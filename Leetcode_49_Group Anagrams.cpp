/*
LEETCODE LINK : https://leetcode.com/problems/group-anagrams/description/

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Example 2:

Input: strs = [""]
Output: [[""]]

Example 3:

Input: strs = ["a"]
Output: [["a"]]
 
Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.
*/

//Approach 1 : Using sorting
//T.C : O(n*mlog(m)) -> n=input size, m=maximum string length in input vector
//S.C : O(n*m)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        vector<vector<string>> output;
        unordered_map<string,vector<string>> mp;
        for(int i=0;i<n;i++){
            string curr=strs[i];
            sort(curr.begin(),curr.end());
            mp[curr].push_back(strs[i]);
        }
        for(auto i:mp){
            output.push_back(i.second);
        }
        return output;

    }
};

//Approach 2:
//T.C : O(n*m) -> n=input size, m=maximum string length in input vector
//S.C : O(n*m)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        vector<vector<string>> output;
        unordered_map<string,vector<string>> mp;
        for(int i=0;i<n;i++){
            string curr=strs[i];
            int arr[26]={0};
            for(int j=0;j<curr.size();j++){
                arr[curr[j]-'a']++;
            }
            string currSort="";
            for(int k=0;k<26;){
                if(arr[k]>0){
                    currSort+=k+'a';
                    arr[k]--;
                }
                else{
                    k++;
                }
            }
            mp[currSort].push_back(strs[i]);
        }
        for(auto i:mp){
            output.push_back(i.second);
        }
        return output;

    }
};
