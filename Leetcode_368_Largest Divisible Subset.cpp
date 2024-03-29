/*

LEETCODE LINK : https://leetcode.com/problems/largest-divisible-subset/description/

Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:
answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.

Example 1:

Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.

Example 2:

Input: nums = [1,2,4,8]
Output: [1,2,4,8]

Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 2 * 109
All the integers in nums are unique.

*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
      int n = nums.size();
      sort(nums.begin(), nums.end());
      vector<int> dp(n, 1);
  		int maxAmount = 1;
  		int maxVal = dp[0];
  		for (int i = 0; i < n; i++)
  		{
  			for (int j = 0; j < i; j++)
  			{
  				if (nums[i] % nums[j] == 0)
  				{
  					dp[i] = max(dp[i], dp[j] + 1);
  				}
  			}
  			if (dp[i] > maxAmount)
  			{
  				maxAmount = dp[i];
  				maxVal = nums[i];
  			}
  		}
  		vector<int> result;
  		if (maxAmount == 1)
  		{
  			result.push_back(nums[0]);
  		}
  		else
  		{
  			for (int i = n - 1; i >= 0; i--)
  			{
  				if (maxAmount == 0) break;
  				if (dp[i] == maxAmount && maxVal % nums[i] == 0)
  				{
  					result.push_back(nums[i]);
  					maxAmount--;
  					maxVal = nums[i];
  				}
  			}
  		}
  		return result;
    }
};
