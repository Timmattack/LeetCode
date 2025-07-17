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
void deleteTree(TreeNode* &root){
    if(root){
        deleteTree(root->left);
        deleteTree(root->right);

        delete root;
    }
}
void printBT(const std::string& prefix, const TreeNode* node, bool isLeft){
    if( node != nullptr )
    {
        std::cout << prefix;

        std::cout << (isLeft ? "├──" : "└──" );

        // print the value of the node
        std::cout << node->val << std::endl;

        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
        printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
}

void printBT(const TreeNode* node){
    printBT("", node, false);
}


vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

}


int main(){

    return 0;
}
