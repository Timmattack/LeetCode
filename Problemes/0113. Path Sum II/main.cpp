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
bool isLeaf(TreeNode* root){
    if(!root) return false;
    if(!root->left && !root->right) return true;
    return false;
}

void pathSum(TreeNode* root, int targetSum, vector<vector<int>>& paths){
    if(isLeaf(root)){
        if(root->val != targetSum)// if the path is invalid, don't make it come back up
            paths = {};
        else
            paths[0].push_back(root->val);// otherwise, just add yourself :)

        return;
    }

    for(vector<int>& path : paths){
        path.push_back(root->val);// add yourself in the way
    }

    vector<vector<int>> Lpaths = paths; // make your childs know
    vector<vector<int>> Rpaths = Lpaths;

    if(root->left) pathSum(root->left, targetSum - root->val, Lpaths);
    if(root->right) pathSum(root->right, targetSum - root->val, Rpaths);

    // mix the valids paths
    for(vector<int>& lp : Lpaths){
        paths.push_back(lp);
    }
    for(vector<int>& rp : Rpaths){
        paths.push_back(rp);
    }
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    if(!root) return {};
    if(isLeaf(root) && root->val == targetSum) return {{root->val}};
    if(isLeaf(root) && root->val != targetSum) return {};

    vector<vector<int>> Lpaths = {{root->val}};
    vector<vector<int>> Rpaths = Lpaths;

    if(root->left) pathSum(root->left, targetSum - root->val, Lpaths);
    if(root->right) pathSum(root->right, targetSum - root->val, Rpaths);

    vector<vector<int>> paths;

    for(vector<int>& lp : Lpaths){
        paths.push_back(lp);
    }
    for(vector<int>& rp : Rpaths){
        paths.push_back(rp);
    }

    return paths;
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
