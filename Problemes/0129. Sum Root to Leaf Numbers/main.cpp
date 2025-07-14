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
    int value = 10*topVal + root->val;

    if(!root->left && !root->right) return value;

    if(!root->left) return sumNumbers(root->right, value);
    if(!root->right) return sumNumbers(root->left, value);

    return sumNumbers(root->left, value) + sumNumbers(root->right, value);
}

int sumNumbers(TreeNode* root) {
    if(!root) return 0;
    return sumNumbers(root, 0);
}

int main(){
    TreeNode* r1 = new TreeNode(1,
                                new TreeNode(2),
                                new TreeNode(3));

    TreeNode* r2 = new TreeNode(4,
                     new TreeNode(0),
                     new TreeNode(9,
                       new TreeNode(5),
                       new TreeNode(1)));

    std::cout << "r1 : " << sumNumbers(r1) << std::endl;
    std::cout << "r2 : " << sumNumbers(r2) << std::endl;

    return 0;
}
