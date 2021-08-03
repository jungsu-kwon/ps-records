// https://leetcode.com/problems/sort-an-array

class Solution {
   public:
    vector<int> sortArray(vector<int>& nums) {
        merge_sort(nums, 0, nums.size());
        return nums;
    }

   private:
    static void merge_sort(vector<int>& nums, size_t l, size_t r) {
        assert(l <= r);

        const auto n = r - l;

        if (n < 2) {
            return;
        }

        const auto mid = l + (r - l) / 2;
        assert(mid - l < r - l);
        merge_sort(nums, l, mid);
        assert(r - mid < r - l);
        merge_sort(nums, mid, r);
        merge(nums, l, l + (r - l) / 2, r);
    }

    static void merge(vector<int>& nums, size_t l, size_t m, size_t r) {
        assert(l <= m && m <= r);

        vector<int> sorted(r - l);
        size_t l1 = l;
        size_t l2 = m;
        size_t r1 = m;
        size_t r2 = r;
        size_t ls = 0;
        while (l2 != r2) {
            if (l1 == r1) {
                copy(sorted.cbegin(), sorted.cbegin() + ls, nums.begin() + l);
                return;
            }

            if (nums[l1] < nums[l2]) {
                sorted[ls++] = nums[l1++];
            } else {
                sorted[ls++] = nums[l2++];
            }
        }
        copy(nums.cbegin() + l1, nums.cbegin() + r1, sorted.begin() + ls);
        copy(sorted.cbegin(), sorted.cend(), nums.begin() + l);
    }
};