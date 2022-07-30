/*
 link:https://www.hackerearth.com/practice/math/number-theory/
 basic-number-theory-1/practice-problems/algorithm/panda-and-chain-reaction/

 */

#include<bits/stdc++.h>
using namespace std;

#define ll long long
int M=1e6+3;


int main(){


  vector<ll>arr(M);
  arr[0]=arr[1]=1;
  for(int i=2;i<M;i++){
    //store the factorail till M in an array
	  arr[i]=(arr[i-1]%M*i%M)%M;
  }

    int t;cin>>t;
    

	while(t--){
		ll n,x;cin>>n>>x;
		if(n>M){
            // if n>M then it means fact(n) is a multiple of M hence fact(n)%M=0
			cout<<0<<endl;
			continue;
		}
        // Multiply fact with the x to get output
		ll ans=(arr[n]%M*(x%M))%M;
		cout<<ans<<endl;
	}

	return 0;
}