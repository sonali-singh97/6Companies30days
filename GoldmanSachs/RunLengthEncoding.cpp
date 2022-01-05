/****
 Question: Run Length Encoding
 Link: https://practice.geeksforgeeks.org/problems/run-length-encoding/1/#
 ****/


string encode(string src)
{     
  int i =0, j =0;
  int len = src.length();
  string output = "";
  
  while(i < len){
     
      while(j < len && src[i] == src[j]){
         j++;
      }
      
      output += src[i] + to_string(j-i);
      i = j;
  }
  
  return output;
}    