#include<iostream>
#include<vector>

using namespace std;

string longestCommonPrefix2Words(string& w1, string& w2){
    string longestPrefix = "";
    int len = min(w1.length(), w2.length());

    int i=0;
    while( (i<len) && (w1[i] == w2[i])){
        longestPrefix += w1[i++];
    }

    return longestPrefix;
}

string longestCommonPrefix(vector<string>& strs) {
    string longestPrefix = strs[0];

    int len=strs.size();
    for(int i=1; i<len; i++){
        longestPrefix = longestCommonPrefix2Words(longestPrefix, strs[i]);
        if(longestPrefix == "")
            return "";
    }

    return longestPrefix;
}

int main(){
    vector<string> ex1 = {"flower", "flow", "flight"};
    vector<string> ex2 = {"dog", "racecar", "car"};

    string res1 = longestCommonPrefix(ex1);
    string res2 = longestCommonPrefix(ex2);

    std::cout << "ex1 : " << res1 << std::endl;
    std::cout << "ex2 : " << res2 << std::endl;

    return 0;
}
