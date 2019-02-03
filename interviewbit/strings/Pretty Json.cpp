/*
Question :
Pretty print a json object using proper indentation.

Every inner brace should increase one indentation to the following lines.
Every close brace should decrease one indentation to the same line and the following lines.
The indents can be increased with an additional ‘\t’
Example 1:

Input : {A:"B",C:{D:"E",F:{G:"H",I:"J"}}}
Output : 
{ 
    A:"B",
    C: 
    { 
        D:"E",
        F: 
        { 
            G:"H",
            I:"J"
        } 
    } 
}
Example 2:

Input : ["foo", {"bar":["baz",null,1.0,2]}]
Output : 
[
    "foo", 
    {
        "bar":
        [
            "baz", 
            null, 
            1.0, 
            2
        ]
    }
]
[] and {} are only acceptable braces in this case.

Assume for this problem that space characters can be done away with.

Your solution should return a list of strings, where each entry corresponds to a single line. The strings should not have “\n” character in them.
*/

vector<string> Solution::prettyJSON(string A) {
    vector<string> X;
    
    string fx = "";
    string pre = "";
    
    int indentCount = 0;
    
    for(int i = 0; i < A.length();i++){
        if(A[i] == '{' || A[i] == '}' || A[i] == '[' || A[i] == ']'){
            
            if(fx != "")X.push_back(pre+fx);
            
            fx = "";
            if(A[i] == '{' || A[i] == '['){
                X.push_back(pre + string(1,A[i]));pre="";
                indentCount++;
                for(int j = 0;j < indentCount;j++)pre += '\t';
            }
            else{
                indentCount--;pre = "";
                for(int j = 0;j < indentCount;j++)pre += '\t';
                X.push_back(pre + string(1,A[i]));
            }
        }
        else if(A[i] == ',' || A[i] == ';'){
            if(A[i-1] == '{' || A[i-1] == '}' || A[i-1] == '[' || A[i-1] == ']'){
                fx = X.back();
                X.pop_back();
                fx += A[i];
                X.push_back(fx);
                fx = "";
            }
            else{
                fx += A[i];
                X.push_back(pre + fx);
                fx = "";
            }
        }
        else fx += A[i];
    }
    //for(int i = 0;i < X.size();i++)cout<<X[i]<<' '<<i<<endl;;
    return X;
}
