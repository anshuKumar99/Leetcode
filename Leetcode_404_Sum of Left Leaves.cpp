/*

LEETCODE LINK : https://leetcode.com/problems/sum-of-left-leaves/description/

Given the root of a binary tree, return the sum of all left leaves.

A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: 24
Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.

Example 2:

Input: root = [1]
Output: 0 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
-1000 <= Node.val <= 1000

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
       stack<pair<TreeNode*,bool>> st;
        int ans=0;
        st.push({root,false});

        while(!st.empty()){
            TreeNode* temp=st.top().first;
            bool isLeft=st.top().second;
            st.pop();

            if(isLeft && temp->left==NULL && temp->right==NULL){
                ans+=temp->val;
            }
            if(temp->left!=NULL){
                st.push({temp->left,true});
            }
            if(temp->right!=NULL){
                st.push({temp->right,false});
            }
        }

        return ans;
        
    }
};
