#include <iostream>
#include<vector>
using namespace std;

int ans(string old,string newStr,string f,int idx,int n){
    if(f==newStr){
        return 1;
    }
  if(idx>=n ||f.size()>newStr.size()){
      return 0;
  }
  int ans1=ans(old,newStr,f+old[idx],idx+1,n);
  int ans2=ans(old,newStr,f,idx+1,n);
  
  return ans1+ans2;
}

int main() {
  string old,newStr;cin>>old>>newStr;
//   int an=0;
  int an=ans(old,newStr,"",0,old.size());
vector<vector<int>>dp(newStr.size(),vector<int>(old.size(),0));
int n=newStr.size();
int m=old.size();
for(int i=0;i<m;i++){
    if(old[i]==newStr[0]){
        if(i-1>=0){
            dp[0][i]=dp[0][i-1]+1;
        }else{
            dp[0][i]=1;
        }
    }else{
        if(i-1>=0){
            dp[0][i]=dp[0][i-1];
        }
    }
}

for(int i=1;i<newStr.size();i++){
    for(int j=1;j<old.size();j++){
        if(newStr[i]==old[j]){
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }else{
            dp[i][j]=dp[i][j-1];
        }
       
    }
}

// for(int i=0;i<n;i++){
//     for(int j=0;j<m;j++){
//         cout<<dp[i][j]<<" ";
//     }
//     cout<<endl;
// }

 
  cout<<dp[newStr.size()-1][old.size()-1]<<" "<<an<<endl;
}