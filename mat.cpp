#include <string>
#include <iostream>
#include "vector"
using  namespace std;

namespace ariel{
    //the instructions we received about the assignment were that the numbers the user enter need to be odd
    bool even(int number){
        return number%2==0;
    }


    /*
     * In my program I initialized the columns and rows as a matrix for the mat, each time filling the outer frame with the first symbol
     * and then the inner frame with the second symbol, and so for sigurin for on an inner circle.
     * Finally, I transferred the matrix I created to the string that in each row of the rug would drop a row.
     */
    string mat(int col, int row, char Symbol_one,char Symbol_two ){
        //the range of every the good letters (printable) are from 33-126 -> according to test number 3
        const int bad_Symbol1=33;
        const int bad_Symbol2=126;
        //check the conditions for the numbers we got
        if(even(col) || even(row) || col<=0 || row<=0||Symbol_one<bad_Symbol1||Symbol_two<bad_Symbol1||Symbol_one>bad_Symbol2|| Symbol_two>bad_Symbol2){
               throw invalid_argument( "The value you inserted is invalid you should insert odd numbers greater than 0");}

        int columns=0;
        int rows=0;
        int cnt_col=col; // temporary variable with the columns value
        int cnt_row=row; // temporary variable with the rows value
        int i=0;  //this index was created for the location where we'd like to add the symbol
        vector< vector<int> > mat(row, vector<int> (col,0 ));//the mat we will print
        char symbol=Symbol_one; //the first symbol we want to print in the mat
        string ans;  //the string that we need to return(the mat)

        while ((columns < cnt_col) && (rows < cnt_row)){
                for (i = columns; i<cnt_col; i++){
                    mat[rows][i] =(unsigned char) symbol;} //put the symbol at the first row
                rows+=1; //now we want to move on to the next line

                for (i = rows; i<cnt_row; i++){
                    mat[i][cnt_col-1] = (unsigned char) symbol;} //put the symbol at the last column at now where we have not yet put a symbol in it
                cnt_col-=1;//after we put the symbol in the lat column we want to fill the column before the last

                if (columns < cnt_col){ //check if we have filled in the col to the end with the current symbol
                    for (i = cnt_row-1; i >= rows; --i){
                        mat[i][columns] =(unsigned char)  symbol;} //put the symbol at the first column at now where we have not yet put a symbol in it
                    columns+=1;
                }

                if (rows < cnt_row){//check if we have filled in the row to the end with the current symbol
                    for (i = cnt_col-1; i >= columns; --i){ //put the symbol at the last row at now where we have not yet put a symbol in it
                        mat[cnt_row-1][i] =(unsigned char)  symbol;}
                    cnt_row-=1;
                }

                // we will change the symbols, if so far we have added one symbol in the mat, now we will add the other
                if(symbol==Symbol_one){
                    symbol=Symbol_two;}
                else{
                    symbol=Symbol_one;}
            }
        //we need to return a string, so we will transfer the matrix we created to the string, when after each line we add "\n"
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                ans+=(unsigned char) mat[i][j];}
            ans+="\n";//we will want to drop a line every time we finish a line of the mat
        }
        return ans;
    }}

