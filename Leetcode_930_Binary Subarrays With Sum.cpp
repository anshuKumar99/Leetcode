/*

LEETCODE LINK : https://leetcode.com/problems/binary-subarrays-with-sum/description/

Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.

Example 1:

Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]

Example 2:

Input: nums = [0,0,0,0,0], goal = 0
Output: 15
 

Constraints:

1 <= nums.length <= 3 * 104
nums[i] is either 0 or 1.
0 <= goal <= nums.length

*/

//BRUTE FORCE

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int currSum=0;
            for(int j=i;j<n;j++){
                currSum+=nums[j];
                if(currSum==goal){
                    ans++;
                }
            }
        }
        return ans;
    }
};

//OPTIMIZED SOLUTION

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        int ans=0;
        int windowSum=0;
        int i=0,j=0;
        int zerosCount=0;
        while(j<n){
            windowSum += nums[j];

            while(i<j && (nums[i]==0 || windowSum > goal)){
                if(nums[i]==0)
                    zerosCount++;
                else 
                    zerosCount=0;
                
                windowSum -= nums[i];
                i++;
            }
            if(windowSum==goal)
                ans+= 1 + zerosCount;

            j++;
        }
        return ans;
    }
};

