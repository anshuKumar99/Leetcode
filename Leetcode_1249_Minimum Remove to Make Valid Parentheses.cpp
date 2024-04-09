/*

LEETCODE LINK : https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/description/

Given a string s of '(' , ')' and lowercase English characters.

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.

Example 1:

Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.

Example 2:

Input: s = "a)b(c)d"
Output: "ab(c)d"

Example 3:

Input: s = "))(("
Output: ""
Explanation: An empty string is also valid.

 
Constraints:

1 <= s.length <= 105
s[i] is either'(' , ')', or lowercase English letter.

*/

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int cntO=0;
        int cntC=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                cntO++;
            }
            else if(s[i]==')' && cntO>0){
                cntO--;
            }
            else if(s[i]==')' && cntO==0){
                s.erase(i,1);
                if(i>=0) i--;
            }
        }

        if(cntO>0){
            for(int i=s.size()-1;i>=0;i--){
                if(s[i]=='(' && cntO>0){
                    s.erase(i,1);
                    cntO--;
                    if(i<=s.size()) i++;
                }
            }
        }

        return s;
    }
};
