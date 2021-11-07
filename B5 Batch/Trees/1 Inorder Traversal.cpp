//Recursive
class Solution
{
public:
    void helper(TreeNode *root, vector<int> &res)
    {
        if (!root)
            return;

        if (root->left)
            helper(root->left, res);

        res.emplace_back(root->val);

        if (root->right)
            helper(root->right, res);
    }

    vector<int> inorderTraversal(TreeNode *A)
    {
        vector<int> res;
        helper(A, res);
        return res;
    }
};

//Iterative
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (!root)
            return {};

        stack<TreeNode *> st;
        vector<int> ans;
        while (true)
        {
            if (root)
            {
                st.emplace(root);
                root = root->left;
            }
            else
            {
                if (st.empty())
                    break;
                root = st.top();
                st.pop();
                ans.emplace_back(root->val);
                root = root->right;
            }
        }

        return ans;
    }
};
