/*

LEETCODE LINK : https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/description/

Given a matrix and a target, return the number of non-empty submatrices that sum to target.

A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 <= x <= x2 and y1 <= y <= y2.

Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different if they have some coordinate that is different: for example, if x1 != x1'.


Example 1:

Input: matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
Output: 4
Explanation: The four 1x1 submatrices that only contain 0.
  
Example 2:

Input: matrix = [[1,-1],[-1,1]], target = 0
Output: 5
Explanation: The two 1x2 submatrices, plus the two 2x1 submatrices, plus the 2x2 submatrix.
  
Example 3:

Input: matrix = [[904]], target = 0
Output: 0

*/

//Brute Force Approach -> Gives T.L.E

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int cnt=0;
        for(int sr=0;sr<n;sr++){
            for(int sc=0;sc<m;sc++){
                for(int er=sr;er<n;er++){
                    for(int ec=sc;ec<m;ec++){
                        int sum=0;
                        for(int i=sr;i<=er;i++){
                            for(int j=sc;j<=ec;j++){
                                sum+=matrix[i][j];
                            }
                        }
                        if(sum==target){
                            cnt++;
                        }
                    }
                }
            }
        }

        return cnt;
    }
};

// Optimized Approach

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int cnt=0;

        //row commulative sum row-wise
        for(int r=0;r<n;r++){
            for(int c=1;c<m;c++){
                matrix[r][c]+=matrix[r][c-1];
            }
        }
      
        //Find the "No. of subarrays with sum k" in downward direction
        //leetcode->560 
        for(int startCol=0;startCol<m;startCol++){
            for(int j=startCol;j<m;j++){
                unordered_map<int,int> mp;
                mp.insert({0,1});
                int cumSum=0;
                for(int i=0;i<n;i++){
                    if(startCol>0){
                        cumSum+=matrix[i][j]-matrix[i][startCol-1];
                    }
                    else{
                        cumSum+=matrix[i][j];
                    }
                    if(mp.find(cumSum-target)!=mp.end()){
                        cnt+=mp[cumSum-target];
                    }
                    mp[cumSum]++;
                }
            }
        }

        return cnt;
    }
};
