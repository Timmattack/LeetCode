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


int minCameraCover(TreeNode* root, bool topHasCamera){

}

int minCameraCover(TreeNode* root) {
    return minCameraCover(root, false);
}

int main(){
    TreeNode* ex1 = new TreeNode(0,
                        new TreeNode(0,
                            new TreeNode(0),
                            new TreeNode(0)
                                    ),
                        nullptr);

    TreeNode* ex2 = new TreeNode(0,
                        new TreeNode(0,
                            new TreeNode(0,
                                new TreeNode(0,
                                    nullptr,
                                    new TreeNode(0)
                                            ),
                                nullptr),
                            nullptr),
                        nullptr);

    int res1 = minCameraCover(ex1);
    int res2 = minCameraCover(ex2);

    cout << "ex1 : " << res1 << endl;
    cout << "ex2 : " << res2 << endl;

    return 0;
}
