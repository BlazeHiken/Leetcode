class Solution {
public:

    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        countValid(root,ans); //directly updates ans
        return ans;
    }

    vector<int> countValid(TreeNode* root, int &ans) { //returns sum of nodes and num of nodes
        if(!root) return {0,0};
        vector<int> left = countValid(root->left,ans);
        vector<int> right = countValid(root->right,ans);
        int sum = left[0]+right[0]+root->val;
        int cnt = left[1]+right[1]+1;
        if(root->val == sum/cnt) ans++;
        return {sum,cnt};
    }
};