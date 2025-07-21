#include<iostream>
using namespace std;


string makeFancyString(string s) {
    int nbSameChar = 1;
    char now = '.';

    string newS = "";
    for(char c : s){
        if(c != now){
            now = c;
            nbSameChar = 1;
            newS += now;
        }
        else if(nbSameChar < 2){
            nbSameChar++;
            newS += now;
        }
    }

    return newS;
}

int main(){
    cout << makeFancyString("Leeetcode") << endl;

    return 0;
}
