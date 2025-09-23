#include<bits/stdc++.h>
class Solution {
public:
    vector<string>gettoken(string z){
        stringstream ss(z);
        string token="";
        vector<string> ans;
        while(getline(ss,token,'.')){
            ans.push_back(token);
        }
        return ans;


    } 
    int compareVersion(string version1, string version2) {
        vector<string>s1,s2;
        s1=gettoken(version1);
        s2=gettoken(version2);
        int n=s1.size();
        int m=s2.size();
        int i=0,j=0;
        while(i<n||j<m){
            int a= i<n?stoi(s1[i]):0;
            int b= j<m?stoi(s2[j]):0;
            if(a<b) return -1;
            else if(a>b) return 1;
            else{
                i++;j++;
            } 
        }
        return 0;
    }
};