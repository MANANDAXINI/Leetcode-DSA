class Solution {
public:
    bool helper(vector<int>& nums, int target, int i, vector<vector<int>>& dp) {
        if (i >= nums.size() || target < 0) {
            return false;
        }

        if (target == 0)
            return true;

        if (dp[target][i] != -1)
            return dp[target][i];

        bool pos = helper(nums, target - nums[i], i + 1, dp);
        bool notposs = helper(nums, target, i + 1, dp);

        dp[target][i] = pos || notposs;
        return dp[target][i];
    }

    bool tab(vector<int>&nums,int target,int i,vector<vector<int>>&dp){
        
        int n=nums.size();
        for(int col=0;col<=n;col++){
            dp[0][col]=true;
        }
        for(int t=1;t<=target;t++){
            for(int i=n-1;i>=0;i--){
                bool inc=0;
                if(t-nums[i]>=0){
               inc=dp[t-nums[i]][i+1];
                }
               bool exc=dp[t][i+1];
               dp[t][i]=inc || exc;

            }
        }

        return dp[target][0];
    }
    

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int target = accumulate(nums.begin(), nums.end(), 0);
        int sumtarget = target / 2;
        if (target % 2 != 0) {
            return false;
        }
        int i = 0;
        vector<vector<int>> dp(target + 1, vector<int>(n + 1, -1));

        return helper(nums, sumtarget, i, dp);
    }
};