class Solution {
public:

    // Encodes a URL to a shortened URL.
    map<string,string>map;
    
    string encode(string longUrl) {
        
        //int map
        //key will be encoded url 
        //key val will be original url
        
        string ans="http://tinyurl.com/";
        int size=map.size();
        string key=ans+to_string(size);
        
        //key->original url
        
        map.insert({key,longUrl});
        
        
        return key;//since keyis the encoded url
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        
        //map pe shortUrl ki value hi orib=ginal string hai
        return map[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));