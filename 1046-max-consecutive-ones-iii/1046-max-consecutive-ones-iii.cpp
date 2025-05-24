class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        while(j<nums.size()){
            int zerocnt=0;
            if(nums[j]==0){
                zerocnt++;
                k--;
            }

            if(k<0){
                if(nums[i]==0){
                    k++;
                }
                i++;
            }
            j++;
        }
        return (j-i);
    }
};