/*

LEETCODE LINK : https://leetcode.com/problems/maximal-rectangle/description/

Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Example 1:

Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.

Example 2:

Input: matrix = [["0"]]
Output: 0

Example 3:

Input: matrix = [["1"]]
Output: 1
 

Constraints:

rows == matrix.length
cols == matrix[i].length
1 <= row, cols <= 200
matrix[i][j] is '0' or '1'.

*/

class Solution {
public:
    vector<int> getNSR(vector<int>& height){
        int n=height.size();
        stack<int> st;

        vector<int> NSR(n);

        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                NSR[i]=n;
            }
            else{
                while(!st.empty() && height[st.top()]>=height[i]){
                    st.pop();
                }
                if(st.empty()){
                    NSR[i]=n;
                }
                else{
                    NSR[i]=st.top();
                }
            }
            st.push(i);
        }
        return NSR;
    }

    vector<int> getNSL(vector<int>& height){
        int n=height.size();
        
        stack<int> st;
        vector<int> NSL(n);

        for(int i=0;i<n;i++){
            if(st.empty()){
                NSL[i]=-1;
            }
            else{
                while(!st.empty() && height[st.top()]>=height[i]){
                    st.pop();
                }
                if(st.empty()){
                    NSL[i]=-1;
                }
                else{
                    NSL[i]=st.top();
                }
            }
            st.push(i);
        }
        return NSL;
    }
    
    int getArea(vector<int>& height){
        int n=height.size();

        vector<int> NSR=getNSR(height);
        vector<int> NSL=getNSL(height);

        vector<int> width(n);

        for(int i=0;i<n;i++){
            width[i]=NSR[i]-NSL[i]-1;
        }

        int area=0;

        for(int i=0;i<n;i++){
            int a=height[i]*width[i];
            area=max(area,a);
        }

        return area;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        vector<int> height(m);

        for(int i=0;i<m;i++){
            height[i]=matrix[0][i]-'0';
        }
        int maxArea=getArea(height);

        for(int row=1;row<n;row++){
            for(int col=0;col<m;col++){
                if(matrix[row][col]=='0'){
                    height[col]=0;
                }
                else{
                    height[col]+=matrix[row][col]-'0';
                }
            }
            maxArea=max(maxArea,getArea(height));
        }

        return maxArea;
        
    }
};
