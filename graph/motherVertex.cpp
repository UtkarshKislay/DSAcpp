#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>&adj,vector<int>&vis,stack<int>&st,int src){
    vis[src]=1;
    for(auto it:adj[src]){
        if(!vis[it]){
            dfs(adj,vis,st,it);
        }
    }
    st.push(src);
}

void dfs(vector<vector<int>>&adj,vector<int>&vis,int src){
    vis[src]=1;
    for(auto it:adj[src]){
        if(!vis[it]){
            dfs(adj,vis,it);
        }
    }
   
}

int findMotherVertex(int n,vector<vector<int>> &adjlist)
{  
    vector<int>vis(n,0);
    stack<int>st;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(adjlist,vis,st,i);
        }
    }
    int val=st.top();
    vector<int>vis2(n,0);
    dfs(adjlist,vis2,val);
    for(int i=0;i<n;i++){
        if(vis2[i]==0)return -1;
    }
    return val+1;
}

int main()
{
    int n,m;cin>>n>>m;
    vector<vector<int>> adjlist(n);
    for(int i=0;i<m;++i)
    {
        int u,v;cin>>u>>v;
        adjlist[u-1].push_back(v-1);
    }
    cout<<findMotherVertex(n,adjlist)<<"\n";
    return 0;
}