class Solution {
public:
    int count_space(string &str)
    {
        int count=0;
        
        for(auto itr:str)
        {
            if(itr==' ')count++;
        }
        return count+1;//no of spaces +1 will the number of words 
        
    }
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        
        //we will count the spaces
        vector<int>store_spaces;
        map<string,int>map;
        for(int i=0;i<messages.size();i++)
        {
            int count=count_space(messages[i]);
            store_spaces.push_back(count);
            
            map[senders[i]]+=store_spaces[i];
            
        }
        
        //now itrate in the map found the maximum and return the string correspond to it
        int count=0;
        string ans;
        
        for(auto itr:map)
        {
            if(itr.second>=count)
            {
                count=itr.second;
                ans=itr.first;
            }
        }
        return ans;
        
    }
};