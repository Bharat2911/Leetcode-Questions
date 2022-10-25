class node{
    
    node* link[26];
    bool found=false;
    
    public:
    
    bool is_present(char ch)
    {
        if(link[ch-'a'])return true;
        
        return false;
    }
    void put(char ch,node*temp)
    {
        link[ch-'a']=temp;
    }
    node* move(char ch)
    {
        return link[ch-'a'];
    }
    void setend()
    {
        found=true;
    }
    bool isend()
    {
        return found;
    }
};
class Trie {
    node*root;
    
public:
    
    Trie() {
        
        root= new node();
        
    }
    
    void insert(string word) {
        
        node*temp=root;
        
        for(int i=0;i<word.length();i++)
        {
            if(!temp->is_present(word[i]))
            {
                temp->put(word[i],new node());
            }
            //move to reference true 
            temp=temp->move(word[i]);
        }
        
        
        temp->setend();
    }
    
    bool search(string word) {
        
        node*temp=root;
        
        for(int i=0;i<word.length();i++)
        {
            if(temp->is_present(word[i]))
            {
                //move to its reference trie
                temp=temp->move(word[i]);
            }
            else
            {
                return false;
            }
        }
        return temp->isend();
    }
    
    bool startsWith(string word) {
        
        node*temp=root;
        
        for(int i=0;i<word.length();i++)
        {
            if(temp->is_present(word[i]))
            {
                //move to its reference trie
                temp=temp->move(word[i]);
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */