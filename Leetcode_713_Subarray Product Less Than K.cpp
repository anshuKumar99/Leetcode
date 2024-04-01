/*

LEETCODE LINK : https://leetcode.com/problems/subarray-product-less-than-k/description/

Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.

Example 1:

Input: nums = [10,5,2,6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are:
[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.

Example 2:

Input: nums = [1,2,3], k = 0
Output: 0
 

Constraints:

1 <= nums.length <= 3 * 104
1 <= nums[i] <= 1000
0 <= k <= 106


*/

// Sliding window
// T.C : O(n)
// S.C : O(1)

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1){
            return 0;
        }

        int n=nums.size();
        int cnt=0,i=0,j=0;

        int product=1;

        while(j<n){
            product*=nums[j];

            while(i<n && product>=k){
                product/=nums[i];
                i++;
            }

            cnt+=j-i+1;

            j++;
        }

        return cnt;
    }
};


//Brute force
// T.C : O(n*n)
// S.C : O(1)

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            int product=1;
            for(int j=i;j<n;j++){
                product*=nums[j];
                if(product<k){
                    cnt++;
                }
                else{
                    break;
                }
            }
        }
        return cnt;
    }
};
