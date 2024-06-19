/*

LEETCODE LINK: https://leetcode.com/problems/longest-palindrome/description/

Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.
Letters are case sensitive, for example, "Aa" is not considered a palindrome.

Example 1:

Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.

Example 2:

Input: s = "a"
Output: 1
Explanation: The longest palindrome that can be built is "a", whose length is 1.
 

Constraints:

1 <= s.length <= 2000
s consists of lowercase and/or uppercase English letters only.

*/

class Solution {
public:
    int longestPalindrome(string s) {
        bool hasOdd=0;
        int len=0;
        unordered_map<char,int> mp;
        for(auto i:s){
            mp[i]++;
        }

        for(auto i:mp){
            if(i.second%2==0){
                len+=i.second;
            }
            else{
                len+=i.second-1;
                hasOdd=1;
            }

        }
        return len+hasOdd;
    }
};
