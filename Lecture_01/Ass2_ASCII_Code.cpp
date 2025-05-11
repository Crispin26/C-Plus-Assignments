#include<iostream>

using namespace std;
//Our Program Display ASCII code for a given character.
int main(void){
    char character;
    cout<<"Write a character : ";
    cin>>character;
    cout<<"The ASCII code of ["<<character<<"]"<<" is : "<<static_cast<int>(character)<<endl;
    return 0;
}
