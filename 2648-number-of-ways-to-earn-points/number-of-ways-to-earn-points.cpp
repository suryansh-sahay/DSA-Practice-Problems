class Solution {
public:
    int mod=1e9+7; 
    
    int cal(int i ,int n , vector<vector<int>>& types , int sum , int tar  , vector<vector<int>>& dp)
    {
        if(sum>tar)
            return 0 ; 
        
      if(sum==tar)
          return 1; 
        
        if(i==n)
        {
            return tar==sum; 
        }
        
        if(dp[i][sum]!=-1)
            return dp[i][sum] ;
        
         int take=0 , nottake=0 ; 
        
        // take
        for(int k=1;k<=types[i][0];k++)
        {
            
            take=(take+cal(i+1 , n, types , sum+k*types[i][1] , tar, dp))%mod; 
        }
        nottake=(nottake+ cal(i+1 , n , types , sum , tar  ,dp ))%mod; 
        
        
        return dp[i][sum] =  (take+nottake)%mod; 
        
        
    }
    
    
    
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        
        
      vector<vector<int>>dp(types.size() , vector<int>(target+100 , -1)) ; 
        return cal(0 , types.size(),  types , 0 ,  target , dp  ) ;
        
        
        
    }
};
// Please Upvote