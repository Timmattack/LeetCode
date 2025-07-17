#include<iostream>
#include<vector>

using namespace std;
bool isAllSameX(vector<vector<int>> points){
    int x = points[0][0];
    for(vector<int>& point : points){
        if(point[0] != x) return false;
    }

    return true;
}

bool isSameSlope(vector<int>& p1, vector<int> p2, vector<int> p3){
    int dy1 = p1[1] - p2[1];
    int dy2 = p2[1] - p3[1];
    int dx1 = p1[0] - p2[0];
    int dx2 = p2[0] - p3[0];

    return dy1*dx2 == dy2*dx1;
}

bool checkStraightLine(vector<vector<int>>& coordinates) {
    if(isAllSameX(coordinates)) return true;

    int len = coordinates.size();
    for(int i=0; i<len-2; i++){
        if(!isSameSlope(coordinates[i], coordinates[i+1], coordinates[i+2])) return false;
    }

    return true;
}

int main(){
    vector<vector<int>> ex1 = {{1,2},{2,3},{3,4},{4,5},{5,6},{6,7}};
    vector<vector<int>> ex2 = {{1,1},{2,2},{3,4},{4,5},{5,6},{7,7}};


    string msg1 = (checkStraightLine(ex1)) ? "isStraight" : "notStraight";
    string msg2 = (checkStraightLine(ex2)) ? "isStraight" : "notStraight";

    cout << "ex1 : " << msg1 << endl;
    cout << "ex2 : " << msg2 << endl;

    return 0;
}
