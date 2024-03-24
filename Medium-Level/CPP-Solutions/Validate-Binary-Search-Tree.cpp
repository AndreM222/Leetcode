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
        listSetup(root); // Set list and organize tree
        for(int i = 0; i < list.size() - 1; i++) // Parse through list
        {
            if(list[i + 1] <= list[i]) return false; // If index is bigger or equal to next than return false
        }

        return true; // return true if list is in order
    }
private:
    vector<int> list; // Set list of binary tree
    void listSetup(TreeNode* root) // Run in-order recursion to setup list
    {
        if(root->left) listSetup(root->left); // If left node available then traverse through it
        list.push_back(root->val); // Push current node value to list
        if(root->right) listSetup(root->right); // If right node available then traverse through it
    }
};
