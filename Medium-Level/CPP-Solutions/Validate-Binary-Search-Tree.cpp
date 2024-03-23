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
    bool isValidBST(TreeNode* root) {
        listSetup(root);
        for(int i = 0; i < list.size() - 1; i++)
        {
            if(list[i + 1] <= list[i]) return false;
        }
        return true;
    }
private:
    vector<int> list;
    void listSetup(TreeNode* root)
    {
        if(root->left) listSetup(root->left);
        list.push_back(root->val);
        if(root->right) listSetup(root->right);
    }
};
