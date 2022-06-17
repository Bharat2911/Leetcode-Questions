/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
       	//we will be going in bottom,ups manner
       	//means we will be doing the post order traversal

       	//for each node we will be checking the four cases
       	//node has_camera
       	//node need_camers
       	//node not_needed_camera
       	//node covered

        int camera_count = 0;

    int has_camera = 0;
    int need_camera = 1;
    int not_needed_camera = 2;
    int covered = 3;

    int minCameraCover(TreeNode *root)
    {
        //base case 
        //if we only have root
        
       camera_count= solve(root)==need_camera?camera_count+1:camera_count;

        return camera_count;
    }
    int solve(TreeNode *root)
    {
        if (root == NULL)
        {
           	//no camera is needed
            return not_needed_camera;
        }
       	// checking for leaf
        if (root->left == NULL and root->right == NULL)
        {
           	//since camera will be needed in this case
            return need_camera;
        }
        //goinf in postorder manner 
        //left->right->root
        
        int left = solve(root->left);
        int right = solve(root->right);

        if (left == need_camera || right == need_camera)
        {
            camera_count++;
           	//since now the particular node will be having the camera
            return has_camera;
        }
        if (left == has_camera || right == has_camera)
        {
           	//every node is covered now 
            return covered;
        }
        return need_camera;
        
        //Time_complexity =O(n)//since we are traversing the nodes only once
        //space_complexity==log(n);
        
    }
};