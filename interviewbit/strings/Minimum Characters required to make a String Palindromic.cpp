/*
You are given a string. The only operation allowed is to insert characters in the beginning of the string. How many minimum characters are needed to be inserted to make the string a palindrome string

Example:
Input: ABC
Output: 2
Input: AACECAAAA
Output: 2

*/

bool checkPalin(string x){
    int p1 = 0,p2 = x.length()-1;
    while(p1 < p2){
        if(x[p1] != x[p2])return 0;
        p1++;p2--;
    }
    return 1;
}
int Solution::solve(string A) {
    //Check for the longest palindrome starting from index 0.
    char z = A[0];
    vector <int> V;
    for(int i = A.length()-1;i > 0;i--){
        if(A[i] == z)V.push_back(i+1);
    }
    
    for(int i = 0;i < V.size();i++){
        if(checkPalin(A.substr(0,V[i]))){
            return A.length() - V[i];
        }
    }
    
    return A.length() - 1;
}
