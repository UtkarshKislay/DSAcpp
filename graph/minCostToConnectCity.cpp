#include<bits/stdc++.h>
using namespace std;

class Edge{
    public:
    int v;
    int wt;
    Edge(int v,int wt)
    {
        this->v=v;
        this->wt=wt;
    }
};

// int find(int x,vector<int>&dsu){
//     if(x==dsu[x])return x;
//     int temp=find(dsu[x],dsu);
//     dsu[x]=temp;
//     return temp;
// }

// int join(int x,int y,vector<int>&dsu){
//     int lx=find(x,dsu);
//     int ly=find(y,dsu);
//     if(lx!=ly){
//         dsu[lx]=ly;
//         return true;
//     }
//     return false;
// }

bool operator<(const Edge &a ,const Edge &b){
    return a.wt>b.wt;
}


int main()
{
    int vtces;
    cin>>vtces;
    vector<vector<Edge>> graph(vtces);
    int edges;cin>>edges;
    for(int i=0;i<edges;++i)
    {
        int v1;cin>>v1;
        int v2;cin>>v2;
        int wt;cin>>wt;
        graph[v1].push_back(Edge(v2,wt));
        graph[v2].push_back(Edge(v1,wt));
    }
    
    // vector<int>dsu(vtces+1,0);
    // for(int i=0;i<vtces+1;i++)dsu[i]=i;
    int ans=0;
   priority_queue<Edge>q;
   q.push({0,-1});
   vector<int>vis(vtces+1,0);
//    int ans=0;
  while(!q.empty()){
      Edge p=q.top();
      q.pop();
      int v=p.v;
      int cost=p.wt;
      if(vis[v])continue;
      vis[v]=1;
     if(cost>0)ans+=cost;
      for(auto it:graph[v]){
        //   for(int i=0;i<it.size();i++){
              q.push({it.v,it.wt});

        //   }
      }

  }

  cout<<ans<<endl;
  
   

    
    return 0;
}