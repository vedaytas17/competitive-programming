/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Given n = 3,

You should return the following matrix:

[
  [ 1, 2, 3 ],
  [ 8, 9, 4 ],
  [ 7, 6, 5 ]
]
*/

vector<vector<int> > Solution::generateMatrix(int A) {
    vector<vector<int> > V;
    V.resize(A);
    for(int i = 0;i < A;i++)V[i] = vector<int>(A);
    
    int num = 1;
    
    int lm = 0,hm = A-1,ln = 0, hn = A-1;
    
    while(num <= A*A){
        
        for(int j = ln;j <= hn;j++)V[lm][j] = num++;
        for(int i = lm+1;i <= hm;i++)V[i][hn] = num++;
        for(int j = hn-1;j >= ln;j--)V[hm][j] = num++; //Additional condition  to handle case when there is only 1 row
        for(int i = hm-1;i > lm;i--)V[i][ln] = num++; //Additional condition to handle case when there is only 1 column
        
        lm++;ln++;hm--;hn--;
    }
    
    return V;
}
