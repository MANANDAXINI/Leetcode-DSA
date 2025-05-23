class Solution {
public:
    int helper(vector<int>&coins,int amount,int n,vector<int>&dp){

        if(amount==0){
            return 0;
        }
         int ans=INT_MAX;

         if(dp[amount]!=-1){
            return dp[amount];
         }

        for(int i=0;i<coins.size();i++){
            int coin=coins[i];
            if(coin<=amount){
                int inc=helper(coins,amount-coin,n,dp);
                if(inc!=INT_MAX){
                    int coinused=1+inc;
                    ans=min(coinused,ans);
                }

            }
            
        }
        dp[amount]= ans;
        return dp[amount];

    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int>dp(amount+1,-1);

       
        int ans=helper(coins,amount,n,dp);
        if(ans==INT_MAX){
            return -1;
        }
        return ans;

    }
};