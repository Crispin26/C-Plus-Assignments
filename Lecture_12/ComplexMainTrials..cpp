///Assignment 5 of 10 (A):
// Continue: Complex Example
// with all operators overloading .

//#include <iostream.h>
//#include <conio.h>

#include <iostream>
# include <conio.h>

#include <windows.h>
#include <cstdlib>  // for system()
# include <math.h>

using namespace std;

class Complex
{
  private:
	float real;
	float imag;

  public:
	Complex()
	{
		real = 0 ;
		imag = 0 ;
		cout<<"This is the default constructor"<<endl;
	}

	Complex(float n)
	{
		real = imag = n ;
		cout<<"This is the overloaded constructor, with one parameter"<<endl;
	}

	Complex(float r, float i)
	{
		real = r ;
		imag = i ;
		cout<<"This is the overloaded constructor, with two parameters"<<endl;
	}
	Complex(const Complex& c)
	{
		real = c.real ;
		imag = c.imag ;
		cout<<"This is the overloaded copy constructor"<<endl;
	}

	~Complex()
	{
		//currently does nothing, because there's no dynamic area.
		cout<<"This is the destructor"<<endl;
	}

	void setReal(float) ;
	void setImag(float) ;
	float getReal() ;
	float getImag() ;
	void print();

	// Binary operators overloading
	Complex operator+(Complex);  // c1+c2
	Complex operator-(Complex);  // c1-c2
	Complex operator+(float);     // c1+3.5
	friend Complex operator+(float, Complex); // 2.4+c1

	//The remaining operators
	Complex operator*(Complex); //
	Complex operator/(Complex);
	Complex operator!=(Complex);
	Complex operator-=(Complex);
	Complex operator*=(Complex);
	Complex operator/=(Complex);


	
	// Unary operators overloading
	Complex operator++(); //Prefix
	Complex operator++(int); //Postfix
	
	//other
	Complex operator+=(Complex); // c1+=c2 same as c1=c1+c2
	Complex operator=(Complex); 
	//OR: Complex& operator=(Complex&);
	
	//logical operators ==, !=, >, <, ... etc
	int operator==(Complex);
	operator float(); //casting operator
	// Note: No return type for the casting operator,
	// because it automatically returns the type you are casting to.


	friend ostream& operator<<(ostream& out, const Complex& c);

};

void Complex::setReal(float r)
{
	real = r ;
}

void Complex::setImag(float i)
{
	imag = i ;
}

float Complex::getReal()
{
	return real ;
}

float Complex::getImag()
{
	return imag ;
}

void Complex::print()
{
	if(imag<0)
	{
		cout<<real<<" - "<<fabs(imag)<<"i"<<endl;
	}
	else
	{
		cout<<real<<" + "<<imag<<"i"<<endl;
	}
}


Complex Complex::operator+(Complex myC)
{
	Complex result;
	result.real = real + myC.real;
	result.imag = imag + myC.imag;
	return result;
}

Complex Complex::operator-(Complex myC)
{
	Complex result;
	result.real = real - myC.real;
	result.imag = imag - myC.imag;
	return result;
}

Complex Complex::operator+(float f)
{
	Complex result;
	result.real = real + f;
	result.imag = imag;
	return result;
}

Complex operator+(float f, Complex myC) //friend function
{
	Complex result;
	result.real = f + myC.real;
	result.imag = myC.imag;
	return result;

//Hint: May also be written like this:
// return myC+f ;
}

//Prefix: ++x  : // increment then return 
Complex Complex::operator++()
{   
	real++;
	return *this;
}

//Postfix: x++ : // return then increment
Complex Complex::operator++(int)
{
	Complex temp = *this;
	real++;
	return temp;
}

int Complex::operator==(Complex myC)
{
	return ((real == myC.real) && (imag == myC.imag));
}

Complex Complex::operator+=(Complex myC)
{
	real += myC.real;
	imag += myC.imag;
	return *this;
//Hint: May also be written like this:
//		*this = *this + myC ;
//		return *this ;
}

Complex Complex::operator=(Complex myC)
{
	real = myC.real ;
	imag = myC.imag ;
	return *this ;

//Hint: May also work on references instead of a whole objects
//Complex& Complex::operator=(Complex &C)
//Note: You still DO NOT change the last line of: return *this
}

Complex::operator float()
{
	return real;
}
Complex Complex::operator*(Complex myC){
	Complex result;
	result.real = (real * myC.real) - (imag * myC.imag);
	result.imag = (real * myC.imag) + (imag * myC.real);

	return result; 
}
Complex Complex::operator/(Complex myC){
	Complex result;
	float denominator = (myC.real * myC.real) + (myC.imag * myC.imag);
	result.real = ((real * myC.real) + (imag * myC.imag)) / denominator;
	result.imag = ((imag * myC.real) - (real * myC.imag)) / denominator;
	return result;
}

	


int main()
{
	//Here, the students should try all the overloaded operators
	// by performing all sorts of mathematical operations
	// on objects, and printing the results to the screen

    system("cls"); // Optional, clears screen

    // 1. individual Complex objects
    Complex a(2, 3);
    Complex b(4, -1);
    Complex c;

    // all overloaded operators
    c = a + b;
    cout << "a + b = ";
    c.print();

    c = a - b;
    cout << "a - b = ";
    c.print();

    c = a * b;
    cout << "a * b = ";
    c.print();

    c = a / b;
    cout << "a / b = ";
    c.print();

    // 2. Creating an array of Complex objects
    Complex complexArray[3] = {
        Complex(1, 2),
        Complex(3, 4),
        Complex(5, -6)
    };

    cout << "\nArray of Complex Numbers:\n";
    for (int i = 0; i < 3; i++) {
        cout << "Complex[" << i << "] = ";
        complexArray[i].print();
    }

    // 3. Adding array elements
    Complex sum;
    for (int i = 0; i < 3; i++) {
        sum = sum + complexArray[i];
    }
    cout << "\nSum of all elements in array = ";
    sum.print();


return 0 ;
}