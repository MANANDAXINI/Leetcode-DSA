class Solution {
public:
    int helper(vector<int>&nums,int n,int last,int i,vector<vector<int>>&dp){
        if(i>=n)return 0;
        
        if(dp[last+1][i]!=-1){
            return dp[last+1][i];
        }
        int curr=nums[i];
        int inclength=0;
        if(last==-1 || curr>nums[last]){
        inclength=1+helper(nums,n,i,i+1,dp);
        }
        int exclength=0+helper(nums,n,last,i+1,dp);

        dp[last+1][i]=max(inclength,exclength);
        return dp[last+1][i];
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int last=-1;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
       
        int i=0;
        return helper(nums,n,last,i,dp);

    }
};