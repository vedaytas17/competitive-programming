/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example:

Given the array [-2,1,-3,4,-1,2,1,-5,4],

the contiguous subarray [4,-1,2,1] has the largest sum = 6.

For this problem, return the maximum sum.
*/

int Solution::maxSubArray(const vector<int> &A) {
    int ans = -1e9+7;
    for(int i = 0;i < A.size();i++){
        ans = max(ans,A[i]);
    }
    vector <int> cum;
    cum.push_back(A[0]);
    for(int i = 1;i < A.size();i++){
        cum.push_back(cum[i-1]+A[i]);
    }
    int mini = 0;
    for(int i = 1;i < A.size();i++){
        ans = max(ans,cum[i]-mini);
        mini = min(mini,cum[i]);
    }
    return ans;
}
