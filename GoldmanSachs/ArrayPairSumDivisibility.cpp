/***** 
Question:
https://practice.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1#
******/

bool canPair(vector<int> nums, int k) {
        
        int len = nums.size();
        if(len%2) return false;
        
       unordered_map<int, int> remainder_count;
 
       for(int ele : nums){
           remainder_count[ele%k]++;
       }
       
       for (int ele: nums ){
           int rem = ele % k;

           if((rem == 0 || rem == k/2 ) && remainder_count[rem]%2 == 0 ) {
               continue;
           }
           else if( remainder_count[rem] == remainder_count[k-rem]){
                continue;
           }
           
           return false;    
    }
    
    return true;
}

/**** APPROACH ****

1. Brute force: O(n*n) and O(n) space
For every element find a pair whose remainder is equal to (k - arr[i]% k) and is unvisited

2. Efficient approach: Time O(n) Space O(n)
Store every remainder count in hashmap
Iterate over array to check for every element pair

****************/
