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
    pair<bool,int> balanced(TreeNode* root){
        if(root==NULL) return {true,0};
        pair<bool,int> left=balanced(root->left);
        pair<bool,int> rgt=balanced(root->right);
        bool leftans=left.first;
        bool rgtans=rgt.first;
        int h1=left.second;
        int h2=rgt.second;
        bool diff=abs(h1-h2)<=1;
        pair<bool,int> ans;
        ans.second=max(h1,h2)+1;
        if(leftans&&rgtans&&diff) ans.first=true;
        else ans.first=false;
        return ans;

    }
    bool isBalanced(TreeNode* root) {
       return balanced(root).first;
    }
};