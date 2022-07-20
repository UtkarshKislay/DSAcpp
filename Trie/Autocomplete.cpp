/*
sort the given vector of string then search for its prefix.
*/

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& p, string s) {
        sort(p.begin(),p.end());
        int n=p.size();
        vector<vector<string>>ans;
        for(int i=1;i<=s.size();i++){
            string ch=s.substr(0,i);
            int count=0;
            vector<string>an;
            for(int j=0;j<n && count<3;j++){
                if(p[j].substr(0,i)==ch){
                    an.push_back(p[j]);
                    count++;
                }
            }
            ans.push_back(an);
        }
        
        return ans;
    }
};

//***********************************************************
vector<vector<string>> suggestedProducts(vector<string>& A, string searchWord) {
        auto it = A.begin();
        sort(it, A.end());
        vector<vector<string>> res;
        string cur = "";
        for (char c : searchWord) {
            cur += c;
            vector<string> suggested;
            it = lower_bound(it, A.end(), cur);
            for (int i = 0; i < 3 && it + i != A.end(); i++) {
                string& s = *(it + i);
                if (s.find(cur)) break;
                suggested.push_back(s);
            }
            res.push_back(suggested);
        }
        return res;
    }
//********************************************************************************
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& p, string s) {
        int n=p.size();
        int m=s.size();
        int i=0,j=n-1;
        sort(p.begin(),p.end());
         vector<vector<string>>ans; 
    for(int k=0;k<s.size();k++){
        while(i<=j && (p[i].size()<k || p[i][k]<s[k])){
            i++;
        }
        while(j>=i && (p[i].size()<k || p[j][k]>s[k])){
            j--;
        }
      
        vector<string>an;
        for(int cnt=i;cnt<=j && cnt<i+3;cnt++){
            an.push_back(p[cnt]);
        }
        ans.push_back(an);
         }
        
        return ans;
    }
};