/*

LEETCODE LINK : https://leetcode.com/problems/number-of-wonderful-substrings/description/

A wonderful string is a string where at most one letter appears an odd number of times.

For example, "ccjjc" and "abab" are wonderful, but "ab" is not.
Given a string word that consists of the first ten lowercase English letters ('a' through 'j'), return the number of wonderful non-empty substrings in word. If the same substring appears multiple times in word, then count each occurrence separately.

A substring is a contiguous sequence of characters in a string.

Example 1:

Input: word = "aba"
Output: 4
Explanation: The four wonderful substrings are underlined below:
- "aba" -> "a"
- "aba" -> "b"
- "aba" -> "a"
- "aba" -> "aba"

Example 2:

Input: word = "aabb"
Output: 9
Explanation: The nine wonderful substrings are underlined below:
- "aabb" -> "a"
- "aabb" -> "aa"
- "aabb" -> "aab"
- "aabb" -> "aabb"
- "aabb" -> "a"
- "aabb" -> "abb"
- "aabb" -> "b"
- "aabb" -> "bb"
- "aabb" -> "b"

Example 3:

Input: word = "he"
Output: 2
Explanation: The two wonderful substrings are underlined below:
- "he" -> "h"
- "he" -> "e"
 

Constraints:

1 <= word.length <= 105
word consists of lowercase English letters from 'a' to 'j'.

*/

// Using Bit Manipulation

class Solution {
public:
    typedef long long ll;
    long long wonderfulSubstrings(string word) {
        unordered_map<ll,ll> mp;
        mp[0]=1;
        int cum_xor=0;
        ll result=0;

        for(auto &ch:word){
            int shift=ch-'a';
            cum_xor^=(1<<shift);
            result+=mp[cum_xor];

            for(char start='a';start<='j';start++){
                shift=start-'a';
                ll temp_xor=cum_xor^(1<<shift);
                result+=mp[temp_xor];
            }

            mp[cum_xor]++;
        }

        return result;
        
    }
};
