class Solution {
public:
    vector<int> getleftmax(vector<int> arr){
        vector<int>left(arr.size());
        left[0]=arr[0];
        for(int i=1;i<arr.size();i++){
            left[i]=max(left[i-1],arr[i]);
        }
        return left;
    }
    vector<int> getrgtmax(vector<int> arr){
        vector<int>rgt(arr.size());
        rgt[arr.size()-1]=arr[arr.size()-1];
        for(int i=arr.size()-2;i>=0;i--){
            rgt[i]=max(rgt[i+1],arr[i]);
        }
        return rgt;
    }
    int trap(vector<int>& height) {
        vector<int>leftmax=getleftmax(height);
        vector<int>rgtmax=getrgtmax(height);
        int sum=0;
        for(int i=0;i<height.size();i++){
            int h=min(leftmax[i],rgtmax[i])-height[i];
            sum+=h;
        }
        return sum;
    }
};