#include <iostream>


using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int sumNumbers(TreeNode* root, int topVal){
    if(!root->left && !root->right) return 10*topVal + root->val;
}

int sumNumbers(TreeNode* root) {
    if(!root) return 0;
    return sumNumbers(root, 0);
}

int main(){
    return 0;
}
