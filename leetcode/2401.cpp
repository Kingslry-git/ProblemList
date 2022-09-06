class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        int cnt[40] = {0};
        for(int i = 0, j = 0,tot = 0; i < n; i ++)
        {
            for(int k = 0; k < 31; k ++)
            {
                if(nums[i] >> k & 1)
                {
                    cnt[k] ++;
                    if(cnt[k] > 1) tot ++;
                }
            }
            while(tot)
            {
                for(int k = 0;k < 31;k ++)
                {
                    if(nums[j] >> k & 1)
                    {
                        cnt[k] --;
                        if(cnt[k] == 1) tot--;//直到减掉那个cnt为2
                    }
                }
                j ++;
            }
            res = max(res, i - j + 1);
        }
        return res;
    }
};