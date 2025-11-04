#include <iostream>
#include <cassert>
/*
Exemple illustrant la récursivité du problème :

s : "abaaaaaaaa"
p : "aba*"
|
| *consommation d'une règle et des caractères correspondant, en partant de la droite*
|
 -> s : "ab"
    p : "ab"
*/


/*
Comment vérifier etoile ?
(Rappel : On analyse le pattern de droite à gauche)
exemple :
s : "aaa"
p : "aa*"
|
v

On voit le "a*" : on étend de 0 caractère, et passe à la règle suivante
    |
     -> s : "aaa"
        p : "a"
        -> faux
        |
     <-
backtrack
On étend de 1 caractère, et passe au suivant
    |
     -> s : "aa"
        p : "a"
        -> faux
        |
     <-
backtrack
On étend de 2 caractères
    |
     -> s : "a"
        p : "a"
        -> vrai !!

La récursivité est terminé : Bravo
a* + une autre règle a été vérifié :D -> Imperdable
*/

/*
Détail abusé :

// On ajoute l'indice de la chaîne S, et du pattern P
// Cette fonction concerne alors 1 caractère de S, à la position iS,
//      et 1 règle de P, à la position iP (voir iP-1 si étoile)
bool _h1IsMatch(std::string const &s, int iS, std::string const &p, int iP){

    // Si tout le pattern a été consommé :
    if(iP <= -1){
        if(iS <= -1)
            return true;// Chaque caractère et règle a été consommé -> le travail est fini
        else
            return false;// Il reste des caractères, mais il n'y a plus de règle à consommer
    }
    // Désormais, il reste au moins des règles à consommer

    // Cas simple : un caractère
    if( p[iP] != '*' ){
        // Si il n'y a plus de caractère à consommer, pas la peine d'essayer
        if(iS <= -1) return false;

        // Si le caractère est Joker : On récurse
        if(p[iP] == '.') return _h1IsMatch(s, iS-1, p, iP-1);

        // Sinon, on récurse SI le caractère est correcte
        return (p[iP] != s[iS]) ? false : _h1IsMatch(s, iS-1, p, iP-1);

        // Dans les 2 cas valide, on consomme un caractère et une règle
    }
    // Sinon, Le pattern est une étoile !!

    // Cas étoile : étudions le caractère à développer
    iP--;

    // Cas Joker à développer
    if(p[iP] == '.'){
        while(iS > -1){
            if(_h1IsMatch(s, iS, p, iP-1)) return true;
            // Si backtrack, on développe un caractère de plus
            iS--;
        }

        // Dernière chance : développement complet
        return _h1IsMatch(s, -1, p, iP-1);
    }

    // Cas où on développe un caractère particulier
        //premier cas où on développe 0 caractères
    if(_h1IsMatch(s, iS, p, iP-1)) return true;

        // On développe pour de vrai cette fois :)
    while((iS > -1) && (s[iS] == p[iP])){
        if(_h1IsMatch(s, iS-1, p, iP-1)) return true;
        // Si backtrack, On développe un caractère de plus
        iS--;
    }

    // On a tout tenté : rien n'est possible
    return false;
}
*/




bool _h1IsMatch(std::string const &s, int iS, std::string const &p, int iP){

    if(iP <= -1){
        if(iS <= -1)
            return true;
        else
            return false;
    }

    // Cas simple : un caractère
    if( p[iP] != '*' ){
        if(iS <= -1)
            return false;
        if(p[iP] == '.')
            return _h1IsMatch(s, iS-1, p, iP-1);

        return (p[iP] != s[iS]) ? false : _h1IsMatch(s, iS-1, p, iP-1);
    }

    // Cas étoile : étudions le caractère à développer
    iP--;

    // Cas Joker à développer
    if(p[iP] == '.'){
        while(iS > -1){
            if(_h1IsMatch(s, iS, p, iP-1)) return true;
            iS--;
        }
        // Dernière chance : Développement complet du Joker
        return _h1IsMatch(s, -1, p, iP-1);
    }

    // Cas développement '0' du caractère
    if(_h1IsMatch(s, iS, p, iP-1))
        return true;
    // Cas développement à au moins un caractère
    while((iS > -1) && (s[iS] == p[iP])){
        if(_h1IsMatch(s, iS-1, p, iP-1)) return true;
        iS--;
    }

    // On a tout tenté : rien n'est possible
    return false;
}

// On commence par analyser le pattern et la chaîne en commençant par la fin (plus simple si étoile).
bool isMatch(std::string const &s, std::string const &p){
    return _h1IsMatch(s, s.length()-1, p, p.length()-1);
}


int main(){
    std::cout << "Session de test :" << std::endl;
    assert( (isMatch("aa", "a")==false) && "Mot basique");
    assert( (isMatch("aa", "a*")==true) && "Expansion simple");
    assert( (isMatch("aaaa", "aa*")==true) && "Exemple perso de backtrack");
    assert( (isMatch("ab", ".*")==true) && "Expansion à Joker");

    return 0;
}
