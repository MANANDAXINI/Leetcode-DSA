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

    int tab(vector<int>&coins,int amount,vector<int>dp){
        dp[0]=0;
       
        for(int amt=1;amt<=amount;amt++){
             int ans=INT_MAX;
            for(int i=0;i<coins.size();i++){
                int coincurrent=coins[i];

                if(coincurrent<=amt){
                    int coinsused=dp[amt-coincurrent];
                    if(coinsused!=INT_MAX){
                        int mincoins=1+coinsused;
                        ans=min(mincoins,ans);

                    }
                }
            }
            dp[amt]=ans;
        }
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int>dp(amount+1,-1);

       
        
        int ans=tab(coins,amount,dp);
        if(ans==INT_MAX){
            return -1;
        }
        return ans;

    }
};