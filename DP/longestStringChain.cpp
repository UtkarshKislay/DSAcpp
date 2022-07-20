bool ispossible(string &s,string &t){
    if(s.size()!=t.size()+1)return false;
    int i=0,j=0;
    while(i<s.size()){
        if(s[i]==t[j]){
            i++;
            j++;
        }else{
            i++;
        }
    }
    if(i==s.size() && j==t.size())return true;
    return false;
}


bool cmp(string &s,string &t){
    return s.size()<t.size();
}

int longestStrChain(vector<string> &arr)
{
    int n=arr.size();
    sort(arr.begin(),arr.end(),cmp);
    vector<int>dp(n,1);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
           if(ispossible(arr[i],arr[j]) && dp[i]<1+dp[j]){
               dp[i]=1+dp[j];
           }
        }
    }
    int maxi=0;
    for(int i=0;i<n;i++){
        maxi=max(dp[i],maxi);
    }
    
    return maxi;
}