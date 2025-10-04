class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;
        int s=0;
        int e=height.size()-1;
        while(s<e){
            int h1=height[s];
            int h2=height[e];
            int mini=min(h1,h2);    //length
            area=max(area,mini*(e-s));    //e-s=width
            if(mini==h1) s++;    //if(h[s]>h[e]) e--; small height ignore kro
            else if(mini==h2) e--;
            else e--;
        }
        return area;
    }
};

