/*

Conditions - 
1. w1 > w2 and l1 > l2 
2. Multiple instances of 1 box allowed

    1 box can generate 2 more boxes by rotating 
    180 rotation wont generate a new box

    Rotate so that height changes

    1. Base = w*l, Height = h
    2. Base = l*h, Height = w
    3. Base = w*h, Height = l


Example - Box arr[] = { {4, 6, 7}, {4, 5, 6}, {10, 12, 32} };

1. Produce all instances of boxes
2. The lowest box must have largest base area and topmost box must have smallest area
    - Sort according to base area
    - We will still have invalid boxes as B1 < B2 doesnt means w1<w2 and l1<l2


l  w  h
10 12 32
32 12 10
10 32 12
 4  5  6
 5  6  4
 4  6  5
 4  7  6
 7  6  4
 4  6  7


Why max, min is required? So as to compare the bigger dimension of 1 box to
bigger dimension of other box.

   h  w  l
B1 10 12 15
B2 8  13  7

Better B2 = 8 7 13


L[i] = maximum possible height when ith box is on top
L[i] = height[i] + max(L[j], j = 0 to i-1) | block i on top of block j 

*/

struct Box
{
    int length, width, height;
};

vector<Box> createAllRotations(vector<Box> &boxes)
{
    vector<Box> rotations;

    for (auto box : boxes)
    {
        //original configuration - L * W * H
        rotations.push_back(box);

        // first rotation: max(L, H) × min(L, H) × W
        rotations.push_back({max(box.length, box.height),
                             min(box.length, box.height),
                             box.width});

        // second rotation: max(W, H) × min(W, H) × L
        rotations.push_back({max(box.width, box.height),
                             min(box.width, box.height),
                             box.length});
    }

    return rotations;
}

bool comp(const Box &b1, const Box &b2){
    return (b1.length * b1.width) > (b2.length * b2.width);
}

int maxBoxStackHeight(vector<Box> boxes){
    vector<Box> rotations = createAllRotations(boxes);

    sort(rotations.begin(),rotations.end(),comp); //decreasing order of area

    int n = rotations.size(), ans = 0;
    vector<int> dp(n);

    for(int i = 0; i < n; i++){
        for(int j = i-1; j >= 0; j--){
            if(rotations[j].length > rotations[i].length &&
               rotations[j].width > rotations[i].width ){
                   dp[i] = max(dp[i],dp[j] + rotations[i].height);
               }
        }
        ans = max(ans,dp[i]);
    }
    return ans;
}

