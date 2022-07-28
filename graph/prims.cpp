#include <iostream>
#include<vector>
#include<queue>
using namespace std;

class Edge{
    public:
    int src;
    int nbr;
    int wt;
    Edge(int src,int nbr,int wt){
        this->src=src;
        this->nbr=nbr;
        this->wt=wt;
    }
};

class pairp{
    public:
    int vrtx;
    int dis;
    
    
    pairp(int vrtx,int dis){
        this->vrtx=vrtx;
        this->dis=dis;
    }
};

bool operator<(const pairp& a, const pairp&b){
    return a.dis>b.dis;
}

int prims(vector<vector<Edge>>&graph,int n,int src){
     vector<bool>vis(n,false);
    priority_queue<pairp>q;
    int ans=0;
    q.push({src,0});
    while(!q.empty()){
        pairp p=q.top();
        ans+=p.dis;
        q.pop();
        if(vis[p.vrtx]){
            continue;
        }
        vis[p.vrtx]=true;
        for(Edge e: graph[p.vrtx]){
            if(!vis[e.nbr]){
                q.push({e.nbr,e.wt});
            }
        }
    }

    return ans;
}


int main() {
   int v,e;cin>>v>>e;
    vector<vector<Edge>>graph(v);
    for(int i=0;i<e;i++){
        int src,nbr,wt;
        cin>>src>>nbr>>wt;
        graph[src].push_back({src,nbr,wt});
        graph[nbr].push_back({nbr,src,wt});
    }
    int src;cin>>src;
    
 int ans=prims(graph,v,src);
 cout<<ans<<endl;
    
    
}
