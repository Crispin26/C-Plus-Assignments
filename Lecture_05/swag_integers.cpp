#include<iostream>
#include<conio.h>

using namespace std;
void swag_function(int *x, int *y);
int main(){
    system("cls");
    int x, y;
    cout<<"THE SWAG INTEGERS "<<endl;
    cout<<"__________________"<<endl;
    cout<<"Enter the value of x : ";
    cin>>x;
    cout<<"Enter the value of y : ";
    cin>>y;
    cout<<"Before exchange : "<<endl;
    cout<<"X = "<<x<<"  "<<"Y = "<<y<<endl;
    cout<<"After exchange : "<<endl;
    swag_function(&x, &y);
    
    getch();
    return 0;
}

void swag_function(int *x, int *y){
    int z;
    z = *x;
    *x = *y;
    *y = z;
    cout<<"x = "<< *x<<"  "<<"y = "<<*y<<endl;
}