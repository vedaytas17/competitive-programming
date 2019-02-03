/*
Question
Given a matrix of m * n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example:

Given the following matrix:

[
    [ 1, 2, 3 ],
    [ 4, 5, 6 ],
    [ 7, 8, 9 ]
]
You should return

[1, 2, 3, 6, 9, 8, 7, 4, 5]
*/

vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    vector<int> X;
    int m = A.size();
    int n = A[0].size();
    int lm = 0,hm = m-1,ln = 0, hn = n-1;
    
    while(lm <=hm && ln <= hn){
        
        for(int j = ln;j <= hn;j++)X.push_back(A[lm][j]);
        for(int i = lm+1;i <= hm;i++)X.push_back(A[i][hn]);
        for(int j = hn-1;j >= ln && lm != hm;j--)X.push_back(A[hm][j]); //Additional condition  to handle case when there is only 1 row
        for(int i = hm-1;i > lm && ln != hn;i--)X.push_back(A[i][ln]); //Additional condition to handle case when there is only 1 column
        
        lm++;ln++;hm--;hn--;
    }
    return X;
}
