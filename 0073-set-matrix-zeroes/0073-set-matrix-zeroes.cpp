class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        bool checkrow=false;
        bool checkcol=false;
        //checking for 1st row;
        for(int i=0;i<m;i++){
            if(matrix[0][i]==0){
                checkrow=true;
                break;
            }
        }
        //checking for 1st col;
        for(int i=0;i<n;i++){
            if(matrix[i][0]==0){
                checkcol=true;
                break;
            }
        }
        //markingh other columns and rows;
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][0]==0||matrix[0][j]==0){
                    matrix[i][j]=0;   
                }
            }
        }
        if(checkrow){
            for(int i=0;i<m;i++){
                matrix[0][i]=0;
            }
        }
        if(checkcol){
            for(int i=0;i<n;i++){
                matrix[i][0]=0;
            }
        }
    }
};