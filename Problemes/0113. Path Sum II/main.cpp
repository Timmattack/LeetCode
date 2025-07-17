#include<iostream>
#include<vector>

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
    return {};
}


string stringVec(vector<int> v){
    if(v.empty()) return "[]";
    int len = v.size();
    string msg = "[";
    msg += to_string(v[0]);
    for(int i=1; i<len; i++){
        msg += ", " + to_string(v[i]);
    }
    msg += "]";

    return msg;
}
void exFormat(int nb, TreeNode* root, int targetSum){
    cout << "----- -----" << endl;
    cout << "ex" << nb << ": " << endl;
    printBT(root);
    vector<vector<int>> res = pathSum(root, targetSum);

    if(res.empty()){
        cout << "[]" << endl;
        return ;
    }

    string msg = "[\n";
    int paths = res.size();
    msg += " "+stringVec(res[0]);
    for(int i=1; i<paths; i++){
        msg += " , "+stringVec(res[i]);
    }
    msg += "]";

    cout << msg << endl;
}
int main(){
    TreeNode* ex1 = new TreeNode(5,
                        new TreeNode(4,
                            new TreeNode(11,
                                new TreeNode(7),
                                new TreeNode(2)
                            ),
                            nullptr),
                        new TreeNode(8,
                            new TreeNode(13),
                            new TreeNode(4,
                                new TreeNode(5),
                                new TreeNode(1)
                            )
                        )
                    );
    TreeNode* ex2 = new TreeNode(1,
                        new TreeNode(2),
                        new TreeNode(3)
                    );

    TreeNode* ex3 = nullptr;

    exFormat(1, ex1, 22);
    exFormat(2, ex2, 5);
    exFormat(3, ex3, 0);

    return 0;
}
