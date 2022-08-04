#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> & arr, int x){
    int i=0,j=arr.size()-1;
    while(i<=j){
        int mid=i+(j-i)/2;
        if(arr[mid]==x){
            return mid;
        }else if(arr[i]<=arr[mid]){
            if(x>=arr[i] && x<arr[mid]){
                j=mid-1;
            }else{
                i=mid+1;
            }
        }else{
            if(x<=arr[j] && x>arr[mid]){
                i=mid+1;
            }else{
                j=mid-1;
            }
        }
    }

    return -1;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int tar;
    cin>>tar;
    int ans = solution(arr,tar);
    cout<<ans<<endl;
}