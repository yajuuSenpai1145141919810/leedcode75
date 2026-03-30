// 700. Search in a Binary Search Tree


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;  // 這邊不用管*700. Search in a Binary Search Tree
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==nullptr) return nullptr;// 因為recursion 最好先寫這 return nullptr!!!

        if(root->val==val) return root; // 中獎拉! 相同
        
        // 因為上面已經做過相同的 這邊就可以只要比左右的
        if(root->val<val) return searchBST(root->right,val);
        else{
            return searchBST(root->left,val);
        }
    }
};
