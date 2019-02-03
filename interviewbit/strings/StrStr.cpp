/*
Question :
Implement strStr().

 strstr - locate a substring ( needle ) in a string ( haystack ). 
Try not to use standard library string functions for this question.

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 NOTE: Good clarification questions:
What should be the return value if the needle is empty?
What if both haystack and needle are empty?
For the purpose of this problem, assume that the return value should be -1 in both cases. 
*/

int Solution::strStr(const string A, const string B) {
    if(A == "")return -1;
    if(A == "" && B == "")return -1;
    //KMP implementation
    
    //LPS array creation
    int p1=0,p2=1;
    int lps[B.length()];
    
    lps[0] = 0;
    
    while(p2 < B.length()){
        if(B[p1] == B[p2])lps[p2++] = ++p1;
        else{
            if(p1 == 0)lps[p2++] = 0;
            else p1 = lps[p1-1];
        }
    }
    
    //KMP algorithm:
    int j = 0,i;
    for(i = 0;i < A.length();){
        if(j == B.length())return i-B.length();
        if(A[i] == B[j]){j++;i++;}
        else{
            if(j == 0)i++;
            else j = lps[j-1];
        }
    }
    
    if(j == B.length())return i-B.length();
    return -1;
}
