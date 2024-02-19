/*

LEETCODE LINK : https://leetcode.com/problems/power-of-two/description/

Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x.

Example 1:

Input: n = 1
Output: true
Explanation: 20 = 1

Example 2:

Input: n = 16
Output: true
Explanation: 24 = 16

Example 3:

Input: n = 3
Output: false
 

Constraints:

-231 <= n <= 231 - 1

*/

//Approach 1 : Remainder-divident method

class Solution {
public:
    Remainder-divident method
    bool isPowerOfTwo(int n) {
        if(n<1){
            return 0;
        }
        while(n!=1){
            int rem=n%2;
            if(rem!=0){
                return 0;
            }
            n/=2;
        }
        return 1;  
    }
};


//Approach 2 : Bit manipulation method
// bit representation of 7  -> 0111
// bit representation of 8  -> 1000
// bitwise AND of 7 and 8 -> 0000
// We will use this property for all numbers which are powers of two

class Solution {
public:
    bool isPowerOfTwo(int n){
        if(n<1){
            return 0;
        }
        return ((n&(n-1))==0);
    }
};
