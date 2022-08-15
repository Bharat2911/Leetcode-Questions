class Solution
{
    public:
    bool differ_by_one(string &str,string &ptr)
    {
        int count=0;
        
        for(int i=0;i<str.length();i++)
        {
            if(str[i]!=ptr[i])
            {
                count++;
            }
        }
        if(count==1)return true;
        return false;
        
    }
        int ladderLength(string beginWord, string endWord, vector<string> &wordList)
        {

           	//i want to make the adj list and i will make in using the map
            unordered_map<string, vector < string>> adj;

           	//will itrate in the word list and fill the map
            int n = wordList.size();

            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (differ_by_one(wordList[i], wordList[j]))
                    {
                        adj[wordList[i]].push_back(wordList[j]);
                        adj[wordList[j]].push_back(wordList[i]);
                    }
                }
            }
           	//we also have to add beginWord into our adj list
            for (int i = 0; i < n; i++)
            {
                if (differ_by_one(beginWord, wordList[i]))
                {
                    adj[beginWord].push_back(wordList[i]);
                    adj[wordList[i]].push_back(beginWord);
                }
            }

           	//now we will do the bsf and find the min distance between beginWord and endWord

            set<string> vis;

            queue<pair<string, int>> q;

            q.push({ beginWord,
                1 });

            vis.insert(beginWord);

            while (!q.empty())
            {
                string str = q.front().first;
                int level = q.front().second;
                q.pop();

               	//itrate in the adj list
                for (auto itr: adj[str])
                {
                   	// adjacent node is not present in visited vector then we can move further
                    if (vis.find(itr) == vis.end())
                    {
                        vis.insert(itr);
                        
                        q.push({itr,level + 1});
                    }
                    if(itr==endWord)
                    {
                        return level+1;
                    }
                }
            }
            return 0;
        }
};