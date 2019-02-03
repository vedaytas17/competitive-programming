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
    /*
       Notes on LPS creation:
       lps[i] is, the length of proper suffix that is also the proper prefix, of the substring(0..i). "Proper" prefix/suffix is all possible prefixes/suffixes except for the whole string. 
       
       Optimization for preparing the LPS array.
       Say we maintain 2 pointers p1 and p2. If charAt p1 == charAt p2, the lps value is simply p1+1.. However, if charAt p1 != charAt p2, we have to go back to the point s.t, p1 points to the character (+1th postion) which is the lps for the substring s(0..p2-1).. For going to that position, we have optimized jumps in the code. Debug the code to undertsnad the same.
    */
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
    /*
     Notes :
      The KMP algorithm uses the LPS array and traverses the text only once. If a mismatch occurs at position 'i' in text(A) and position(j) in Pattern(B), then halt at i, if j is not 0.
      If j is 0, increment i, meaning the pattern is available only in substring(i+1,...A.length()).
      If j is not 0, then go back to the position (j = )lps[j-1] and try to match the character at j with i and so on...
    */
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
