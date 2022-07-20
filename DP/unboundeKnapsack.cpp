int unboundedKnapsack(int n,int w,vector<int>&profit,vector<int>&weight,vector<vector<int>>&dp){
    if(n<0 || w<0){
        return 0;
    }
    if(dp[n][w]!=-1){
        return dp[n][w];
    }
    int ans1=0;
    if(w-weight[n]>=0){
     ans1=unboundedKnapsack(n,w-weight[n],profit,weight,dp)+profit[n];
    }
    int ans2=unboundedKnapsack(n-1,w,profit,weight,dp);
    return dp[n][w]= max(ans1,ans2);
} 

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
   vector<vector<int>>dp(n,vector<int>(w+1,0));
   for(int i=0;i<n;i++){
       for(int j=0;j<=w;j++){
           int ans1=0;
           if(j-weight[i]>=0){
               ans1=dp[i][j-weight[i]]+profit[i];
           }
           int ans2=0;
           if(i-1>=0){
               ans2=dp[i-1][j];
           }
           dp[i][j]=max(ans1,ans2);
       }
   }
    return dp[n-1][w];
//    return unboundedKnapsack(n-1,w,profit,weight,dp); 
    
}


import requests
BASE_URL = 'https://api.openweathermap.org/data/2.5/weather?'
CITY = "Hyderabad"
API_KEY = "378c4c160f9077f9fc0085073ec0a2e9"
URL = BASE_URL + 'q=' + CITY + "&appid=" + API_KEY
response = requests.get(URL)
r = response.json()
## Print the required output in given format
# print(r)
print("City:<",r['name'],">")
print("Temperature:<",r['main']['temp'],">")
print("Weather Report:<",r['weather'][0]['description'],">")