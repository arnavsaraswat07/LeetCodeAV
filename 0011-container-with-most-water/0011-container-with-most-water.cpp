class Solution {
public:
    int maxArea(vector<int>& height) {
        //traverse from left and right both
        //take the min of left and right and compute the area min*(r-l+1);
        //lets do this

        int l=0;
        int n=height.size();
        int r=n-1;
        int mini=INT_MAX;
        int maxarea=INT_MIN;
        while(l<r){
            mini=min(height[l],height[r]);
            maxarea=max(maxarea,mini*(r-l));
            if(height[l]>height[r]){
                r--;
            }
            else{
                l++;
            }


        }
        return maxarea;
        
    }
};