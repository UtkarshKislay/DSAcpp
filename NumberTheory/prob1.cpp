#include <iostream>
using namespace std;
// #defing int int
#define ll long long int
ll modExpon(ll a,ll b,ll m){
	if(b==0){
		return 1;
	}
	if(b==1)return a;
	ll ans=a;
    ll temp=modExpon(a,b/2,m)%m;
   if(b&1){
	   return  (ans%m*temp%m*temp%m*1ll)%m;
   }
   return (temp%m*temp%m*1ll)%m;

}

ll d, x, y;
void extendedEuclid(ll A, ll B) {
    if(B == 0) {
        d = A;
        x = 1;
        y = 0;
    }
    else {
        extendedEuclid(B, A%B);
        ll temp = x;
        x = y;
        y = temp - (A/B)*y;
    }
}



ll modInverse(ll A, ll M)
{
    extendedEuclid(A,M);
    return (x%M+M)%M;    //x may be negative
}

int main() {
	ll a,b,c,m;cin>>a>>b>>c>>m;
	ll first=modExpon(a,b,m);
    ll secon=modInverse(c,m);
	ll ans=(first%m*secon%m*1ll)%m;
	cout<<ans<<endl;

}