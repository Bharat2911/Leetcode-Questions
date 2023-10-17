class Solution {
public:
   bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        //parent to child
        unordered_map<int,vector<int>> adj;
        //child to parent
        unordered_map<int,int> adjj;
        for(int i=0;i<n;i++){
            int node=i;
            int leftc=leftChild[i];
            int rightc=rightChild[i];
            if(leftc!=-1){
                adj[node].push_back(leftc);
                if(adjj.find(leftc)!=adjj.end()){
                    return false;
                }
                adjj[leftc]=node;
            }
            if(rightc!=-1){
                adj[node].push_back(rightc);
                if(adjj.find(rightc)!=adjj.end()){
                    return false;
                }
                adjj[rightc]=node;
            }
        }
        int root = -1;
        for(int i = 0; i<n; i++) {
            if(adjj.find(i) == adjj.end()) {
                if(root != -1){
                    return false;
                }
                else{
                    root = i;
                }
            }
        }
        if(root == -1)  return false;
        //simple bfs call
        vector<bool> vis(n,false);
        queue<int> q;
        q.push(root);
        int count=1;
        vis[root]=true;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            //parent-->child
            //u-->v
            for(auto &v:adj[u]){
                if(!vis[v]){
                    vis[v]=true;
                    count++;
                    q.push(v);
                }
            }
        }
        return count==n;
    }
};