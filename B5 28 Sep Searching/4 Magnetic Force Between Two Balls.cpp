class Solution
{
public:
    bool isPossible(vector<int> &pos, int curr_gap, int total_balls)
    {

        int i = 0, n = pos.size();
        int prev_ball_pos = pos[0];
        total_balls--;

        //placing the current ball on pos[i]
        while (i < n && total_balls > 0)
        {
            if (pos[i] - prev_ball_pos >= curr_gap)
            {
                prev_ball_pos = pos[i];
                total_balls--;
            }
            i++;
        }

        if (total_balls == 0)
            return true;
        return false;
    }

    int maxDistance(vector<int> &pos, int m)
    {
        int n = pos.size();
        sort(pos.begin(), pos.end());

        int lo = 0, hi = pos[n - 1] - pos[0]; //10^9

        int ans = 0;

        while (lo <= hi)
        {
            int mid_force = (lo + hi) >> 1;
            if (isPossible(pos, mid_force, m))
            {
                ans = max(ans, mid_force);
                lo = mid_force + 1; //F = 3, we will try to find for F = 4
            }
            else
            {
                hi = mid_force - 1;
            }
        }
        return ans;
    }
};