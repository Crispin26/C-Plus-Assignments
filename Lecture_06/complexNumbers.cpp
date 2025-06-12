#include<iostream>
#include<conio.h>
#include<math.h>

using namespace std;
struct  Complex {
    float real;
    float imag;


    void setReal(float);
    void setImag(float);
    float getReal();
    float getImag();

    void init();
    void print();
};

void Complex::setReal(float r){real = r;}
float Complex::getReal(){return real;}
void Complex::setImag(float i){imag = i;}
float Complex::getImag(){ return imag;}

void Complex::print(){
    if(imag < 0){
        cout<<real<<" - "<<fabs(imag)<<"i"<<endl;
    }else{
        cout<<real<<" + "<<imag<<"i"<<endl;
    }
}
Complex add(Complex, Complex);
Complex substract(Complex, Complex);



int main(){
    system("cls");
    Complex myComplex1, myComplex2, resultComplex;
    
    myComplex1.setImag(2);
    myComplex1.setReal(7);
    myComplex2.setReal(3);
    myComplex2.setImag(4);

    resultComplex = add(myComplex1, myComplex2);
    resultComplex.print();

    resultComplex = substract(myComplex1, myComplex2);
    resultComplex.print();

    return 0;
}

Complex add(Complex c1, Complex c2){
    Complex c3;
    c3.real = c1.getReal() + c2.getReal();
    c3.imag = c1.getImag() + c2.getImag();
    return c3; 
}

Complex substract(Complex c1, Complex c2){
    Complex c3;
    c3.real = c1.getReal() - c2.getReal();
    c3.imag = c1.getImag() - c2.getImag();
    return c3; 
}

