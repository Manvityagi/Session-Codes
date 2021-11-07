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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        return create(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }

    TreeNode *create(vector<int> &inorder, vector<int> &postorder, int is, int ie, int ps, int pe)
    {
        if (ps > pe)
        {
            return nullptr;
        }
        TreeNode *node = new TreeNode(postorder[pe]);
        int pos;
        for (int i = is; i <= ie; i++)
        {
            if (inorder[i] == node->val)
            {
                pos = i;
                break;
            }
        }
        //pos - is = nodes in left tree
        node->left = create(inorder, postorder, is, pos - 1, ps, pos - is + ps - 1);
        node->right = create(inorder, postorder, pos + 1, ie, pos - is + ps, pe - 1);
        return node;
    }
};