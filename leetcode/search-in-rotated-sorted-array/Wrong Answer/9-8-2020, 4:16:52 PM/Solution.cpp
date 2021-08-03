// https://leetcode.com/problems/search-in-rotated-sorted-array


class Solution {
public:
	int binarySearchPivot(std::vector<int> &nums,int left, int right){
		while (left < right){
			auto mid = left + (right - left ) / 2 ; 
			if (nums[mid] > nums[mid+1]) return mid;
			else if (nums[mid] < nums[left] ) return binarySearchPivot(nums,left,mid-1);
			else return binarySearchPivot(nums,mid+1,right);
		}
		return -1;

	}
	int binarySearch(std::vector<int> &nums,int left, int right, int target){
		while (left <= right){
			auto mid = left + (right - left ) / 2 ; 
			if (nums[mid] == target) return mid;
			else if (nums[mid] < target ) return binarySearch(nums,mid+1,right,target);
			else return binarySearch(nums,left,mid-1,target);
		}
		return -1;
		
	}
    int search(vector<int>& nums, int target) {
		if (nums.size() == 0 )
			return -1;
		if (nums[0] < nums[nums.size()-1])
			return binarySearch(nums,0,nums.size()-1,target);
		auto pivot = binarySearchPivot(nums,0,nums.size()-1);
		if (target  >= nums[0]) return binarySearch(nums,0,pivot,target);
		else return binarySearch(nums,pivot+1,nums.size()-1,target);
		return -1;
        
    }
};