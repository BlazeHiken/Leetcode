class Solution {
public:
    long long prev = LLONG_MIN;
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        if(!isValidBST(root->left)) return false;
        if(prev >= root->val) {
            return false;
        } else {
            prev = root->val;
        }
        if(!isValidBST(root->right)) return false;
        return true;
    }
};