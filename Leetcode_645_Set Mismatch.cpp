/* 
LEETCODE LINK  : https://leetcode.com/problems/set-mismatch/description/

You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return them in the form of an array.

Example 1:

Input: nums = [1,2,2,4]
Output: [2,3]

Example 2:

Input: nums = [1,1]
Output: [1,2]
*/


class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int sum=nums[0];
        vector<int> ans(2);
        for(int i=1;i<n;i++){
            sum+=nums[i];
            if(nums[i-1]==nums[i]){
                ans[0]=nums[i-1];
            }
        }
        int originalSum=(n*(n+1))/2;
        ans[1]=originalSum-(sum-ans[0]);
        return ans;
    }
};
