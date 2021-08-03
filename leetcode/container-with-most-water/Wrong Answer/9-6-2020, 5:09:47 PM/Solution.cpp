// https://leetcode.com/problems/container-with-most-water

class Solution {
private : 
    int searchNext(std::vector<int> &height,int startInd,bool fromLeft){
        int nextInd = 0 ;
        if (fromLeft){
            auto itFound = std::upper_bound(height.begin() + startInd,height.end(),height[startInd]);
            if (itFound == height.end()){
                return -1;
            }
            nextInd = itFound - height.begin();
        }
        else{
            auto itFound = height.rbegin() + height.size() -1 - startInd;
            for (;itFound != height.rend(); ++itFound ){
                if (*itFound > height[startInd])
                    break;
            }
            if (itFound == height.rend())
                return -1;
            nextInd = height.size() - 1 - (itFound - height.rbegin());
        }
        return nextInd ;

    }
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0 ;
        int l = 0, r = height.size()-1;
        int maxVolume =(r-l) * std::min(height[r],height[l]);
        while (l < r){
            if (height[l] < height[r])
            {
                l = searchNext(height,l,true);
                if (l == -1)
                    break;
                else 
                    maxVolume = std::max(maxVolume,(r-l) * std::min(height[r],height[l]));
            }
            else
            {
                r = searchNext(height,r,false);
                if (r == -1)
                    break;
                else
                    maxVolume = std::max(maxVolume,(r-l) * std::min(height[r],height[l]));
            }
        }
        return maxVolume;
    }
};