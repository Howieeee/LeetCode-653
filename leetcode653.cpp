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
    void find_two_sum(TreeNode* node, bool& found, int val){
        if( node==NULL )
            return; 
        //cout << node->val <<  " val: " << val << endl;
        if(val < node->val){
            find_two_sum(node->left,found,val);
        }else if(val > node->val){
            find_two_sum(node->right,found,val);
        }else if(val == node->val){
            //cout << "found\n";
            found = true;
            return ;
        }
    } 
    
    bool findTarget(TreeNode* root, int k) {
        if(root->left == NULL && root->right == NULL){
            return false;
        }
        bool found = false;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                int target = k - (node->val);
                
                if(target != node->val)//如果target與 當前重複 代表不存在
                    find_two_sum(root,found,target);
                if(found)
                    return true;
                
                if(node->left)
                    q.push(node->left);
                
                if(node->right)
                    q.push(node->right);
                
            }
            
        }
        return false;
    }
};
