class node{
    
    public:
    
    node*link[26];
    
    bool f=false;
   
    
    bool is_present(char ch)
    {
        if(link[ch-'a'])
        {
            return true;
        }
        return false;
        
    }
    void put(char ch,node*temp)
    {
        link[ch-'a']=temp;
        
    }
    node*move(char ch)
    {
        return link[ch-'a'];
    }
    void set_end()
    {
        f=true;
    }
    bool is_end()
    {
        return f;
    }
};
class WordDictionary {
    
    // node*root;
    
public:
    WordDictionary() {
        
        root=new node();
        
    }
    
    void addWord(string word) {
        node*temp=root;
        
        for(auto itr:word)
        {
            if(!temp->is_present(itr))
            {
                //put kar do
                temp->put(itr,new node());
            }
            temp=temp->move(itr);
        }
        temp->set_end();
    }
    
    bool search(string word) {
        
        //for each postion we have two options either we will have dot or we will have character
        
        int idx=0;
        
        return solve(word,idx,root);
    }
    
    private:
     node*root;
    
    bool solve(string word,int idx,node*temp)
    {
        if(idx==word.length())
        {
            return temp->is_end();
        }
        
        if(word[idx]!='.')
        {
            //move to the reference trie
            temp=temp->move(word[idx]);
            
            return temp and solve(word,idx+1,temp);
        }
        else
        {
            //when we have dot then try all possible character from a to z
            for(int i=0;i<26;i++)
            {
                
                if(temp->link[i] and solve(word,idx+1,temp->link[i]))return true;
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */