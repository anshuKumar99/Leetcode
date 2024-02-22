/*
LEETCODE LINK : https://leetcode.com/problems/bitwise-and-of-numbers-range/description/

Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.

Example 1:

Input: left = 5, right = 7
Output: 4

Example 2:

Input: left = 0, right = 0
Output: 0

Example 3:

Input: left = 1, right = 2147483647
Output: 0
 
Constraints:

0 <= left <= right <= 231 - 1

*/

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        if(left==0){
            return 0;
        }
        if (__builtin_clz(left)!=__builtin_clz(right)){
            return 0;//left & right don't have same bit length
        }
        while(right>left){
            right&=(right-1);
        }
        return right;
    }
};
