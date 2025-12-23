class Solution {
private: 
    void solve(TreeNode* root , int &ans ){
        if(!root) return ;
        if(root->left && !root->left->left && !root->left->right){
            ans += root->left-> val;
        }
        
        solve(root->left , ans); 
        solve(root->right , ans);
        return;
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root || (!root->left && !root->right) ) return 0;
        int ans = 0 ; 
        solve(root,ans);
        return ans ;
    }
};
