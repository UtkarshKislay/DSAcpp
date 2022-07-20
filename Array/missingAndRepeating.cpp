#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	int xorr=0;
    for(int i=0;i<n;i++){
        xorr^=arr[i];
    }
    for(int i=1;i<=n;i++){
        xorr^=i;
    }
    int x=0,y=0;
    int rbs=xorr&(-xorr);
    for(int i=0;i<n;i++){
        if(rbs&arr[i]){
            y^=arr[i];
        }else{
            x^=arr[i];
        }
    }
    for(int i=1;i<=n;i++){
        if(rbs&i){
            y^=i;
        }else{
            x^=i;
        }
    }
    for(int i=0;i<n;i++){
        if(x==arr[i]){
            return {y,x};
        }else if(y==arr[i]){
            return {x,y};
        }
    }
	return {x,y};
}
