/*

LEETCODE LINK : https://leetcode.com/problems/palindrome-linked-list/description/

Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

Example 1:

Input: head = [1,2,2,1]
Output: true

Example 2:

Input: head = [1,2]
Output: false
 
Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// Using Stack

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        ListNode* curr=head;
        while(curr!=NULL){
            st.push(curr->val);
            curr=curr->next;
        }
        curr=head;
        while(curr!=NULL && !st.empty()){
            if(st.top()!=curr->val){
                return false;
            }
            st.pop();
            curr=curr->next;
        }
        return true;
        
    }
};


//Using Vector

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> vec;
        while(head!=NULL){
            int data=head->val;
            vec.push_back(data);
            head=head->next;
        }
        int i=0;
        int j=vec.size()-1;
        while(i<j){
            if(vec[i]!=vec[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
        
    }
};
