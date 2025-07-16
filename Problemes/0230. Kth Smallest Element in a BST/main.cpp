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

/*** ça commence ici ***/


int kthSmallest(TreeNode* root, int k) {

}


int main(){
    TreeNode* ex1 = new TreeNode(3,
                        new TreeNode(1,
                            nullptr,
                            new TreeNode(2))
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

    cout << "ex1 : " << res1 << endl;
    cout << "ex2 : " << res2 << endl;

    deleteTree(ex1);
    deleteTree(ex2);

    return 0;
}
