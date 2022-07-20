
//************************************************************************************************
class kn{
    public:
    int x,y,count;
    kn(int x,int y,int count){
        this->x=x;
        this->y=y;
        this->count=count;
    }
};

class Solution 
{
    
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&start,vector<int>&end,int n)
	{
	    vector<vector<int>>vis(n,vector<int>(n,0));
	    queue<kn>q;
	    q.push({start[0]-1,start[1]-1,0});
	    int cnt=0;
	    vis[start[0]-1][start[1]-1]=1;
	    while(!q.empty()){
	        kn an=q.front();
	        int x=an.x;
	        int y=an.y;
	        int cnt=an.count;
	        q.pop();
	        if(x==end[0]-1 && y==end[1]-1){
	            return cnt;
	        }
	        if(x-2>=0 && y+1<n && !vis[x-2][y+1]){
	            vis[x-2][y+1]=1;
	            q.push({x-2,y+1,cnt+1});
	        }
	        if(x-2>=0 && y-1>=0 && !vis[x-2][y-1]){
	            vis[x-2][y-1]=1;
	            q.push({x-2,y-1,cnt+1});
	        }
	        if(x-1>=0 && y+2<n && !vis[x-1][y+2]){
	            vis[x-1][y+2]=1;
	            q.push({x-1,y+2,cnt+1});
	        }
	        if(x-1>=0 && y-2>=0 && !vis[x-1][y-2]){
	            vis[x-1][y-2]=1;
	            q.push({x-1,y-2,cnt+1});
	        }
	        if(x+1<n && y+2<n && !vis[x+1][y+2]){
	            vis[x+1][y+2]=1;
	            q.push({x+1,y+2,cnt+1});
	        }
	        if(x+1<n && y-2>=0 && !vis[x+1][y-2]){
	            vis[x+1][y-2]=1;
	            q.push({x+1,y-2,cnt+1});
	        }
	        if(x+2<n && y+1<n && !vis[x+2][y+1]){
	            vis[x+2][y+1]=1;
	            q.push({x+2,y+1,cnt+1});
	        }
	        if(x+2<n && y-1>=0 && !vis[x+2][y-1]){
	            vis[x+2][y-1]=1;
	            q.push({x+2,y-1,cnt+1});
	        }
	        
	    }
	    return -1;
	}
	
	
};

//************************************************************************************************