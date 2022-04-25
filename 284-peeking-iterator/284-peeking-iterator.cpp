/*
 *Below is the interface for Iterator, which is already defined for you.
 ***DO NOT**modify the interface for Iterator.
 *
 *class Iterator {
 *		struct Data;
 *		Data* data;
 *public:
 *		Iterator(const vector<int>& nums);
 *		Iterator(const Iterator& iter);
 *
 *		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator: public Iterator
{
    public: vector<int> temp;
    int ptr;
    int n;

    PeekingIterator(const vector<int> &nums): Iterator(nums)
    {
       	// Initialize any member here.
       	// **DO NOT**save a copy of nums and manipulate it directly.
       	// You should only use the Iterator interface methods.
        temp = nums;
        ptr = -1;
        n = temp.size();
    }

   	// Returns the next element in the iteration without advancing the iterator.
    int peek()
    {

        int ans = 0;

        if (ptr+1 < n)
        {
            ans = temp[ptr+1];
        }
        return ans;
    }

   	// hasNext() and next() should behave the same as in the Iterator interface.
   	// Override them if needed.
    int next()
    {

        int ans = 0;
        ptr++;
        ans = temp[ptr];

        
        return ans;
    }

    bool hasNext() const
    {
        if (ptr== n - 1)
        {
            return false;
        }
        return true;
    }
};