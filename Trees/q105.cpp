class Solution {
public:
    int preIndex = 0;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> posi;
        for(int i=0; i<inorder.size(); i++) {
            posi[inorder[i]] = i;
        }
        return build(0,inorder.size()-1, preorder, posi);
    }

    TreeNode* build(int inStart, int inEnd, vector<int>& preorder, unordered_map<int,int> &posi) {
        if(inStart>inEnd) return NULL;
        int val = preorder[preIndex++];
        TreeNode *newNode = new TreeNode(val);
        int mid = posi[val];
        newNode->left = build(inStart,mid-1,preorder,posi);
        newNode->right = build(mid+1,inEnd,preorder,posi);
        return newNode;
    }
};