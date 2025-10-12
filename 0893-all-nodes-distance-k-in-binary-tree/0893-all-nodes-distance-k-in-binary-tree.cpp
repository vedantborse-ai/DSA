/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void fun(TreeNode* root, unordered_map<TreeNode* , TreeNode*> &parent, TreeNode* target){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr= q.front();
            q.pop();
            if(curr->left){
                parent[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right){
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        fun(root, parent, target);
        unordered_map<TreeNode* , bool> visit;
        queue<TreeNode*> q;
        q.push(target);
        visit[target]=true;
        int curr=0;
        while(!q.empty()){
            if(curr==k) break;
            int size=q.size();
            for(int i=0; i<size; i++){
                TreeNode* current=q.front();
                q.pop();
                if(current->left && !visit[current->left]){
                    visit[current->left]=true;
                    q.push(current->left);
                }
                if(current->right && !visit[current->right]){
                    visit[current->right]=true;
                    q.push(current->right);
                }
                if(parent[current] && !visit[parent[current]]){
                    q.push(parent[current]);
                    visit[parent[current]]=true;
                }
            }
            curr++;
        }
        vector<int> result;
        while(!q.empty()){
            result.push_back(q.front()->val);
            q.pop();
        }
        return result;
    }
};