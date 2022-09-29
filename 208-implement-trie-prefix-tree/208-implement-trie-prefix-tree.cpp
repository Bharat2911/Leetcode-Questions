struct node{
    
    node*link[26];
    
    bool f=false;
    
    bool present(char ch)
    {
        if(link[ch-'a'])return true;
        
        return false;
    }
    void put(char ch,node*temp)
    {
        link[ch-'a']=temp;
        
    }
    
    
    node*get(char ch)
    {
        return link[ch-'a'];
    }
    void setend()
    {
        f=true;
    }
    bool isend()
    {
        return f;
    }
};

class Trie {
    
   node*root;
    
public:
    Trie() {
        
        root=new node();
        
    }
    
    void insert(string word) {
        
        node * temp=root;
        
        for(int i=0;i<word.length();i++)
        {
            if(!temp->present(word[i]))
            {
                //if elemnt is not present than ye elemne ko trie me daal dega
                
                temp->put(word[i],new node());
            }
            //move to the reference trie
            
            temp=temp->get(word[i]);
        }
        //once the word got fineshed 
        temp->setend();
    }
    
    bool search(string word) {
        
        node*temp=root;
        
        for(int i=0;i<word.length();i++)
        {
            if(!temp->present(word[i]))
            {
                return false;
            }
            //if present move to its refernce trie
            temp=temp->get(word[i]);
        }
        return temp->isend();
    }
    
    bool startsWith(string word) {
         node*temp=root;
        
        for(int i=0;i<word.length();i++)
        {
            if(!temp->present(word[i]))
            {
                return false;
            }
            //if present move to its refernce trie
            temp=temp->get(word[i]);
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