/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    queue<TreeNode*> q;       
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        
        vector<vector<int>> ans;
        vector<int> cur_vec;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty()){
        TreeNode* top = q.front();
        q.pop();
            if(top == NULL)
            {
                ans.push_back(cur_vec);
                cur_vec.resize(0);
                if (q.size() > 0) q.push(NULL);
            }
            else
            {
               if(top->left!=NULL) q.push(top->left);
               if(top->right!=NULL) q.push(top->right);
               cur_vec.push_back(top->val);
            }
            
        }
        
        return ans;
    }
};