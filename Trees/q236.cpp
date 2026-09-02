class Solution {
public:
    //bubble up result
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(root==p) return p; //return p if p found, this keeps getting returned when found once
        if(root==q) return q; //return q if q found
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if(left && right) { //both children return a value that means p in left and q in right or vice versa
            return root;  // therefore the root is the lca because its the first common part
        } else if(left) { // if right is null bubble up left
            return left;
        } else if(right) { //if left is null bubble up right
            return right;
        } else { //both null then return null
            return NULL;
        }
    }
};