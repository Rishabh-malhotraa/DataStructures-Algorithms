#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'tableOfContents' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts STRING_ARRAY text as parameter.
 */
 
class Headings {
public:
 string h1;
 vector<string> h2;  
};
 
void addSubs(vector<Headings> &t , vector<string> &subs) 
 {
    int last_idx = t.size() - 1;
    t[last_idx].h2 = subs;
    subs.clear();
    return; 
 }

vector<string> tableOfContents(vector<string> text) {
   
   vector<Headings> t; 
   vector<string> result;
   
   
   vector<string> subs;
   for (string &s : text)
   {
     string h1 = s.substr(0, 2);
     string h2 = s.substr(0, 3);  
     
     if( h1 == "# ")
     {
       if(subs.size() != 0)
          addSubs(t,subs);
       
       string title = s.substr(2);
       Headings temp({title, {}});
       t.push_back(temp); 
     }
     
     if( h2 == "## ")
       subs.push_back(s.substr(3)); 

   }
   addSubs(t, subs);
   
   for(int i =0 ; i< t.size() ; i++)
   {
     string idx = to_string(i+1) + ". ";
     result.push_back(idx + t[i].h1);
     
     idx.pop_back();
     
     for(int j = 0; j < t[i].h2.size(); j++)
     {
       string idx_2 = to_string(j+1) + ". ";
       result.push_back(idx + idx_2 + t[i].h2[j]);
     }
   }
   
   return result;
}
int main()