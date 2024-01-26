/* 
LEETCODE LINK  : https://leetcode.com/problems/longest-common-subsequence/description/

Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0. A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

Example 1:
Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.

Example 2:
Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
*/

//One approach can be brute force approach one in which we will find all subsequences of both the strings and then we can find longest common subsequence.

//Optimized Approach

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length();
        int m=text2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i=n-1;i>=0;i--){
            for (int j=m-1;j>=0;j--){
                char c1=text1[i];
                char c2=text2[j];
                if(c1 == c2){
                    dp[i][j]=1+dp[i+1][j+1];
                } 
                else {
                    dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
        
    }
};

