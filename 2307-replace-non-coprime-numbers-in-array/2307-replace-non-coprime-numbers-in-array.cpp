class Solution {
public:
    // int gcd(int n,int m){
    //     while(n!=m){
    //         if(n>m) n-=m;
    //         else m-=n;
    //     }
    //     return n;
    // }
    // int lcm(int a,int b){
    //     int d=a/gcd(a,b);
    //     return d*b;
    // }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> st;
        for(int i=0;i<nums.size();i++){
            while(!st.empty()&&gcd(nums[i],st.back())>1){
                nums[i]=lcm(nums[i],st.back());
                st.pop_back();
                
            }
            st.push_back(nums[i]);
        }
        return st;
    }
};