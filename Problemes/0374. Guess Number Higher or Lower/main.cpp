#include<iostream>

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

const int GO_LOWER = -1;
const int GO_UPPER = 1;

int guess(int num){return 0;}

int guessNumber(int lower, int upper){
    if(lower==upper) return lower;

    int middle = lower + (upper - lower)/2;

    int goGuess = guess(middle);

    switch(goGuess){
        case GO_LOWER:
            return guessNumber(lower, middle-1);

        case GO_UPPER:
            return guessNumber(middle+1, upper);

        default:
            return middle;
    }
}

int guessNumber(int n) {
    return guessNumber(1, n);
}


int main(){


    return 0;
}
