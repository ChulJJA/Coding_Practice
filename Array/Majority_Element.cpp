#include <vector>

using namespace std;

/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You
may assume that the majority element always exists in the array.



Example 1:

Input: nums = [3,2,3]
Output: 3

Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2


Constraints:

n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109
*/

class MySolution {
   public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int curr = nums[i];
            for (int j = 0; j < nums.size(); ++j) {
                if (curr == nums[j]) {
                    ++count;
                }

                if (count > nums.size() / 2) {
                    return nums[i];
                }
            }
            count = 0;
        }
        return count;
    }
};

class BetterSolution {
   public:
    int majorityElement(vector<int>& nums) {
        int freq = 0, ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (freq == 0) {
                ans = nums[i];
            }
            if (ans == nums[i]) {
                freq++;
            } else {
                freq--;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums1 = {3, 2, 3};
    vector<int> nums2 = {2, 2, 1, 1, 1, 2, 2};

    BetterSolution my_sol;
    my_sol.majorityElement(nums2);

    return 0;
}