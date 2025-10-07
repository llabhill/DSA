#include <bits/stdc++.h>
using namespace std;
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
    void solve(TreeNode* root,int steps ,bool goleft,int &ans){
        if(root==NULL) return ;
        ans=max(ans,steps);
        if(goleft==true){
            solve(root->left,steps+1,false,ans);
            solve(root->right,1,true,ans);
        }
        else{
            solve(root->right,steps+1,true,ans);
            solve(root->left,1,false,ans);
        }
    }
    int longestZigZag(TreeNode* root) {
        int ans=0;
        solve(root,0,true,ans);
        solve(root,0,false,ans);
        return ans;
    }
};