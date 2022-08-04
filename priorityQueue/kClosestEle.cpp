#include<bits/stdc++.h>


using namespace std;
struct cmp{
  bool operator()(pair<int,int>a,pair<int,int>b){
      return a.second<b.second;
  }
};
vector<int> findClosest(vector<int> &arr, int k, int x){
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq;
    int n=arr.size();
   for(int i=0;i<k;i++){
       pq.push({arr[i],abs(x-arr[i])});
   }
   for(int i=k;i<n;i++){
       if(pq.top().second>abs(x-arr[i])){
           pq.pop();
           pq.push({arr[i],abs(x-arr[i])});
       }

   }
   vector<int>ans;
   while(!pq.empty()){
       ans.push_back(pq.top().first);
       pq.pop();
   }
   sort(ans.begin(),ans.end());
   return ans;
    
}

int main(){
    int n;
    cin>>n;
    vector<int> arr;
    
    for(int i=0; i<n; ++i){
        int a;
        cin>>a;
        arr.push_back(a);
    }
    
    int k, x;
    cin>>k>>x;
    
    vector<int> ans=findClosest(arr, k, x);
    
    for(int ele: ans){
        cout<<ele<<" ";
    }
    
    return 0;
}

// optimized if sorted array is give

class Solution {
 public:
    
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
      
        vector<int>ans;
         int n=arr.size();
        int i=0,j=n-1;
        int idx=-1;
        int cnt=0;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(arr[mid]==x){
                idx=mid;
                break;
            }else if(arr[mid]<x){
                i=mid+1;
            }else{
                j=mid-1;
            }
        }
        
        if(idx!=-1){
            i=idx-1;
            j=idx+1;
            ans.push_back(arr[idx]);
            cnt++;
        }else{
            swap(i,j);
        }
        
        while(i>=0 && j<n && cnt<k){
            if(abs(x-arr[i])<=abs(x-arr[j])){
                ans.push_back(arr[i]);
                i--;
            }else{
                ans.push_back(arr[j]);
                j++;
            }
            cnt++;
        }
        
  
        while(i>=0 && cnt<k){
                ans.push_back(arr[i]);
                i--;
              cnt++;
            }
        while(j<n && cnt<k){
            ans.push_back(arr[j]);
            j++;
           cnt++;
        }
        sort(ans.begin(),ans.end());
        return ans;
        
        
    }
};