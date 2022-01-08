/***
 Question: Nuts and Bolts
 Link: https://practice.geeksforgeeks.org/problems/nuts-and-bolts-problem0431/1#
 ****/


class Solution{
public:	
    int partition(char arr[], int low, int high, char pivot){
        int i = low; // right pivot position
       for (int j =low;j <high; j++){
           if(arr[j]  < pivot){
               // if curr element is smaller than pivot then store at index i and increment i
               swap(arr[i], arr[j]);
                i++;
           }
           else if(arr[j] == pivot){
               // store the pivot element at last index
               swap(arr[j], arr[high]);
               j--;
           }
       }
       
       swap(arr[i], arr[high]);
       return i;
       
    }
    
    void matchPairsUtil(char nuts[], char bolts[], int low, int high){
        
        if(low < high){
            int pivot = partition(nuts, low, high, bolts[high]);
            
            partition(bolts, low, high, nuts[pivot]);
            
            matchPairsUtil(nuts, bolts, low, pivot-1);
            matchPairsUtil(nuts, bolts, pivot+1, high);
        }
    }
    
	void matchPairs(char nuts[], char bolts[], int n) {
	    
	    matchPairsUtil(nuts, bolts, 0, n-1);
	}
	
};

	/***** APPROACH *****
	 Time Complexity: 2*O(nlogn) ~ O(nlogn)
	 - Use Quick sort to sort both the array simultaneously
	 
	 ********************/