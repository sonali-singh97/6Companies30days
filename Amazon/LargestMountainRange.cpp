/*
* Question: Largest Mountain Subarray
* Link: https://leetcode.com/problems/longest-mountain-in-array/
*/


class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int maxLength = 0;
        int n = arr.size();
        
        int i = 1;
        while(i < n){

                bool mountain = false;
                int j = i;
                
                while( j < n && arr[j-1] < arr[j]) j++;
                
                while(i!=j && j < n && arr[j-1] > arr[j]){
                    j++;
                    mountain = true;
                }
                
                if(mountain ){
                    maxLength = max(maxLength, j-i+1);
                    i = j-1;
                }
           i++;
        }
        
        return maxLength;
    }
};