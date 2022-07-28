#include<bits/stdc++.h>
using namespace std;

//***************************************************************************
// 2D DSU
// index=(rowIndex*(length of Col)+(colIndex)) | 0 based indexing
// index=i*m+j
// val -> i=val/m && j=val%m
int find(int i,int j,vector<vector<int>>&par,int m){
    int val=i*m+j;
    if(val==par[i][j]){
        return val;
    }
    int x=par[i][j]/m;
    int y=par[i][j]%m;
    int temp= find(x,y,par,m);
    par[x][y]=temp;
    return temp;
}

bool unio(int i1,int j1,int i2,int j2,vector<vector<int>>&par,int m){
    int lx=find(i1,j1,par,m);
    int ly=find(i2,j2,par,m);

    if(lx!=ly){
       par[lx/m][lx%m]=ly;
       return true;
    }
    return false;
}
//***************************************************************************

vector<int>numIslands2(int n,int m, vector<vector<int>>& pos){
    vector<vector<int>>dsu(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int val=i*m+j;
            dsu[i][j]=val;
            // cout<<val<<" ";
        }
        // cout<<endl;
    }
   
    vector<int>ans;
    int nIsland=0;
    vector<vector<int>>island(n,vector<int>(m,0));
    vector<int>dir={0,1,0,-1,0};
    for(int i=0;i<pos.size();i++){
        int x=pos[i][0];
        int y=pos[i][1];
        island[x][y]=1;
        bool ans1=0;
      for(int j=0;j<4;j++){
          int fi=x+dir[j];
          int se=y+dir[j+1];
        
          if(fi>=0 && se>=0 && fi<n && se<m && island[fi][se]==1){
            bool an=unio(x,y,fi,se,dsu,m);
            if(an){
                ans1=true;
                nIsland--;
            }
        
            // cout<<x<<" "<<y<<" "<<pos[i][0]<<" "<<pos[i][1]<<endl;
         
          }
        
      }
       nIsland++;
      ans.push_back(nIsland);
        
        
    }
 
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //        cout<<dsu[i][j]<<" ";
    //     }
    //     cout<<endl;
     
    // }

   
return ans;

 
}

int main(){
    int m,n,q;
    cin>>m>>n>>q;
    
    vector<vector<int>>pos(q,vector<int>(2));
    
    for(int i=0;i<q;i++){
        cin>>pos[i][0];
        cin>>pos[i][1];
    }
    vector<int>ans=numIslands2(m, n, pos);
    
    cout<<"[";
    for(int i=0;i<ans.size();i++){
        if(i==ans.size()-1)
            cout<<ans[i];
        else
            cout<<ans[i]<<", ";
    }
    cout<<"]";
    }