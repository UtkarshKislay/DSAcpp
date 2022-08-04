#include<bits/stdc++.h>
using namespace std;

vector<int>parent;
vector<int>disc;
vector<int>low;
vector<bool>vis;

int timer;

void bridges(int u,vector<vector<int>>& graph,vector<vector<int>>& ans){
    vis[u]=true;
    disc[u]=low[u]=timer;
    timer++;
    for(auto it:graph[u]){
        if(parent[u]==it){
            continue;
        }else if(vis[it]){
            low[u]=min(low[u],disc[it]);
        }else{
            parent[it]=u;
            bridges(it,graph,ans);
            low[u]=min(low[u],low[it]);
            if(low[it]>disc[u]){
                ans.push_back({u,it});
            }
        }
    }
}


vector<vector<int>> criticalConnection(int n,vector<vector<int>>& edges){
    vector<vector<int>>graph(n);
    
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    parent.resize(n);
    disc.resize(n);
    low.resize(n);
    vis.resize(n);
    
    timer=0;
    
    vector<vector<int>>ans;
    bridges(0,graph,ans);
    
    return ans;
}


int main(){
    
    int n,e;
    cin>>n>>e;
    
    vector<vector<int>>edges(e);
    
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        edges[i].push_back(x);
        edges[i].push_back(y);
        
    }
    
    vector<vector<int>>ans=criticalConnection(n,edges);
    
    
    cout<<'[';
    for(int i=0;i<ans.size();i++){
        cout<<'[';
        for(int j=0;j<ans[0].size();j++){
            if(j==ans[0].size()-1){
                cout<<ans[i][j];
            }else{
                cout<<ans[i][j]<<", ";
            }
        }
        if(i==ans.size()-1){
            cout<<"]";
        }else{
            cout<<"], ";
        }
    }
    cout<<"]";
    
    
}