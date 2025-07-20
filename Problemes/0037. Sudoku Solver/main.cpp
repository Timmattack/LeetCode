#include<iostream>
#include<vector>
#include<bitset>
#include<array>

using namespace std;

using Board = vector<vector<char>>;

void printBoard(Board& B){
    string msg = "";
    for(int i=0; i<9; i++){
        if(i%3 == 0) msg += " ------- ------- -------\n";

        for(int j=0; j<9; j++){
            if(j%3 == 0) msg += "| ";
            msg += B[i][j];
            msg += " ";
        }
        msg += "|\n";


    }
    msg += " ------- ------- -------\n";
    cout << msg << endl;
}

using Possibles = bitset<9>;

inline int charToIndex(char c) { return c - '1'; }
inline char indexToChar(int i) { return '1' + i; }


struct BitsetIterator {
    const std::bitset<9>& bits;
    int index = 0;

    BitsetIterator(const std::bitset<9>& b) : bits(b) {
        // Positionne l'index au premier bit actif
        while (index < 9 && !bits.test(index)) ++index;
    }

    bool hasNext() const {
        return index < 9;
    }

    char next() {
        char c = '1' + index;
        ++index;
        while (index < 9 && !bits.test(index)) ++index;
        return c;
    }
};

class BoardCleaner {
public:
    static constexpr int SIZE = 9;

    vector<vector<char>> board;

    // Possibilités restantes pour chaque ligne, colonne, carré
    array<Possibles, SIZE> possiblesInLines;
    array<Possibles, SIZE> possiblesInCols;
    array<array<Possibles, 3>, 3> possiblesInSquare;

    BoardCleaner(const Board& _board)
        : board(_board)
    {
        Possibles all;
        all.set(); // tous les chiffres sont possibles au départ

        possiblesInLines.fill(all);
        possiblesInCols.fill(all);
        for (auto& row : possiblesInSquare)
            row.fill(all);

        // Supprimer les candidats déjà posés
        for (int line = 0; line < SIZE; ++line) {
            for (int col = 0; col < SIZE; ++col) {
                char c = board[line][col];
                if (c != '.') {
                    updatePossibles(line, col, c);
                }
            }
        }
    }

    Possibles getPossibilitiesInXY(int line, int col) const {
        return possiblesInLines[line]
             & possiblesInCols[col]
             & possiblesInSquare[line / 3][col / 3];
    }

    void updatePossibles(int line, int col, char value) {
        int idx = charToIndex(value);
        possiblesInLines[line].reset(idx);
        possiblesInCols[col].reset(idx);
        possiblesInSquare[line / 3][col / 3].reset(idx);
    }

    void revertPossibles(int line, int col, char value) {
        int idx = charToIndex(value);
        possiblesInLines[line].set(idx);
        possiblesInCols[col].set(idx);
        possiblesInSquare[line / 3][col / 3].set(idx);
    }

    void printPossibilities(int line, int col) const {
        Possibles c = getPossibilitiesInXY(line, col);
        cout << "Possibles for (" << line << ", " << col << "): ";
        for (int i = 0; i < 9; ++i)
            if (c[i]) cout << indexToChar(i) << ' ';
        cout << '\n';
    }
};

// return the next case which contains '.', starting after what is given
// give your variables which represent the next i/j
// -1/-1 if end of board
void nextVoidInBoard(Board& board, int iStart, int jStart, int &iNext, int &jNext){

    // search on the same line
    for(int j=jStart+1; j<9; j++){
        if(board[iStart][j] == '.'){
            iNext = iStart;
            jNext = j;
            return ;
        }
    }

    //search on next lines
    for(int i=iStart+1; i<9 ;i++){
        for(int j=0; j<9; j++){
            if(board[i][j] == '.'){
                iNext = i;
                jNext = j;
                return ;
            }
        }
    }

    iNext = -1;
    jNext = -1;
    return ;

}


bool solveSudoku(Board& board, BoardCleaner &bc, int line, int col){
    if(line == -1 && col == -1) return true;

    Possibles possibilities = bc.getPossibilitiesInXY(line ,col);

    if(possibilities.none()) return false;

    int iNext, jNext;
    nextVoidInBoard(board, line, col, iNext, jNext);

    // go through all the possibilities
    char v;
    BitsetIterator it(possibilities);
    while(it.hasNext()){
        v = it.next();

        board[line][col] = v;
        bc.updatePossibles(line, col, v);
        if(solveSudoku(board, bc, iNext, jNext)) return true;
        bc.revertPossibles(line, col, v);
    }

    board[line][col] = '.';

    return false;
}

void solveSudoku(Board& board) {
    BoardCleaner bc(board);

    int iStart, jStart;
    nextVoidInBoard(board, 0,-1, iStart, jStart);

    solveSudoku(board, bc, iStart, jStart);
}


void _testNextVoidInBoard(Board& board){
    int iNext, jNext;
    for(int iStart=0; iStart<9; iStart++){
        for(int jStart=0; jStart<9; jStart++){
            nextVoidInBoard(board, iStart, jStart, iNext,jNext);

            cout << "start(" << iStart << ", " << jStart << "): next(" << iNext << ", " << jNext << ")" << endl;
        }
    }



}
int main(){
    Board ex1 = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};

    //_testNextVoidInBoard(ex1);

    //_testPossibilitiesHere(ex1, 0,2);


    cout << "Solving ..." << endl;
    solveSudoku(ex1);

    printBoard(ex1);

    return 0;
}
