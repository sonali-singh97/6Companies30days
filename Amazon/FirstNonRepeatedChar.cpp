/****
 * Question: First non-repeating character in a stream
 * Link: https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1#
 ****/


class Solution {
	public:
	    class Lnode {
	        public:
	        char ch;
	        Lnode* prev ; 
	        Lnode* next ;
	        
	        Lnode(char ch){
	            this -> ch = ch;
	            prev = NULL;
	            next = NULL;
	        }
	    };
	    
	    void addNode(Lnode** head, Lnode** tail, char ch){
	        Lnode* temp = new Lnode(ch);
	        if(*head == NULL){
	            *head = temp;
	            *tail = temp;
	            return;
	        }
	            
	       (*tail)->next = temp;
	       temp -> prev = *tail;
	       *tail = temp;

	    }
	    
	    void removeNode(Lnode** head, Lnode** tail, Lnode* addr){
	        Lnode* prevNode = addr-> prev;
	        Lnode* nextNode = addr -> next;
	        
	        if(*head == addr ) *head = nextNode;
	        if(*tail == addr)  *tail = prevNode;
	     
	         if(prevNode) prevNode-> next = nextNode;
	         if(nextNode)  nextNode-> prev = prevNode;
	     
	        delete(addr);
	    }
	    
		string FirstNonRepeating(string A){
		   int n = A.size();
		   string output = "";
		   if(n == 0) return output;
		   
		   Lnode* head = NULL;
		   Lnode* tail = NULL;
		   
		   vector<Lnode*> nodeAdd(26, NULL);
		   vector<bool> seen(26);
		   
		   for ( int i = 0; i < n; i ++){
		       int ind = A[i] - 'a';
		       if(!seen[ind] && !nodeAdd[ind]){
		          addNode(&head, &tail, A[i]);
		          nodeAdd[ind] = tail;
		       }
		       else if(!seen[ind] && nodeAdd[ind]){
		           removeNode(&head, &tail, nodeAdd[ind]);
		           nodeAdd[ind] = NULL;
		           seen[ind] = true;
		       }
		       
		       if(head!=NULL) output+= head->ch;
		       else output+= "#";
		       
		   }
		   
		   return output;
		   
		}
		
		/***** APPROACH ****
		Time : O(n)
		space: O(26)
		
		Using array instead of DLL, Time : O(26*n)
		
		- Create a doubly linked list to store non- repeated characters
		- Create an array to store address of char and another array to mark visited chars.
		- if(!seen[ch] && !addr[ch]) 
		        addNode(ch)
		        store address in addr array
		- else if(!seen[ch] && addr[ch])
		        deleteNode(ch)
		        remove address drom addr array
		        seen[ch] = true
		- head of DLL contains first non-repeated character till that index
		
		********************/

};