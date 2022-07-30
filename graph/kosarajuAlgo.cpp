#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>&graph,int n,vector<int>&vis,stack<int>&st,int src){
//   if(vis[src])return;
 
  vis[src]=1;
  for(auto it:graph[src]){
	  if(!vis[it]){
		  dfs(graph,n,vis,st,it);
	  }
  }
   st.push(src);
}

void dfs(vector<vector<int>>&graph,int src,vector<int>&visi){
	// if(visi[src])return;
	visi[src]=1;
	for(auto it:graph[src]){
		if(!visi[it]){
			dfs(graph,it,visi);
		}
}
}

int kosaraju(vector<vector<int>> & graph,int n){
    vector<int>vis(n,0);
	stack<int>st;
	for(int i=0;i<n;i++){
		if(!vis[i]){
	       dfs(graph,n,vis,st,i);
		}
	}

	vector<vector<int>>newGraph(n);
	for(int i=0;i<n;i++){
		for(auto it:graph[i]){
			newGraph[it].push_back(i);
		}
	}

	int cnt=0;
	vector<int>visi(n,0);
	while(st.size()>0){
		int val=st.top();
		st.pop();
		if(visi[val]){
			continue;
		}
	   dfs(newGraph,val,visi);
	   cnt++;
	}
	// for(int i=0;i<n;i++){
	// 	if(!visi[i]){
	// 		dfs(newGraph,i,visi);
	// 		cnt++;
	// 	}
	// }

	// for(int i=0;i<n;i++){
	//   cout<<i+1<<" :";
	//   for(auto it:newGraph[i]){
	// 	  cout<<it+1<<" ";
	// }
	//   cout<<endl;
	// }

	return cnt;

}

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>>graph(n); 
	for(int i = 0;i<m;i++) {
	    int u, v;
	    cin >> u >> v; 
	    graph[u-1].push_back(v-1);
	}
    cout<<kosaraju(graph, n);
}
