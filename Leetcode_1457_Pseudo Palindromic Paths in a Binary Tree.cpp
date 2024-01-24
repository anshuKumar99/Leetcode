/* 
LEETCODE LINK : https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/

Given a binary tree where node values are digits from 1 to 9. A path in the binary tree is said to be pseudo-palindromic if at least one permutation of the node values in the path is a palindrome.
Return the number of pseudo-palindromic paths going from the root node to leaf nodes.

Example 1:
Input: root = [2,3,1,3,1,null,1]
Output: 2 
*/

//Approach 1:Using Vector 
//T.C : O(n)
//S.C : O(1) 

class Solution {
public:
    int odd(const vector<int>& d){
        int c=0;
        for(int i=1;i<10;i++){
            if(d[i]&1){
                c++;
            }
        }
        return c;
    }
    void preorder(TreeNode* root,vector<int>& d,int &count){
        if(root==NULL){
            return;
        }
        d[root->val]++;
        if(root->left==NULL && root->right==NULL){
            int cnt=odd(d);
            if(cnt<=1){
                count++;
            }
            d[root->val]--;
            return;
        }
        preorder(root->left,d,count);
        preorder(root->right,d,count);
        d[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> d(10,0);
        int count=0;
        preorder(root,d,count);
        return count;
    }
};
