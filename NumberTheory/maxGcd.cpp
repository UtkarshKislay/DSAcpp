/*

If you can't conquer yourself, then forget to conquer the world !!

*/
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;

void in_itCode();

//typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>pb_ds;
#define ll long long int
#define end_l "\n"
#define loop(i,a,b) for(int i=a;i<b;i++)
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
#define vect vector<int>
#define pb push_back
#define makep make_pair<int,int>
#define paivect vector<pair<int,int>> 

string toBinary(int n, int len)
{
    string binary;
    for (unsigned i = (1 << len - 1); i > 0; i = i / 2) {
        binary += (n & i) ? "1" : "0";
    }
 
    return binary;
}


int main(int argc, char const *argv[])
{   
    // boost  
      //  in_itCode();
    //  int t;cin>>t;
   //   while(t--){

  //     } 

       int n;cin>>n;
       cout<<n<<endl;

  


      
    return 0;
}

void in_itCode(){
#ifndef ONLINE_JUDGE
freopen("V:/input.txt", "r", stdin);
freopen("V:/output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}