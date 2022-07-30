#include<bits/stdc++.h>
using namespace std;
class pairs{
    public:
    int x,y,wt;
    pairs(int x,int y,int wt){
        this->x=x;
        this->y=y;
        this->wt=wt;
    }
};
bool operator<(const pairs&a,const pairs&b){
    return a.wt>b.wt;
}


int swimInRisingWater(vector<vector<int>>&grid)
{
    int n=grid.size();
    int m=grid[0].size();

    priority_queue<pairs>q;
    q.push({0,0,grid[0][0]});
    vector<vector<int>>vis(n,vector<int>(m,0));
    vector<int>dir={0,1,0,-1,0};
    while(!q.empty()){
        pairs p=q.top();
        q.pop();
        int x=p.x;
        int y=p.y;
        int cost=p.wt;

        if(x==n-1 && y==m-1){
            return cost;
        }
        if(vis[x][y])continue;
        vis[x][y]=1;
        for(int i=0;i<4;i++){
            int x1=x+dir[i];
            int y1=y+dir[i+1];
            if(x1>=0 && y1>=0 && x1<n && y1<m && vis[x1][y1]==0){
                q.push({x1,y1,max(grid[x1][y1],cost)});
            }
        }

       
    }
    return -1;
}

int main()
{
    int n;cin>>n;
    int m;cin>>m;
    vector<vector<int>> grid(n,vector<int>(m));
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j) cin>>grid[i][j];
    cout<<swimInRisingWater(grid)<<"\n";
    return 0;
}