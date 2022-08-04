#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void findPair(vector<int> &arr,int target) {
    int i=0,j=1;
    int n=arr.size();
    sort(arr.begin(),arr.end());
    while(j<n){
        int diff=arr[j]-arr[i];
        if(diff==target && i!=j){
            cout<<arr[i]<<" "<<arr[j]<<endl;
            return;
        }else if(diff<target){
            j++;
        }else{
            i++;
        }
    }
    cout<<-1<<endl;
}

int main() {
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i < n;i++) {
        cin>>arr[i];
    }
    int target;
    cin>>target;
    findPair(arr,target);
    return 0;
}