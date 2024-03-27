/*

LEETCODE LINK : https://leetcode.com/problems/find-the-duplicate-number/description/

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.


Example 1:

Input: nums = [1,3,4,2,2]
Output: 2

Example 2:

Input: nums = [3,1,3,4,2]
Output: 3

Example 3:

Input: nums = [3,3,3,3,3]
Output: 3
 

Constraints:

1 <= n <= 105
nums.length == n + 1
1 <= nums[i] <= n
All the integers in nums appear only once except for precisely one integer which appears two or more times.

*/

// Using Map
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n=nums.size();

        unordered_map<int,int> mp;

        for(auto i:nums){
            if(mp[i]==1){
                return i;
            }
            mp[i]++;
        }

        return -1;
    }
};


// Using Sorting
// Time Complexity: O(n*logn)
// Space Complexity: O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {     
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                return nums[i];
            }
        }
        return -1;
    }
};
