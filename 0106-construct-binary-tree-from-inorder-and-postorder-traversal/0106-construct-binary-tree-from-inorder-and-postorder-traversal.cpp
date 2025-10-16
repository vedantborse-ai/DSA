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
    TreeNode* bt(vector<int>& postorder, int pStart, int pEnd, vector<int>& inorder, int inStart, int inEnd, map<int, int>& mpp){
        if(pStart>pEnd || inStart>inEnd) return NULL;
        TreeNode* root = new TreeNode(postorder[pEnd]);
        int introot=mpp[root->val];
        int numsRight = inEnd - introot;
        root->right = bt(postorder, pEnd - numsRight, pEnd - 1, inorder, introot + 1, inEnd, mpp);
        root->left = bt(postorder, pStart, pEnd - numsRight - 1, inorder, inStart, introot - 1, mpp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> mpp;
        for(int i=0; i<inorder.size(); i++) mpp[inorder[i]]=i;
        TreeNode* root = bt(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, mpp);
        return root;
    }
};