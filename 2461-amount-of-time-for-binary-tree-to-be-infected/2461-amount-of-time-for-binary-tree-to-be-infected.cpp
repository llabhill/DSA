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
    TreeNode* createmapping(TreeNode* root,unordered_map<TreeNode* ,TreeNode* >&m,int k){
        //if(root==NULL) return NULL;
        queue<TreeNode*>q;
        q.push(root);
        m[root]=NULL;
        TreeNode* res=NULL;
        while(!q.empty()){
            TreeNode * temp=q.front();
            q.pop();
            if(temp->val==k) res=temp;
            if(temp->left){
                m[temp->left]=temp;
                q.push(temp->left);
            }
            if(temp->right){
                m[temp->right]=temp;
                q.push(temp->right);
            }
        }
        return res;
    }
    int solve( TreeNode* root,unordered_map<TreeNode*,TreeNode* >&m){
        int cnt=0;
        map<TreeNode*,bool>visited;
        queue<TreeNode*>q;
        q.push(root);
        visited[root]=true;
       
        while(!q.empty()){
            int size=q.size();
            bool flag=0;
            for(int i=0;i<size;i++){
                TreeNode*temp=q.front();
                q.pop();
                if(temp->left&&!visited[temp->left]){
                    flag=1;
                    visited[temp->left]=true;
                    q.push(temp->left);
                }
                if(temp->right&&!visited[temp->right]){
                    flag=1;
                    visited[temp->right]=true;
                    q.push(temp->right);
                }
                if(m[temp]!=NULL&&!visited[m[temp]]){
                    visited[m[temp]]=true;
                    flag=1;
                    q.push(m[temp]);
                }
            }
            if(flag==1) cnt++;
        }
        return cnt;

    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode* ,TreeNode* >m;
        TreeNode* targetnode=createmapping(root,m,start);
        int ans=solve(targetnode,m);
        return ans;
    }
};