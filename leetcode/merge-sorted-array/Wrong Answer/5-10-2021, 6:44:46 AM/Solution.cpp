// https://leetcode.com/problems/merge-sorted-array

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        auto left = m - 1, right = n - 1;
        auto to_put = nums1.size() - 1;


        while (right != -1 && left != -1)
        {
            if (nums1[left] > nums2[right])
            {
                nums1[to_put] = nums1[left];
                left -= 1;
            }
            else{
                nums1[to_put] = nums2[right];
                right -= 1;
            }
            to_put -= 1;
        }
        if (left == -1){
            nums1.insert(nums1.begin(),nums2.begin(),nums2.begin()+right);
        }

        
    }
};