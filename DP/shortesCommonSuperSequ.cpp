#include<vector>
#include<algorithm>


//find lcs then 

string shortestSupersequence(string a, string b)
{ 
    int n=a.size(),m=b.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j]=1+dp[i-1][j-1];          
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    string s="";
    int i=n,j=m;
    while(i>0 && j>0){
        if(a[i-1]==b[j-1]){
            s+=a[i-1];
            i--;
            j--;
        }else{
            if(dp[i-1][j]>dp[i][j-1]){
                i--;
            }else{
                j--;
            }
        }
    }
    reverse(s.begin(),s.end());
    
    
    string ans="";
     i=0,j=0;
    int k=0;
    while(i<n && j<m){
        if(s[k]==a[i] && s[k]==b[j]){
            ans+=a[i];
            i++;
            j++;
            k++;
        }else if(s[k]!=a[i] && s[k]!=b[j]){
            ans+=a[i];
            ans+=b[j];
            i++;
            j++;
        }else if(s[k]!=a[i]){
            ans+=a[i];
            i++;
        }else{
            ans+=b[j];
            j++;
        }
    }
    while(i<n){
        ans+=a[i];
        i++;
    }
    while(j<m){
        ans+=b[j];
        j++;
    }
//     cout<<ans<<endl;
    return ans;
    
}