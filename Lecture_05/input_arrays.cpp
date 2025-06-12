#include<iostream>
#include<conio.h>

using namespace std;
void input_output(int *ptr, int arr[5]);
int main(){
    system("cls");
    int *ptr = 0, arr[5];
    cout<<"THE INPUT OUTPUT ARRAY "<<endl;
    cout<<"_______________________"<<endl;
    input_output(ptr, arr);
    getch();
    return 0;
}

void input_output(int *ptr, int arr[5]){
    ptr = arr;
    for (int i = 0; i < 5; i++){
        cout<<"Enter an integer : "<<endl;
        cin>>ptr[i];
        cout<<endl;
    }
    for (int i = 0; i<5; i++){
        cout<<"The value entered : "<<ptr[i];
        cout<<endl;
    }
}