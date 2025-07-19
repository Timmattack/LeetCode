#include<iostream>
#include<vector>
#include<set>


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


set<char> inSquare(Board &board, int line, int col){
    set<char> valInSquare;

    int iStart = 3*(line/3);
    int iEnd = iStart + 3;
    int jStart = 3*(col/3);
    int jEnd = jStart + 3;

    for(int i=iStart; i<iEnd; i++){
        for(int j=jStart; j<jEnd; j++){
            if(board[i][j] != '.') valInSquare.insert(board[i][j]);
        }
    }

    return valInSquare;
}
void keepPossibilitiesInSquare(Board &board, set<char> &possibilities, int line, int col){
    set<char> square = inSquare(board, line, col);

    for(char v : square){
        possibilities.erase(v);
    }
}
void keepPossibilitiesInCol(Board &board, set<char> &possibilities, int col){
    for(vector<char> L : board){
        if(L[col] != '.') possibilities.erase(L[col]);
    }
}
void keepPossibilitiesInLine(Board &board, set<char> &possibilities, int line){
    for(char v : board[line]){
        if(v != '.') possibilities.erase(v);
    }
}
void keepGoodPossibilities(Board &board, set<char> &possibilities, int line, int col){
    keepPossibilitiesInSquare(board, possibilities, line, col);
    keepPossibilitiesInLine(board, possibilities, line);
    keepPossibilitiesInCol(board, possibilities, col);
}

set<char> possibilitiesHere(Board& board, int line, int col){
    set<char> possibilities = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

    keepGoodPossibilities(board, possibilities, line, col);

    return possibilities;
}


bool solveSudoku(Board& board, int line, int col){
    if(line == -1 && col == -1) return true;

    set<char> possibilities = possibilitiesHere(board, line, col);

    if(possibilities.empty()) return false;

    int iNext, jNext;
    nextVoidInBoard(board, line, col, iNext, jNext);

    for(char v : possibilities){
        board[line][col] = v;
        if(solveSudoku(board, iNext, jNext)) return true;
    }

    board[line][col] = '.';

    return false;
}

void solveSudoku(Board& board) {
    if(board[0][0] == '.') solveSudoku(board, 0, 0);

    int iStart, jStart;
    nextVoidInBoard(board, 0,0, iStart, jStart);

    solveSudoku(board, iStart, jStart);
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
void _testPossibilitiesHere(Board &board, int line, int col){
    vector<char> possibilities = possibilitiesHere(board, line, col);

    for(char c : possibilities){
        std::cout << c << " ";
    }
    std::cout << std::endl;
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
