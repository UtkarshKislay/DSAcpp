//************************************Approach 1************************
class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;
    int childCount;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};

class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool add(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->childCount++;
        }

        // Recursive call
        return add(child, word.substr(1));
    }

    void add(string word) {
        if (add(root, word)) {
            this->count++;
        }
    }

    /*..................... Palindrome Pair................... */
    
    bool search(string word,TrieNode *root){
        if(word.size()==0){
            if(root->isTerminal){
                return true;
            }
            return false;
        }
        if(root->isTerminal){
            string temp=word;
            reverse(temp.begin(),temp.end());
            if(temp==word){
                return true;
            }
        }
        int idx=word[0]-'a';
        if(root->children[idx]!=NULL){
            return search(word.substr(1),root->children[idx]);
        }
        return false;
    }

    bool isPalindromePair(vector<string> words) {
         int n=words.size();
        for(int i=0;i<n;i++){
            string st=words[i];
            reverse(st.begin(),st.end());
            add(st);
        }
        for(int i=0;i<n;i++){
            int m=words[i].size();
            
            for(int j=0;j<m;j++){
                string st=words[i].substr(0,j);
                string temp=st;
                reverse(temp.begin(),temp.end());
                if(st==temp){
                   bool ans=search(words[i].substr(j),root);
                 if(ans){
                      return true;
                       }
                }
              
            }
         
        }
        return false;
    }
};


//******************************Approach 2**********************************
/*
Create a Map insert reverse word in it.Then search for the palindrome.






*/
class Solution {
public:
    
    
    string rever(string &word){
        string temp=word;
        reverse(temp.begin(),temp.end());
        return temp;
    }
    bool isPalindrome(string &str){
         int i = 0;
         int j = str.size() - 1; 

         while(i < j) {
             if(str[i++] != str[j--]) return false;
         }

         return true;
     }

    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string,int>m;
        for(int i=0;i<words.size();i++){
            m[rever(words[i])]=i;
        }
        vector<vector<int>>ans;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
                string left=words[i].substr(0,j);
                string right=words[i].substr(j);
                if(isPalindrome(left) && m.find(right)!=m.end() && m[right]!=i){
                    ans.push_back({m[right],i});
                }
                if(isPalindrome(right) && m.find(left)!=m.end() && m[left]!=i){
                   if(left==""){
                         ans.push_back({m[left],i});
                         ans.push_back({i,m[left]});
                   }else{
                        ans.push_back({i,m[left]});
                   }
                   
                }
            }
        }
        return ans;
    }
};

///

/*
int pairSum(int *arr, int n, int num)
{
	sort(arr,arr+n);
    int i=0,j=n-1;
    int numOfPair=0;
    while(i<j){
        int sum=arr[i]+arr[j];
        if(sum>num){
            j--;
        }else if(sum<num){
            i++;
        }else{
            
            if(arr[i]==arr[j]){
                int cnt=(j-i);
                numOfPair+=(cnt*(cnt+1)/2);
                return numOfPair;
            }
            int l=i+1;
            int r=j-1;
            // int cnt1=1;
            while(l<j && arr[l]==arr[i]){
                l++;
            }
            while(r>i && arr[r]==arr[j]){
                r--;
            }
            int cnt1=(l-i);
            int cnt2=(j-r);
            numOfPair+=(cnt1)*(cnt2);
            i=l;
            j=r;
        }
    }
    return numOfPair;
}
*/


#include<climits>
template < typename T>
    class paair {
     public:
        TreeNode<T>* node;
        T sum;
    };
paair<int>* maxSumNodeHelper(TreeNode<int>* root)
{
    if(root==NULL)
    {
        return NULL;
    }
    int sumMax=root->data;
    for(int i=0;i<root->children.size();i++)
    {
        sumMax+=root->children[i]->data;
    }
    paair<int>* max=new paair<int>();
    max->node=root;
    max->sum=sumMax;
    for(int i=0;i<root->children.size();i++)
    {
        paair<int>*temp=maxSumNodeHelper(root->children[i]);
        if(max->sum<temp->sum )
        {
            max=temp;
        }
        
    }
    return max;
    
}


TreeNode<int>* maxSumNode(TreeNode<int>* root) {
    
    return maxSumNodeHelper(root)->node;
}