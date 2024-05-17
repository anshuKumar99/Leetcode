/*

LEETCODE LINK: https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/description/

You are given the head of a non-empty linked list representing a non-negative integer without leading zeroes.

Return the head of the linked list after doubling it.

Example 1:

Input: head = [1,8,9]
Output: [3,7,8]
Explanation: The figure above corresponds to the given linked list which represents the number 189. Hence, the returned linked list represents the number 189 * 2 = 378.

Example 2:

Input: head = [9,9,9]
Output: [1,9,9,8]
Explanation: The figure above corresponds to the given linked list which represents the number 999. Hence, the returned linked list reprersents the number 999 * 2 = 1998. 
 
Constraints:

The number of nodes in the list is in the range [1, 104]
0 <= Node.val <= 9
The input is generated such that the list represents a number that does not have leading zeros, except the number 0 itself.

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
class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* curr=head;
        ListNode* prev=NULL;

        while(curr!=NULL){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }

        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
      
        head=reverse(head);

        ListNode* curr=head;
        ListNode* prev=NULL;

        int carry=0;

        while(curr!=NULL){
            int newVal=(curr->val)*2+carry;

            curr->val=newVal%10;

            if(newVal>=10){
                carry=1;
            }
            else{
                carry=0;
            }

            prev=curr;
            curr=curr->next;
        }

        if(carry!=0){
            ListNode* temp=new ListNode(carry);
            prev->next=temp;
        }
        
        return reverse(head);
    }
};
