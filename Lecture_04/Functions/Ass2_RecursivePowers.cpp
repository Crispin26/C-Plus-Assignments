#include<iostream>

using namespace std;

double RecursiveFunction(double base, int exponent){
    if (exponent == 0) return 1;

    return base * RecursiveFunction(base, exponent - 1);
}
int main(){
    double base;
    int exponent;
    cout<<"Enter the base : ";
    cin>>base;
    cout<<"Enter the exponent : ";
    cin>>exponent;
    
    cout<< base<<" ^ "<< exponent << " = "<<RecursiveFunction(base, exponent)<<endl;
    return 0;
}