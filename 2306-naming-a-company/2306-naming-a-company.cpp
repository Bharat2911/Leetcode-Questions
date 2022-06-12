class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        
      unordered_set<string> idea_set;
        long long result = 0;
        int n = ideas.size();
        for (int i = 0; i < n; ++i) idea_set.insert(ideas[i]);
 
        vector<vector<int>> can_pair(26, vector<int>(26, 0));
        for (int i = 0; i < n; ++i) {      
            string cur = ideas[i];
            int original = cur[0] - 'a';
            for (int j = 0; j < 26; ++j) {
                cur[0] = j + 'a';
                if (idea_set.count(cur) == 0) {
                    can_pair[original][j] += 1;
                } 
            }
        }
        for (int i = 0; i < 26; ++i) {
            for (int j = i + 1; j < 26; ++j) {
                result += (can_pair[i][j] * can_pair[j][i] * 2);
            }
        }
        return result;
    
    }
};