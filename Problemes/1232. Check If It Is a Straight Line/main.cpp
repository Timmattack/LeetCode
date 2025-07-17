#include<iostream>
#include<vector>

using namespace std;

bool checkStraightLine(vector<vector<int>>& coordinates) {

}



int main(){
    vector<vector<int>> ex1 = {{1,2},{2,3},{3,4},{4,5},{5,6},{6,7}}
    vector<vector<int>> ex2 = {{1,1},{2,2},{3,4},{4,5},{5,6},{7,7}}


    string msg1 = (checkStraightLine(ex1)) ? : "isStraight" : "notStraight";
    string msg2 = (checkStraightLine(ex2)) ? : "isStraight" : "notStraight";

    cout << "ex1 : " << msg1 << endl;
    cout << "ex2 : " << msg2 << endl;


    return 0;
}
