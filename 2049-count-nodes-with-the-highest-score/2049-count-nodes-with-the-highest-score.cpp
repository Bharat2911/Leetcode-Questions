class Solution {
public:
    int solve(TreeNode*root,vector<long long>&arr,int total_nodes)
    {
        if(root==NULL)
        {
            return 0;
        }
        
       long long  count=1;
        
        int left=solve(root->left,arr,total_nodes);
        
        int right=solve(root->right,arr,total_nodes);
        
        int x=total_nodes-(left+right+1);
        
        if(left>0)
        {
            count=count*left;
        }
        if(right>0)
        {
            count=count*right;
        }
        if(x>0)
        {
            count=count*x;
        }
        arr.push_back(count);
        
        return left+right+1;
    }
    int countHighestScoreNodes(vector<int>& parents) {
        
        int total_nodes=parents.size();
        
        vector<long long>arr;
       TreeNode* root;
        vector<TreeNode*> temp(parents.size());
        for(int i = 0; i < temp.size(); i++)
        {
            temp[i] = new TreeNode(i);
        }
        for(int i = 1; i < temp.size(); i++)
        {
            if(temp[parents[i]]->left) temp[parents[i]]->right = temp[i];
            else temp[parents[i]]->left = temp[i];
        }
        root = temp[0];
        
        solve(root,arr,total_nodes);
        
        
        long long maxi=arr[0];
        
        for(auto itr:arr)
        {
            maxi=max(maxi,itr);
            cout<<itr<<" ";
        }
        
        long long count=0;
        
        for(auto itr:arr)
        {
            if(itr==maxi)
            {
                count++;
            }
        }
        
        return count;
        
    }
};