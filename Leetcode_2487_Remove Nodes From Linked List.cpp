/*

LEETCODE LINK: https://leetcode.com/problems/remove-nodes-from-linked-list/description/

You are given the head of a linked list.

Remove every node which has a node with a greater value anywhere to the right side of it.

Return the head of the modified linked list.

Example 1:

Input: head = [5,2,13,3,8]
Output: [13,8]
Explanation: The nodes that should be removed are 5, 2 and 3.
- Node 13 is to the right of node 5.
- Node 13 is to the right of node 2.
- Node 8 is to the right of node 3.

Example 2:

Input: head = [1,1,1,1]
Output: [1,1,1,1]
Explanation: Every node has value 1, so no nodes are removed.

 
Constraints:

The number of the nodes in the given list is in the range [1, 105].
1 <= Node.val <= 105

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
    ListNode* removeNodes(ListNode* head) {
        ListNode* curr=head;

        vector<int> ans;
        vector<int> v;

        while(curr!=NULL){
            v.push_back(curr->val);
            curr=curr->next;
        }

        int n=v.size();

        vector<int> right(n);


        right[n-1]=v[n-1];

        for(int i=n-2;i>=0;i--){
            right[i]=max(right[i+1],v[i]);
        }

        for(int i=0;i<n;i++){
            if(right[i]<=v[i]){
                ans.push_back(v[i]);
            }
        }

        curr=head;
        int j=0;


        while(j<ans.size()){
            curr->val=ans[j];
            if(j==ans.size()-1){
                curr->next=NULL;
                break;
            }
            curr=curr->next;
            j++;
        }
        return head;
    }
};
