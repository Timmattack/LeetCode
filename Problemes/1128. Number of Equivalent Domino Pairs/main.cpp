#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
using Dominoe = vector<int>;

struct DominoeHash {
    std::size_t operator()(const std::vector<int>& v) const {
        // On suppose que v.size() == 2
        int a = std::min(v[0], v[1]);
        int b = std::max(v[0], v[1]);

        return std::hash<int>()(a) ^ std::hash<int>()(b << 1);
    }
};

struct DominoeEqual {
    bool operator()(const std::vector<int>& a, const std::vector<int>& b) const {
        return (a[0] == b[0] && a[1] == b[1]) ||
               (a[0] == b[1] && a[1] == b[0]);
    }
};

bool mapContains(Dominoe& d, unordered_map<Dominoe, int, DominoeHash, DominoeEqual>& mapDominoes){
    return mapDominoes.find(d) != mapDominoes.end();
}

int distinctPairsNPoints(int n){
    if(n <= 1) return 0;
    return distinctPairsNPoints(n-1) + n-1;
}

int distinctPairsNPointsDirect(int n){
    if(n <= 1)
        return 0;
    return (n*(n+1))/2 - n;
}

int numEquivDominoPairs(vector<Dominoe>& dominoes) {
    unordered_map<Dominoe, int, DominoeHash, DominoeEqual> mapDominoes;

    for(Dominoe d : dominoes){
        if(mapContains(d, mapDominoes)){
            mapDominoes.find(d)->second++;
        }
        else{
            mapDominoes.insert({d, 1});
        }
    }

    int nbPairesDistinctes = 0;
    for(auto i: mapDominoes){
        std::cout << "[" << i.first[0] << "," << i.first[1] << "] : " << i.second << std::endl;
        nbPairesDistinctes += distinctPairsNPointsDirect(i.second);
    }

    return nbPairesDistinctes;
}

int main(){
    vector<Dominoe> ex1 = {{1,2},{2,1},{3,4},{5,6}};
    vector<Dominoe> ex2 = {{1,2},{1,2},{1,1},{1,2},{2,2}};

    int res1 = numEquivDominoPairs(ex1);
    std::cout << "-----" << std::endl;
    int res2 = numEquivDominoPairs(ex2);

    std::cout << "Le premier exemple a : " << res1 << " paires distinctes" << std::endl;
    std::cout << "Le deuxième exemple a : " << res2 << " paires distinctes" << std::endl;

    return 0;
}
