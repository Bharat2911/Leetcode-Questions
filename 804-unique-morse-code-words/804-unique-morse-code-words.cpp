class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        
        unordered_map<char,string>map;
        
        map.insert({'a',".-"});
        map.insert({'b',"-..."});
        map.insert({'c',"-.-."});
        map.insert({'d',"-.."});
        map.insert({'e',"."});
        map.insert({'f',"..-."});
        map.insert({'g',"--."});
        map.insert({'h',"...."});
        map.insert({'i',".."});
        map.insert({'j',".---"});
        map.insert({'k',"-.-"});
        map.insert({'l',".-.."});
        map.insert({'m',"--"});
        map.insert({'n',"-."});
        map.insert({'o',"---"});
        map.insert({'p',".--."});
        map.insert({'q',"--.-"});
        map.insert({'r',".-."});
        map.insert({'s',"..."});
        map.insert({'t',"-"});
        map.insert({'u',"..-"});
        map.insert({'v',"...-"});
        map.insert({'w',".--"});
        map.insert({'x',"-..-"});
        map.insert({'y',"-.--"});
        map.insert({'z',"--.."});
        
        set<string>set;
        
        for(auto itr:words)
        {
            string str="";
            
            for(int i=0;i<itr.length();i++)
            {
                str+=map[itr[i]];
            }
            set.insert(str);
        }
        return set.size();
    }
};