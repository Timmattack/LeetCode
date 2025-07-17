#include<iostream>

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


/*** ça commence ici ***/
/*
 Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.
 */


// 0 <= node.val
int kthSmallest(TreeNode* root, int k) {
    if(!root) return -1;

    int Lmin = kthSmallest(root->left, k);
    if(Lmin >= 0) return Lmin;

    if(k+Lmin == 0) return root->val;

    int Rmin = kthSmallest(root->right, k+Lmin);
    if(Rmin >= 0) return Rmin;

    if(k+Rmin == 0) return root->val;

    return Lmin+Rmin;
}


int main(){
    TreeNode* ex1 = new TreeNode(3,
                        new TreeNode(1,
                            nullptr,
                            new TreeNode(2)
                            ),
                        new TreeNode(4)
                    );

    TreeNode* ex2 = new TreeNode(5,
                        new TreeNode(3,
                            new TreeNode(2,
                                new TreeNode(1),
                                nullptr
                                ),
                            new TreeNode(4)
                        ),
                        new TreeNode(6)
                    );

    int res1 = kthSmallest(ex1, 1);
    int res2 = kthSmallest(ex2, 3);

    cout << "ex1 : " << endl;
    printBT(ex1);
    cout << "res : " << res1 << endl;
    cout << "-----" << endl;
    cout << "ex2 : " << res2 << endl;
    printBT(ex2);


    deleteTree(ex1);
    deleteTree(ex2);

    return 0;
}
