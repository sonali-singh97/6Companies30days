/***
Group Anagrams using Tries
Link: https://practice.geeksforgeeks.org/problems/print-anagrams-together/1/#
****/


class Solution{
  public:
  class Trie {
      public:
      bool isLast;
      vector<int> indexes;
      Trie* child[26];
      
      Trie(){
          isLast = false;
          for (int i =0; i < 26; i++){
              child[i] = NULL;
          }
      }
      
  };
  
  void insert (Trie* root , string s, int in){
      int len = s.length();
      Trie* curr = root;
      for (int i =0; i < len; i ++){
          int ind = s[i]-'a';
          if(curr->child[ind] == NULL){
              curr -> child[ind] = new Trie();
          }
          curr = curr->child[ind];
      }
      
      if (len != 0) {
          curr -> isLast = true;
          curr-> indexes.push_back(in);
      }
  }
  
  void groupAnagrams (Trie* root, vector<vector<string>>& ans,vector<string>& string_list ){
      if (root == NULL) return;
      
      if (root -> isLast){
          vector<string> grp;
          for (auto it : root->indexes){
              grp.push_back(string_list[it]);
          }
          ans.push_back(grp);
      }
      for (int i =0; i < 26; i ++)
        groupAnagrams(root->child[i], ans , string_list);
  }
  
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        int len = string_list.size();
        Trie* root = new Trie();
        for ( int i =0; i < len ; i ++){
            string s = string_list[i];
            sort(s.begin(), s.end());
            insert(root, s, i);
        }
        
        vector<vector<string>> ans;
        
        groupAnagrams(root, ans, string_list );
        return ans;
    }
};


/****** APPROACH ******
 Time Complexity :  O(N*S*log(S))
 - Create an empty Trie
 - Loop over the input array, for every index
        - Sort the string
        - Insert the sorted string in Trie
        - Store the index of the string at the end of each word in Trie
 - Traverse the Trie and and in case of a leaf node, traverse the index list as well and push all the indexes in Output array.

 *********************/