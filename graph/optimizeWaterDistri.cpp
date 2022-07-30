#include<bits/stdc++.h>
using namespace std;

int find(int x,vector<int>&dsu){
    if(dsu[x]==x)return x;
    int temp=find(dsu[x],dsu);
    dsu[x]=temp;
    return temp;
}

bool join(int x,int y,vector<int>&dsu){
    int lx=find(x,dsu);
    int ly=find(y,dsu);
    if(lx!=ly){
        dsu[lx]=ly;
        return true;
    }
    return false;
}

bool cmp(vector<int>&a,vector<int>&b){
    return a[2]<b[2];
}

int minCostToSupplyWater(int n, vector<int>&wells, vector<vector<int>>& pipes){
      vector<int>dsu(n+1,0);
      for(int i=0;i<n+1;i++)dsu[i]=i;
      int tcost=0;
      for(int i=1;i<=n;i++){
          pipes.push_back({0,i,wells[i-1]});
          //makes new connection from 0-i having cost=wells[i-1]
      }
      sort(pipes.begin(),pipes.end(),cmp);
      for(int i=0;i<pipes.size();i++){
          int x=pipes[i][0];
          int y=pipes[i][1];
          int cost=pipes[i][2];

          if(join(x,y,dsu)){
              tcost+=cost;
          }
      }

      return tcost;

}


int main(){
    int v,e;
    cin>>v>>e;
    
    
    vector<int>wells(v);
    
    for(int i=0;i<v;i++){
        cin>>wells[i];
    }
    
    
    vector<vector<int>>pipes(e,vector<int>(3));
    
    for(int i=0;i<e;i++){
        for(int j=0;j<3;j++){
            cin>>pipes[i][j];
        }
    }
    
    cout<<minCostToSupplyWater(v, wells, pipes);
    
}