#include<iostream>
#include<vector>

using namespace std;

bool isSamePoint(vector<int>& p1, vector<int>& p2){
    return p1[0] == p2[0] && p1[1] == p2[1];
}

bool isAllDistinct(vector<vector<int>>& points){
    return !isSamePoint(points[0], points[1]) &&
        !isSamePoint(points[0], points[2]) &&
        !isSamePoint(points[1], points[2]);
}

float pente(vector<int>& p1, vector<int>& p2){
    float dy = p1[1] - p2[1];
    float dx = p1[0] - p2[0];

    return dy/dx;
}

bool isSameLine(vector<vector<int>>& points){
    if(points[0][0] == points[1][0] && points[1][0] == points[2][0]) return true;

    float ratio1 = pente(points[0], points[1]);
    float ratio2 = pente(points[1], points[2]);

    return ratio1 == ratio2;
}

bool isBoomerang(vector<vector<int>>& points) {
    if(!isAllDistinct(points)) return false;

    return !isSameLine(points);
}

int main(){

    vector<vector<int>> ex1 = {{1,1}, {2,3}, {3,2}};
    vector<vector<int>> ex2 = {{1,1}, {2,2}, {3,3}};

    string msg1 = (isBoomerang(ex1)) ? "IsBoomerang" : "NotBoomerang";
    string msg2 = (isBoomerang(ex2)) ? "IsBoomerang" : "NotBoomerang";

    std::cout << "ex1 : " << msg1 << endl;
    std::cout << "ex2 : " << msg2 << endl;

    return 0;
}
