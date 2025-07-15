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


TreeNode* sortedArrayToBST(vector<int>& nums, int left, int right){
    if(right - left == 1){
        return new TreeNode(nums[right],
                            new TreeNode(nums[left]),
                            nullptr);
    }
    if(left <= right){
        int middle = (left+right)/2;
        //std::cout << "v:" << nums[middle] << ", l:" << left << ", r:" << right << ", next:(" << left << "," << middle-1 << "),(" << middle+1 << "," << right << ")" << std::endl;
        return new TreeNode(nums[middle],
                            sortedArrayToBST(nums, left, middle-1),
                            sortedArrayToBST(nums, middle+1, right)
                            );
    }
    else return nullptr;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    if(nums.size() == 1) return new TreeNode(nums[0]);
    if(nums.size() == 2) return new TreeNode(nums[1],
                                               new TreeNode(nums[0]),
                                               nullptr);
    return sortedArrayToBST(nums, 0, nums.size()-1);
}

int main(){
    vector<int> ex1 = {-10, -3, 0, 5, 9};
    vector<int> ex2 = {1, 3};

    TreeNode* t1 = sortedArrayToBST(ex1);
    std::cout << "-----" << std::endl;
    TreeNode* t2 = sortedArrayToBST(ex2);
    std::cout << "-----" << std::endl;

    std::cout << "t1 : " << std::endl;
    printBT(t1);

    std::cout << std::endl;
    std::cout << "t2 : " << std::endl;
    printBT(t2);


    return 0;
}
