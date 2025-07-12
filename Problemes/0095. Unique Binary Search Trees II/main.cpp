#include<iostream>
#include<vector>
#include<utility>

using namespace std;

struct TreeNode {
     int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
 on part d'un noeud, on créé les sous arbres possibles

 */
TreeNode* deepCopyTreeNode(TreeNode* &r){
    if(!r) return nullptr;

    return new TreeNode(r->val,
                        deepCopyTreeNode(r->left),
                        deepCopyTreeNode(r->right));
}

vector<TreeNode*> allTreeFrom2SubTreesAnd1rootValue(vector<TreeNode*>& sags, vector<TreeNode*>& sads, int v){
    int leng = sags.size();
    int lend = sads.size();

    vector<TreeNode*> res;
    if(leng <= 1){
        // Il n'y a qu'une possibilité quoi qu'il arrive pour l'arbre de gauche
        TreeNode* sag = (leng == 0) ? nullptr : sags[0] ;

        for(TreeNode* t : sads){
            res.push_back(new TreeNode(v, sag, t));
        }

    }
    else if(lend <= 1){
        // Une seule possibilité comme arbre de droite
        TreeNode* sad = (lend == 0) ? nullptr : sads[0] ;

        for(TreeNode* t : sags){
            res.push_back(new TreeNode(v, sad, t));
        }
    }
    else{

        for(TreeNode* tg : sags){
        for(TreeNode* td : sads){
            res.push_back(new TreeNode(v,
                                       deepCopyTreeNode(tg),
                                       deepCopyTreeNode(td)));
        }
        }
    }

    return res;
}

bool estRangeVide(pair<int, int> range){
    return range.first > range.second;
}

bool estRangeUnique(pair<int, int> range){
    return range.first == range.second;
}

// range étant un intervalle de range.first à range.second (tout inclus), le range est vide si range.first > range.second
vector<TreeNode*> buildBSTFromRange(pair<int, int> range){
    if(estRangeVide(range)) return {nullptr};
    if(estRangeUnique(range)) return {new TreeNode(range.first)};

    vector<TreeNode*> res;
    vector<TreeNode*> sads; // sous arbres droit
    vector<TreeNode*> sags; // sous arbres gauche

    // on prend le premier comme racine
    sads = buildBSTFromRange({range.first+1, range.second});

    for(TreeNode* t : sads){
        res.push_back(new TreeNode(range.first,
                                   nullptr,
                                   t)); // rien à gauche
    }

    // on prend les autres comme racine
    vector<TreeNode*> allTrees;
    for(int i=range.first+1; i<=range.second-1; i++){
        sags = buildBSTFromRange({range.first+1, i-1});
        sads = buildBSTFromRange({i+1, range.second-1});

        allTrees = allTreeFrom2SubTreesAnd1rootValue(sags, sads, i);

        for(TreeNode* t : allTrees){
            res.push_back(t);
        }

    }

    // on prend le dernier comme racine
    sags = buildBSTFromRange({range.first, range.second-1});
    for(TreeNode* t : sags){
        res.push_back(new TreeNode(range.second,
                                   t,
                                   nullptr));// rien à droite
    }

    return res;
}

vector<TreeNode*> generateTrees(int n) {

    return buildBSTFromRange({1,n});

}


int main(){


    std::cout << generateTrees(3).size() << std::endl;
    std::cout << generateTrees(1).size() << std::endl;

    return 0;
}
