class Solution {
public:

    int ans; //need external storage

    int kthSmallest(TreeNode* root, int k) {
        inorder(root,k); //ans finder
        return ans;
    }

    void inorder(TreeNode *root, int &k) { //basic inorder, update ans when k==0, pass by reference
        if(!root) return;
        inorder(root->left,k);
        k--;
        if(k==0) ans=root->val;
        inorder(root->right,k);
    }
};