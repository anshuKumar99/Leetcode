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

class Solution {
public:
    void solve1(string &text1,vector<string> &v1,string output,int i){
        if(i>=text1.size()){
            v1.push_back(output);
            return;
        }
        solve1(text1,v1,output,i+1);
        solve1(text1,v1,output+text1[i],i+1);


    }
     void solve2(string &text2,vector<string> &v2,string output,int i){
        if(i>=text2.size()){
            v2.push_back(output);
            return;
        }
        solve2(text2,v2,output,i+1);
        solve2(text2,v2,output+text2[i],i+1);


    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<string> v1;
        vector<string> v2;
        solve1(text1,v1,"",0);
        solve2(text2,v2,"",0);
        int maxLen=0;
        for(int i=0;i<v1.size();i++){
            for(int j=0;j<v2.size();j++){
                if(v1[i]==v2[j]){
                    int size=v1[i].size();
                    maxLen=max(maxLen,size);
                }
            }
        }
        return maxLen;

        
    }
};


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

