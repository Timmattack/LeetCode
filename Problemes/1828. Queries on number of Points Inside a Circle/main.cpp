#include<iostream>
#include<vector>

using namespace std;
using Point = vector<int>;
using Cercle = vector<int>;
string vectToString(vector<int>& v){
    if(v.empty()) return "[]";

    string msg = "["+to_string(v[0]);
    int len = v.size();
    for(int i=1; i<len; i++){
        msg += ", "+to_string(v[i]);
    }
    msg += "]";

    return msg;
}
int carre(int a){return a*a;}

bool isInCircle(Point p, Cercle c){
    return carre(p[0]-c[0]) + carre(p[1]-c[1]) <= c[2]*c[2];
}

vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
    vector<int> res;

    int pointsInC = 0;
    for(Cercle c : queries){
        pointsInC = 0;

        for(Point p : points){
            pointsInC += isInCircle(p, c);
        }
        res.push_back(pointsInC);
    }

    return res;
}


int main(){
    vector<Point> p1s = {{1,3},{3,3},{5,3},{2,2}};
    vector<Cercle> c1s = {{2,3,1},{4,3,1},{1,1,2}};

    vector<Point> p2s = {{1,1},{2,2},{3,3},{4,4},{5,5}};
    vector<Cercle> c2s = {{1,2,2},{2,2,2},{4,3,2},{4,3,3}};

    vector<int> res1 = countPoints(p1s, c1s);
    vector<int> res2 = countPoints(p2s, c2s);

    cout << "ex1 : " << vectToString(res1) << endl;
    cout << "ex2 : " << vectToString(res2) << endl;


    return 0;
}
