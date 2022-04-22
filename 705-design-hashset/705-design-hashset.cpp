class MyHashSet
{
    public:
       	//two approach we will use 
       	//ist approach ->time optimised (take an array of size 1e6+1) take bhot saari space
       	//2nd approach ->space optmised (make a vector list type of size 10)

        vector<list < int>> set;
    int size = 10;

    MyHashSet()
    {

        set.resize(size);
    }

   	//make a function that find index for us whereto add key
    int find_idx(int key)
    {
        int i = key % size;

        return i;
    }
    bool search(int key)
    {
        int i = find_idx(key);

       	//using the stl function of list
        std::list<int>::iterator itr = std::find(set[i].begin(), set[i].end(), key);

       	//if itr not reach end of the vector means we get the key 
        if (itr != set[i].end())
        {
            return true;
        }
        return false;
    }
    void add(int key)
    {

       	//if key i not present in list then we will insert it int the index 
        int i = find_idx(key);

        if (!search(key))
        {
            set[i].push_back(key);
        }
    }

    void remove(int key)
    {

       	//if key is present then only we will remove it
        int i = find_idx(key);

        if (search(key))
        {
            set[i].remove(key);
        }
    }

    bool contains(int key)
    {

        return search(key);
    }
};

/**
 *Your MyHashSet object will be instantiated and called as such:
 *MyHashSet* obj = new MyHashSet();
 *obj->add(key);
 *obj->remove(key);
 *bool param_3 = obj->contains(key);
 */