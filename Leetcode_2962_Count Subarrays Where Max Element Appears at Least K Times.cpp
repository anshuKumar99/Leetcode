/*

LEETCODE LINK : https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/

You are given an integer array nums and a positive integer k.

Return the number of subarrays where the maximum element of nums appears at least k times in that subarray.

A subarray is a contiguous sequence of elements within an array.

Example 1:

Input: nums = [1,3,2,3,3], k = 2
Output: 6
Explanation: The subarrays that contain the element 3 at least 2 times are: [1,3,2,3], [1,3,2,3,3], [3,2,3], [3,2,3,3], [2,3,3] and [3,3].

Example 2:

Input: nums = [1,4,2,1], k = 3
Output: 0
Explanation: No subarray contains the element 4 at least 3 times.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 106
1 <= k <= 105

*/

// Using Sliding Window
// T.C : O(n)
// S.C : O(1)

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=INT_MIN;

        for(int l=0;l<n;l++){
            maxi=max(maxi,nums[l]);
        }

        long long int i=0,j=0,cnt=0,ans=0;

        while(j<n){
            if(nums[j]==maxi){
                cnt++;
            }
            while(i<n && cnt>=k){
                if(nums[i]==maxi){
                    cnt--;
                }
                i++;
                ans+=n-j; //very imp because n-j is total subarray containing max element atleast k times when end is j
            }

            j++;
        } 
        return ans;
        
    }
};
