//
// Created by raz on 13/03/2022.
//
#include <iostream>
#include "mat.hpp"
#ifdef _WIN32
#else
    #include <unistd.h>
    #endif
using namespace ariel;
using namespace std;

int main(){
    //the variables
    int col;
    int row;
    char Symbol_one;
    char Symbol_two;

    //the input and the output the variables for the mat
    cout << "Enter number for the columns of the mat:" << endl;
    cin >> col;
    cout << "Enter number for the rows of the mat:" << endl;
    cin >> row;
    cout << "Enter a symbol for the mat:" << endl;
    cin >> Symbol_one;
    cout << "Enter another symbol for the mat:" << endl;
    cin >> Symbol_two;
    //send and print the mat
    cout << ariel::mat(col, row, Symbol_one, Symbol_two) << endl;

    //creation of a variety of rugs of all sizes with different symbols
    for (int i=5;i<11;i++) {
        if(i%2==0){
            i++;
        }
        for (int j = 5; j < 11; j++) {
            if(j%2==0){
                j++;
            }
            for (int k = 33; k < 126; k++) {
                for (int t = 33; t < 126; t++) {
                    cout << ariel::mat(i, j, k, t) << endl;
                    sleep(1);
                }

            }
        }
    }


    return 0;
}
