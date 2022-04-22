class MyHashSet
{
    public:
       	//two approach we will use 
       	//ist approach ->time optimised
       	//2nd approach ->space optmised

        vector<bool> set;

    MyHashSet()
    {

        set.resize(1000000 + 1);
    }

    void add(int key)
    {

        set[key] = true;
    }

    void remove(int key)
    {

        set[key] = false;
    }

    bool contains(int key)
    {
        return set[key];
    }
};

/**
 *Your MyHashSet object will be instantiated and called as such:
 *MyHashSet* obj = new MyHashSet();
 *obj->add(key);
 *obj->remove(key);
 *bool param_3 = obj->contains(key);
 */