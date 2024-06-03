/*

LEETCODE LINK: https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/description/

You are given an array nums of non-negative integers. nums is considered special if there exists a number x such that there are exactly x numbers in nums that are greater than or equal to x.

Notice that x does not have to be an element in nums.

Return x if the array is special, otherwise, return -1. It can be proven that if nums is special, the value for x is unique.


Example 1:

Input: nums = [3,5]
Output: 2
Explanation: There are 2 values (3 and 5) that are greater than or equal to 2.

Example 2:

Input: nums = [0,0]
Output: -1
Explanation: No numbers fit the criteria for x.
If x = 0, there should be 0 numbers >= x, but there are 2.
If x = 1, there should be 1 number >= x, but there are 0.
If x = 2, there should be 2 numbers >= x, but there are 0.
x cannot be greater since there are only 2 numbers in nums.

Example 3:

Input: nums = [0,4,3,0,4]
Output: 3
Explanation: There are 3 values that are greater than or equal to 3.
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 1000


*/

// Approach-1 (Brute Force)
// T.C : O(n*n)
// S.C : O(1)

class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n=nums.size();

        for(int i=0;i<=n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(nums[j]>=i){
                    cnt++;
                }
            }
            if(cnt==i){
                return cnt;
            }
        }
        return -1;
    }
};


// Approach-2 (Using binary search)
// T.C : O(n*logn)
// S.C : O(1)

class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n=nums.size();

        sort(nums.begin(),nums.end());

        for(int x=0;x<=n;x++){
            int idx=lower_bound(begin(nums),end(nums),x)-begin(nums);
            int cnt=n-idx;
            if(cnt==x){
                return x;
            }
        }
        return -1;
    }
};


// Approach-3 (Binary search on answer)
// T.C : O(n*logn)
// S.C : O(1)

class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n=nums.size();

        sort(nums.begin(),nums.end());

        int l=0,r=n;

        while(l<=r){
            int mid=l+(r-l)/2;
            int idx=lower_bound(begin(nums),end(nums),mid)-begin(nums);
            int cnt=n-idx;
            if(cnt==mid){
                return cnt;
            }
            else if(cnt>mid){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return -1;
    }
};

// Approach-4 (Using counting Sort + Prefix Sum)
// T.C : O(n)
// S.C : O(n)

class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n=nums.size();

        vector<int> freq(n+1);

        for(int i=0;i<n;i++){
            int num=nums[i];
            freq[min(n,num)]++;
        }

        int cumSum=0;
        for(int x=n;x>=0;x--){
            cumSum+=freq[x];
            if(cumSum==x){
                return x;
            }
        }
        return -1;
    }
};
