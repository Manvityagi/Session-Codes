class Solution {
public:
    vector<TreeNode*> helper(int st, int end)
    {
        vector<TreeNode*> ans;
        if(st > end){
            ans.push_back(nullptr);
            return ans;
        }
        
        for(int idx = st; idx <= end; idx++){
            vector<TreeNode*> leftList = helper(st,idx-1);
            vector<TreeNode*> rightList = helper(idx+1,end);
           
            for(auto left : leftList){
                for(auto right : rightList){
                    TreeNode* root = new TreeNode(idx);
                    root->left = left;
                    root->right = right;
                    ans.push_back(root);
                }
            }
        }
                    return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(!n) return {};
        return helper(1,n);
    }
};