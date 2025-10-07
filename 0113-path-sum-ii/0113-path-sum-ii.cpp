/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root,int k,int &sum,vector<vector<int>> &ans,vector<int>&out){
        if(root==NULL) return ;
        sum+=root->val;
        out.push_back(root->val);
        
        if(root->left==NULL&&root->right==NULL){
            if(sum==k){
                ans.push_back(out);
            }
        } 
     
        solve(root->left,k,sum,ans,out);
        solve(root->right,k,sum,ans,out);
        out.pop_back();
        sum-=root->val;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        vector<int>out;
        int sum=0;
        solve(root,targetSum,sum,ans,out);
        return ans;

    }
};