/*
Question: Phone Directory
Link: https://practice.geeksforgeeks.org/problems/phone-directory4628/1/#
*/

class Solution{
public:
    
    class Trie {
        public:
        Trie* children[26];
        bool isLast;
        
        Trie (){
            isLast = false;
            for (int i =0; i < 26; i ++){
                children[i] = NULL;
            }
        }
        
    };
    
    void insert( Trie* root, string s){
       int len = s.length();
      Trie * node = root;
      for (int i =0; i < len ; i ++){
          int ind = s[i] - 'a';
          
          if (node->children[ind] == NULL){
              node->children[ind] = new Trie();
          }
          node = node->children[ind];
          
      }
     if (len) node -> isLast = true;
    }
    
    void displayContactsUtil(Trie* root, string pre, vector<string>& ans){
        
        if(root->isLast == true){
            ans.push_back(pre);
        }
        
        for (int i =0;i < 26; i ++){
            if(root->children[i]!=NULL) 
                displayContactsUtil(root->children[i], pre+ char(i + 'a'), ans);
        }
    }
    
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        Trie* root = new Trie();
        int len = s.length();
        vector<vector<string>> output(len);
        
        for(int i = 0; i < n; i ++){
           insert(root, contact[i]);
        }
        
        string pre = "";
        Trie* prev = root;
        int i =0;
        for (; i < len ; i ++){
            pre += s[i];
            int ind = s[i] - 'a';
            if (!prev->children[s[i] - 'a']) break;
            prev = prev->children[ind];
            displayContactsUtil(prev, pre, output[i]);

        }
        
        while(i < len){
            output[i++].push_back("0");
        }
        
        return output;
    }
};


/**** APPROACH ****
 * Time : O(|s| * n * max|contact[i]|)
 * Space: O(n) + O (n * max|contact[i]|)
 
 - Store all strings in a Trie.
 - For every prefix, print all words starting with that prefix.
 - Keep the track of trie node for every prefix just print all words from there
 - If a prefix is not present,rest of the prefix also is not present.
 ******************/