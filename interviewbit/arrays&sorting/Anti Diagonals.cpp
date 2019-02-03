/*
Question
Give a N*N square matrix, return an array of its anti-diagonals. Look at the example for more details.

Example:

		
Input: 	

1 2 3
4 5 6
7 8 9

Return the following :

[ 
  [1],
  [2, 4],
  [3, 5, 7],
  [6, 8],
  [9]
]


Input : 
1 2
3 4

Return the following  : 

[
  [1],
  [2, 3],
  [4]
]


*/

vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    vector < vector<int> > V;
    if(A.size() == 0) return V;
    V.resize(A.size()*2-1);
    for(int i = 0;i < A.size();i++){
        for(int j = 0;j < A.size();j++){
            V[i+j].push_back(A[i][j]);
        }
    }
    return V;
}
