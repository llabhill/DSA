class Solution {
public:
    int maxi(vector<vector<int>> mat,int mid,int n){
        int maxelm=INT_MIN;
        int index=0;
        for(int i=0;i<n;i++){
            if(mat[i][mid]>maxelm){
                maxelm=mat[i][mid];
                index=i;
            }
        }
        return index;

    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int s=0;
        int e=m-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            int rowindex=maxi(mat,mid,n);
            int leftelm=mid-1>=0?mat[rowindex][mid-1]:-1;
            int rgtelm=mid+1<m?mat[rowindex][mid+1]:-1;
            if(leftelm<mat[rowindex][mid]&&mat[rowindex][mid]>rgtelm){
                return {rowindex,mid};
            }
            else if(mat[rowindex][mid]<rgtelm){
                s=mid+1;
            }
            else e=mid;
        }
        return{-1,-1};
    }
};