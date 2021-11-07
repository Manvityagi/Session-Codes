/*

              n
          /       \
        n          n
       / \
      n   n 
     /
    n
   /
  n


*/
class Solution {
public:
    int dfs(TreeNode* root)
    {
        if(!root) return 0;
        
        int left = dfs(root->left);
        int right = dfs(root->right);
        
        if(left == -1 || right == -1 || abs(left-right) > 1)
                return -1;
        
        return max(left,right)+1;
        
        
    }
    bool isBalanced(TreeNode* root) {
         if(!root) return 1;
        
        return dfs(root) != -1;
    }
    
};