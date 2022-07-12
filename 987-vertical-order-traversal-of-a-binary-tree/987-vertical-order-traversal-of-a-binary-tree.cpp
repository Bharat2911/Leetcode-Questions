/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
          vector<vector<int>> ans;
							//  x    y
	queue<pair<TreeNode*, pair<int, int>>> q;
	  // x        y      // nodes
	map<int, map<int, multiset<int>>> m;

	q.push({root, {0, 0}});
	while(!q.empty()) {
		auto curr = q.front();
		q.pop();

		TreeNode* currNode = curr.first;
		int x = curr.second.first;
		int y = curr.second.second;

		m[x][y].insert(currNode->val);

		if (currNode->left)
			q.push({currNode->left, {x-1, y+1}});
		if (currNode->right)
			q.push({currNode->right, {x+1, y+1}});
	}

	for (auto i: m) {
		vector<int> v;
		for (auto j: i.second)
			for (auto k: j.second)
				v.push_back(k);
		ans.push_back(v);
	}

	return ans;
    }
};