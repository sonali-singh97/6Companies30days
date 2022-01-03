/**** Question: Subarray Product less than K
 Link : https://leetcode.com/problems/subarray-product-less-than-k/
 *****/

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        // Sliding window technique
        int i = 0, j = 0;
        int n = nums.size();
        long long prod = 1;
        int count = 0;
        
         while(j < n ){
             prod*= nums[j];
             
             // Increment i until product becomes less than K
             while(prod>= k && i < j){
                 prod /= nums[i++];
             }
             
             // Count all the subarrays starting from index i 
             if (prod < k) count+= (j-i+1);
             j++;
         }
        
        return count;
    }

};