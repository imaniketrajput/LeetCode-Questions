class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int l = 0;
        int r = n -1;
        int maxi = INT_MIN;
        int area;

        while(l<r)
        {
            int width = r - l;
            int h = min(height[l], height[r]);
            area = h * width;
            maxi = max(maxi, area);
            
            if(height[l] <= height[r])
            {  
                l++;
            }
            else{
                r--;
            }
        }

        return maxi;
    }
};