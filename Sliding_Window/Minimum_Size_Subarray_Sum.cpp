/*
Given an array of positive integers nums and a positive integer target,
return the minimal length of a subarray whose sum is greater than or
equal to target. If there is no such subarray, return 0 instead.


Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem
constraint. Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0


Constraints:

1 <= target <= 109
1 <= nums.length <= 105
1 <= nums[i] <= 104
*/

#include <vector>

using namespace std;

class MySolution {
   public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min_length = 1024;
        for (int i = 0; i < nums.size(); ++i) {
            int curr_sum = 0;

            for (int j = i; j < nums.size(); ++j) {
                curr_sum += nums[j];
                if (curr_sum >= target) {
                    min_length = min(min_length, j - i + 1);
                    break;
                }
            }
        }
        return min_length == 1024 ? 0 : min_length;
    }
};

class BetterSolution {
   public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = 1024;
        int sum = 0;
        int start = 0, end = 0;
        int n = nums.size();
        while (end < n) {
            sum += nums[end];
            while (sum >= target) {
                result = min(result, end - start + 1);
                sum -= nums[start];
                start++;
            }
            end++;
        }
        if (result == 1024) return 0;
        return result;
    }
};

int main() {
    vector<int> nums1 = {2, 3, 1, 2, 4, 3};
    vector<int> nums2 = {1, 4, 4};
    vector<int> nums3 = {1, 1, 1, 1, 1, 1, 1, 1};

    MySolution my_sol;
    my_sol.minSubArrayLen(11, nums3);

    return 0;
}