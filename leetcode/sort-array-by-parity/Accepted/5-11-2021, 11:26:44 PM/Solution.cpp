// https://leetcode.com/problems/sort-array-by-parity

#include <vector>
using namespace std;

class Solution {
private:
    bool is_even(int num)
    {
        return num % 2 == 0;
    }
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int num_even = 0;
        int n = A.size();

        for (auto num : A){
            if (is_even(num))
                num_even += 1;
        }

        int even_ind = 0;
        int odd_ind = num_even;

        while (odd_ind != A.size() && even_ind != num_even)
        {
            while (odd_ind != A.size() && !is_even(A[odd_ind]))
                odd_ind++;

            while (even_ind != num_even && is_even(A[even_ind]))
                even_ind++;
            
            if (even_ind == num_even || odd_ind == A.size())
                break;
            swap(A[odd_ind],A[even_ind]);
        }

        return A;




        
    }
};