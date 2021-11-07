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

        v.push_back(root->val);
        helper(root->left);
        helper(root->right);
    }

    vector<int> preorderTraversal(TreeNode *root)
    {

        for (int i = 0; i < v.size(); i++)
            cout << v[i];

        if (root == NULL)
            return v;
        helper(root);
        return v;
    }
};

//Iterative
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        if (!root)
            return {};
        stack<TreeNode *> st;
        st.push(root);
        vector<int> ans;
        while (!st.empty())
        {
            root = st.top();
            st.pop();
            ans.push_back(root->val);

            if (root->right)
                st.push(root->right);
            if (root->left)
                st.push(root->left);
        }

        return ans;
    }
};