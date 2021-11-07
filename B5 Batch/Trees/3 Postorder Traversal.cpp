/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    vector<int> v;
    void helper(TreeNode *root)
    {
        if (root == NULL)
            return;

        helper(root->left);

        helper(root->right);
        v.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode *root)
    {
        if (root == NULL)
            return v;
        helper(root);
        return v;
    }
};

//Iterative - 1 stack
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        if (!root)
            return {};
        vector<int> ans;
        stack<TreeNode *> st;
        st.push(root);

        while (!st.empty())
        {
            root = st.top();
            st.pop();
            ans.push_back(root->val);

            if (root->left)
                st.push(root->left);
            if (root->right)
                st.push(root->right);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//Iterative - 2 stacks
/*
In postorder, what we do? If we are at node N, then we 
traverse the left and right child of the node, and after that, 
we push N, right? Here we do the same thing using two stacks s1 and s2.
S1 stores the left and right child, and s2 stores the node. 
When we take the top of s1 and assign it to s2, 
we are basically saying: 
"hey, deal with this node after treating its left and right child" 
cause stack is a lifo structure, so when we push the top of s1 to s2
 and then we push the nodes of children of N to s1, 
 we are doing the same thing as recursion i e. 
 first looking for left and right child, and then looking at the 
 parent node. Also, in s1 , we add in left then right , so that in s2,
  it comes back as right then left and while popping from s2,
it comes back in left then right again, i.e. it retains order. 

*/  