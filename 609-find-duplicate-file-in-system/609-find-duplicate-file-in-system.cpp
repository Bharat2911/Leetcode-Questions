#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>m;
        for(int i=0;i<paths.size();i++){
            string path=paths[i];
            
            // Split string on blank space using istringstream
            istringstream ss(path);
 
            string word; 
            string halfpath="";
            ss>>halfpath;
            while (ss >> word)
            {
                size_t f=word.find("(");
                string file_name = word.substr(0,f);
                string content = word.substr(f,word.size());
                m[content].push_back(halfpath+"/"+file_name);
            }
        }
        for(auto i=m.begin();i!=m.end();i++){
            if(i->second.size()>1){
                ans.push_back(i->second);
            }
        }
        return ans;
    }
};