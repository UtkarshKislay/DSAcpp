#include<bits/stdc++.h>
vector<int> divisibleSet(vector<int> &arr){
    int n=arr.size();
    vector<int>dp(n,1),hash(n,0);
    sort(arr.begin(),arr.end());
    int maxi=1;
    int lidx=0;
    for(int i=0;i<n;i++){
        hash[i]=i;
        for(int j=0;j<i;j++){
            if(arr[i]%arr[j]==0 && 1+dp[j]>dp[i]) {
                dp[i]=dp[j]+1;
                hash[i]=j;
            }
        }
        if(dp[i]>maxi){
            maxi=dp[i];
            lidx=i;
        }
    }
    vector<int>temp;
    temp.push_back(arr[lidx]);
    while(hash[lidx]!=lidx){
        lidx=hash[lidx];
        temp.push_back(arr[lidx]);
    }
    reverse(temp.begin(),temp.end());
//     for(int i=0;i<temp.size();i++){
//         cout<<temp[i]<<" ";
//     }
    return temp;
}