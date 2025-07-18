#include<iostream>
#include<vector>


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
void nextVoidInBoard(Board& board, int iStart, int jStart, int &iNext, int &jNext){
    if(iStart == 8){
        for(int j=jStart; j<9; j++){
            if(board[8][j] == '.'){
                iNext = 8;
                jNext = j;
                return ;
            }
        }
        iNext = -1;
        jNext = -1;
        return ;
    }

    for(int i=iStart; i<9 ;i++){
        for(int j=jStart+1; j<9; j++){
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

bool solveSudoku(Board& board, int line, int col){
    return true;
}

void solveSudoku(Board& board) {
    if(board[0][0] == '.') solveSudoku(board, 0, 0);

    int iStart, jStart;
    nextVoidInBoard(board, 0,0, iStart, jStart);

    solveSudoku(board, iStart, jStart);
}


void _testNextVoidInBoard(Board& board){
    int iNext, jNext;
    nextVoidInBoard(board, 0,0, iNext,jNext);

    cout << iNext << ", " << jNext << endl;
}
int main(){
    Board ex1 = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};

    /*
    cout << "Solving ..." << endl;
    solveSudoku(ex1);
    */

    _testNextVoidInBoard(ex1);

    printBoard(ex1);

    return 0;
}
