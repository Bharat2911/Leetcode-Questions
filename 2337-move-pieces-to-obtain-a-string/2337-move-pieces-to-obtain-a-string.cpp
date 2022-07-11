class Solution
{
    public:
       	//thsi 
        bool canChange(string start, string target)
        {
            
            //observation one -> 
           	//remove the spaces from both the string start and target and check whether the remainig is same or not
            string s, t;
            for (int i = 0; i < start.size(); i++)
            {
                if (start[i] != '_') s.push_back(start[i]);
                if (target[i] != '_') t.push_back(target[i]);
            }
            
            cout<<s<<" "<<t;
            if (s != t) return false;
             
            
            // observation 2->
           	//check for indexes 

            vector<int> str_l_idx;
            vector<int> tar_l_idx;

            for (int i = 0; i < start.length(); i++)
            {
                if (start[i] == 'L') str_l_idx.push_back(i);

                if (target[i] == 'L') tar_l_idx.push_back(i);
            }

           	//observation l index in str always remain greater than l index in target if not return false;

            for (int i = 0; i < str_l_idx.size(); i++)
            {
                if (str_l_idx[i] < tar_l_idx[i]) return false;
            }
            
            
            // observation 3->
           	//same apply for the right index;
            vector<int> str_r_idx;
            vector<int> tar_r_idx;

            for (int i = 0; i < start.length(); i++)
            {
                if (start[i] == 'R') str_r_idx.push_back(i);

                if (target[i] == 'R') tar_r_idx.push_back(i);
            }

            for (int i = 0; i < str_r_idx.size(); i++)
            {
                if (str_r_idx[i] > tar_r_idx[i]) return false;
            }

            return true;
        }
};