/*

LEETCODE LINK: https://leetcode.com/problems/sort-colors/description/

Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.


Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
 

Constraints:

n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.

Follow up: Could you come up with a one-pass algorithm using only constant extra space?

*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();

        int cntRed=0,cntWhite=0,cntBlue=0;

        for(int i=0;i<n;i++){
            if(nums[i]==0){
                cntRed++;
            }
            else if(nums[i]==1){
                cntWhite++;
            }
            else{
                cntBlue++;
            }
        }
        int j=0;
        while(cntRed!=0){
            nums[j]=0;
            j++;
            cntRed--;
        }
        while(cntWhite!=0){
            nums[j]=1;
            j++;
            cntWhite--;
        }
        while(cntBlue!=0){
            nums[j]=2;
            j++;
            cntBlue--;
        }
    }
};
