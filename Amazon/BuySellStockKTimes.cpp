/*** 
 * Question: Buy ans sell Stocks atmost k times
 * Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
 ***/


class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n == 0) return 0;
        int dp[k+1][n];
        
        for (int i =0; i <=k ; i ++){
             int prevMax = INT_MIN;
            for(int j =0; j < n; j ++){
                if(i == 0 || j == 0) dp[i][j] = 0;
                 else {
                     dp[i][j] = dp[i][j-1];
                     
                     // find max of (dp[i-1][j-1] - prices[j-1])
                     prevMax = max (prevMax, dp[i-1][j-1] - prices[j-1]);
                     dp[i][j] = max(dp[i][j],  prevMax + prices[j]);
                 }
            }
        }
        
        return dp[k][n-1];
    }
};

/***** APPROACH****
Time Complexity: O(k*n)
Src: https://youtu.be/3YILP-PdEJA

- Create a DP array of (k+1)* n
- for every index
     - prevMax = maxProfit for transaction between d & j ( d = 0 to j-1)
     - value = max (dp[i][j-1] , prevMax)
- return dp[k][n-1]
*******************/