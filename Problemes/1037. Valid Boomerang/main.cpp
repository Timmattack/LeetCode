#include<iostream>
#include<vector>

bool isAllDistinct(vector<vector<int>>& points){

}

bool isBoomerang(vector<vector<int>>& points) {

}

int main(){

    vector<vector<int>> ex1 = {{1,1}, {2,3}, {3,2}};
    vector<vector<int>> ex2 = {{1,1}, {2,2}, {3,3}};

    std::cout << "ex1 : " << (isBoomerang(ex1)) ? "IsBoomerang" : "NotBoomerang" << endl;
    std::cout << "ex2 : " << (isBoomerang(ex2)) ? "IsBoomerang" : "NotBoomerang" << endl;

    return 0;
}
