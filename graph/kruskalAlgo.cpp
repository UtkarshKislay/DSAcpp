#include<bits/stdc++.h>
using namespace std;

bool cmp(vector<int>&a,vector<int>&b){
    return a[2]<b[2];
}

int find(int x,vector<int>&dsu){
    if(x==dsu[x])return x;
    int temp=find(dsu[x],dsu);
    dsu[x]=temp;
    return temp;
}

bool unio(int x,int y,vector<int>&dsu){
    int lx=find(x,dsu);
    int ly=find(y,dsu);
    if(lx!=ly){
        dsu[lx]=ly;
        return true;
    }
    return false;
}

int minCostToSupplyWater(int n,vector<vector<int>>&graph){
    sort(graph.begin(),graph.end(),cmp);
    vector<int>dsu(n+1,-1);
    for(int i=0;i<n+1;i++){
        dsu[i]=i;
    }

   int tcost=0;
    for(int i=0;i<graph.size();i++){
        int x=graph[i][0];
        int y=graph[i][1];
        int cost=graph[i][2];
        if(unio(x,y,dsu)){
          tcost+=cost;
        }
    }
    return tcost;
}
int main(){
    int v,e;
    cin>>v>>e;
    
    vector<vector<int>>pipes(e,vector<int>(3));
    
    for(int i=0;i<e;i++){
        for(int j=0;j<3;j++){
            cin>>pipes[i][j];
        }
    }
    cout<<minCostToSupplyWater(v,pipes);
    }


