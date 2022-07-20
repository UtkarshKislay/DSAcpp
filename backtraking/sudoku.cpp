#include<bits/stdc++.h>
using namespace std;

bool isValid(int matrix[9][9]){
     int n=9;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int val=matrix[i][j];
         
            if(val==0)continue;
            
           for(int k=0;k<n;k++){
               if(k!=i && matrix[k][j]==val)return false;
           }
            for(int k=0;k<n;k++){
                if(k!=j && matrix[i][k]==val)return false;
            }
            int row=(i/3)*3;
            int col=(j/3)*3;
           for(int k1=row;k1<row+3;k1++){
               for(int k2=col;k2<col+3;k2++){
                   if(k1!=i && k2!=j && matrix[k1][k2]==val)return false;
               }
           } 
           
        }
    }
    
    return true;
}

void print(int matrix[9][9]){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool isSudoko(int matrix[9][9],int i,int j,int n){
    if(j==n){
       i=i+1;
       j=0;
   }
    if(i>=n){
        bool ans= isValid(matrix);
        if(ans){
            print(matrix);
        }
        return ans;
    }
   bool ans=false;
    if(matrix[i][j]==0){
        for(int k=1;k<=n;k++){
            matrix[i][j]=k;
            if(isValid(matrix)){
                ans=ans||isSudoko(matrix,i,j+1,n);
            }
            matrix[i][j]=0;
        }
    }else{
        ans=isSudoko(matrix,i,j+1,n);
    }
    return ans;
}

bool isItSudoku(int matrix[9][9]) {
     return isSudoko(matrix,0,0,9);
}


int main(){
    int matrix[9][9];
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>matrix[i][j];
        }
    }
    
    bool ans=isItSudoku(matrix);
  
}

    
int rightSetBit(int x){
    return x&(-x);
}

int lastPowrof2(int n){
   int pos=31;
  for(int i=31;i>=0;i--){
    if((n&(1<<i))!=0){
         pos=i;
         break;
    }
  }
  int ans=pow(2,pos)-1;
  return ans;
}
bool bitSetUnset(int n,int k)
{
    int new_num = n >> (k - 1);
    return (new_num & 1);
}
bool isPowerOfTwo(int x)
{
     return x && (!(x & (x - 1)));
}

string toBinary(int n, int len)
{
    string binary;
    for (unsigned i = (1 << len - 1); i > 0; i = i / 2) {
        binary += (n & i) ? "1" : "0";
    }
    return binary;
}

int binaryToDecimal(int n)
{
    int num = n;
    int dec_value = 0;
    int base = 1;
    int temp = num;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;
        dec_value += last_digit * base;
        base = base * 2;
    }
    return dec_value;
}