#include<iostream>

using namespace std;

int main(){
    int size = 3;
    int magicBox[size][size];

    //Filling the matrix with zeros
    for (int i = 0; i< size; i ++){
        for(int j = 0; j < size; j++){
            magicBox[i][j] = 0;
        }
    }

    int row = 0;
    int col = size / 2 ;
    //Assign values within the matrix
    for(int i = 1; i <= size * size; i ++){
        magicBox[row][col] = i;

        int oldRow = row;
        int oldCol = col;

        row--;
        col++;

        if(row < 0) row = size - 1;
        if(col >= size) col = 0;

        if (magicBox[row][col] != 0){
            row = oldRow + 1;
            col = oldCol;
        }
    }
    
    //Diplay the Matrix Box
    for(int i = 0; i< size; i++){
        for(int j = 0; j<size; j++){
            cout<<magicBox[i][j]<<"\t";
        }
        cout<<endl;
    }
    return 0;

}