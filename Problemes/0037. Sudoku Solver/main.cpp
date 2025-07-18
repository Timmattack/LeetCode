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


bool solveSudoku(Board& board, int line, int col){

}

void solveSudoku(vector<vector<char>>& board) {
    if(solveSudoku(board, 0, 0)){
        return;
    }
}


int main(){
    Board ex1 = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};



    printBoard(ex1);

    return 0;
}
