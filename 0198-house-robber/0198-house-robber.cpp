class Solution {
public:
    int robber(vector<int>&nums,int n,int i,vector<int>&dp){
        if(i>=n)return 0;


        if(dp[i]!=-1){
            return dp[i];
        }
        int inc=nums[i]+robber(nums,n,i+2,dp);
        int exc=robber(nums,n,i+1,dp);
        dp[i]=max(inc,exc);
        return dp[i];

        
    }

    int tab(vector<int>&nums,vector<int>&dp,int n,int i){
        dp[n]=0;
        dp[n+1]=0;

        for(int i=n-1;i>=0;i--){
            int inc=nums[i]+dp[i+2];
            int exc=0+dp[i+1];
            dp[i]=max(inc,exc);
        }
        return dp[i];
    }


    int rob(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        vector<int>house(n+2,-1);
       
        return tab(nums,house,n,i);
    }
};