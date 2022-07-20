//************************************************************************************

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	
	void dfs(int src,vector<int>adj[],vector<int>&vis,stack<int>&s){
	    if(vis[src])return;
	    vis[src]=true;
	    for(auto it:adj[src]){
	        if(!vis[it])dfs(it,adj,vis,s);
	    }
	    s.push(src);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    stack<int>s;
	    vector<int>vis(V,false);
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            dfs(i,adj,vis,s);
	        }
	    }
	    vector<int>ans;
	    while(!s.empty()){
	       // cout<<s.top()<<" ";
	        ans.push_back(s.top());
	        s.pop();
	    }
	    return ans;
	    
	}
};

//************************************************************************************
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>dep(V,0);
	    for(int i=0;i<V;i++){
	        for(auto it:adj[i]){
	            dep[it]++;
	        }
	    }
	    queue<int>q;
	    for(int i=0;i<V;i++){
	       if(dep[i]==0){
	           q.push(i);
	       }
	    }
	    vector<int>ans;
	    while(!q.empty()){
	        int crr=q.front();
	        q.pop();
	        ans.push_back(crr);
	        for(auto it:adj[crr]){
	            dep[it]--;
	            if(dep[it]==0){
	                q.push(it);
	            }
	        }
	    }
	    
	    return ans;
	}
};

//*******************************************************************************************


/**********************************************************

	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public : 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this -> data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

***********************************************************/
#include<vector>
void printVector( vector<int>& v, int i)
{
    for (int j = i; j < v.size(); j++)
        cout << v[j] << " ";
    cout << endl;
}
  
void rootToLeafPathsSumToKhelp(BinaryTreeNode<int>* root, vector<int>&path, int k)
{
    
    if (root==NULL){
        return;
    }
     path.push_back(root->data);
    if(root->left==NULL && root->right==NULL){
         int f = 0;
    for (int j = path.size() - 1; j >= 0; j--) {
        f += path[j];
       
    }
        
         if (f == k)
        {
            printVector(path,0);
            
        }
    }
    
   
  
    
    rootToLeafPathsSumToKhelp(root->left, path, k);
  	rootToLeafPathsSumToKhelp(root->right, path, k);
  
    
   
    
     
  
    
    path.pop_back();
}
void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k) {
    if(root==NULL){
        return;
    }
    vector<int> path;
   rootToLeafPathsSumToKhelp(root, path, k);
}


//**********************************************************************************
BinaryTreeNode<int>* buildTree1(int *preorder, int *inorder, int In_Start , int In_End ,int Pre_Start,int Pre_End) {
   // if(Pre_Start>Pre_End || In_Start>In_End){
   //     return NULL;
   // }
    if(Pre_Start>Pre_End){
        return NULL;
    }
     static int idx=0;
    int  rootData = preorder[idx];
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    
    idx=idx+1;
    
    int rootIndexIn=-1 ;
    
   
    
    if(Pre_Start==Pre_End){
        return root;
    }
    
    for(int i= In_Start ; i <=  In_End; i++ ){
        if(inorder[i] == rootData ){
            rootIndexIn = i ;
            break;
        }
     }
    
    
    int LInStart = In_Start ;
    int LInEnd = rootIndexIn - 1 ;
    int LPreStart = Pre_Start ;
    int LPreEnd = rootIndexIn - 1 ;
 
   
    
    int RInStart = rootIndexIn  + 1 ;
    int RInEnd = In_End;
    int RPreStart = rootIndexIn+1 ;
    int RPreEnd = Pre_End ;
    
        root->left = buildTree1(preorder, inorder ,In_Start ,LInEnd,LPreStart,LPreEnd);
        root-> right = buildTree1(preorder, inorder ,RInStart ,RInEnd ,RPreStart ,RPreEnd);
  

    return root ;
}

BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    // Write your code here
    return buildTree1(preorder, inorder , 0 , inLength-1  , 0 , preLength - 1);
    
}
