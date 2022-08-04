#include<bits/stdc++.h>
using namespace std;

int maximise(vector<int>& arr)
{   
    int n=arr.size();
    int sum=0;
    int fans=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        fans+=i*arr[i];
    }
    int ans=fans;
    for(int i=1;i<n;i++){
        int temp=fans+sum-arr[n-i]*n;
        fans=temp;
        ans=max(ans,temp);
    }
   
    return ans;




}

int main()
{
    int n;
    cin>>n;
    
    vector<int> arr(n,0);
    for(int i =0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    int ans = maximise(arr);
    cout<<ans;
    
}