//Assignment 5 of 10 (B):
//Stack Example: with overloading operator=

//#include <iostream.h>
//# include <conio.h>

#include <iostream>
# include <conio.h>

#include <windows.h>
#include <cstdlib>  // for system()

using namespace std;

class Stack
{
  private:
	int top ;
	int size;
	int *ptr;
	static int counter ;

  public:
	Stack()
	{
		top = 0 ;
		size = 10;
		ptr = new int[size];
		counter++ ;
		cout<<"This is the default constructor"<<endl;
	}

	Stack(int n)
	{
		top = 0;
		size = n;
		ptr = new int[size];
		counter++ ;
		cout<<"This is the overloaded constructor with one parameter"<<endl;
	}
	Stack(const Stack &n);

	~Stack()
	{
		delete[] ptr;
		counter-- ;
		cout<<"This is the destructor"<<endl;
	}

	static int getCounter()
	{
		return counter ;
	}

	//Stack(Stack &) ;
	void push(int);
	int pop();
	Stack& operator= (Stack&);
	//comment the friend fun as see the effect ...
	friend void viewContent(Stack) ;

	friend Stack concatStack(const Stack&, const Stack&);
};

//static variable initialization
int Stack::counter = 0 ;

Stack::Stack(const Stack & myStk)
{
	top = myStk.top;
	size = myStk.size;
	ptr = new int[size];
	for (int i=0 ; i<top ; i++)
	{
		ptr[i] = myStk.ptr[i];
	}
	counter++ ;
	cout<<"This is the Copy Constructor"<<endl ;
}

void Stack::push(int n)
{
	if (top == size)
	{
		cout <<"Stack is full"<<endl;
	}
	else
	{
		ptr[top] = n;
		top++;
	}
}

int Stack::pop()
{
	int retVal;

	if (top == 0)
	{
		cout <<"Stack is Empty"<<endl;
		retVal = -1 ;
	}
	else
	{
		top--;
		retVal = ptr[top];
	}
	return retVal;
}

Stack& Stack::operator= (Stack& myS)
{
	delete[] ptr;
	top = myS.top;
	size = myS.size;
	ptr = new int[size];
	for (int i = 0; i < top; i++)
	{
		ptr[i] = myS.ptr[i];
	}
	return *this;
}


void viewContent(Stack myS)
{
	//**if (!myS.isempty())
	for(int i=0 ; i<myS.top ; i++)
	{
		cout<<myS.ptr[i]<<endl ;
		//myS.ptr[i]=999999;
	}
}

// Our functiion that combines two Stack objects to create one
Stack concatStack(const Stack & s1, const Stack & s2 ){
	Stack combinedStack(s1.top + s2.top);

	//	We add all the elements of s1 to combinedStack
	for(int i = 0; i<s1.top; i++){
		combinedStack.push(s1.ptr[i]);
	}

	//
	for(int i = 0; i<s2.top; i++){
		combinedStack.push(s2.ptr[i]);
	}

	return combinedStack;
}


int main()
{
	system("cls"); //clrscr() ;
//	int num ;
	Stack s1,s2 ;
	s1.push(5);
	s1.push(10);

	s1.push(15) ;

	s2.push(90) ;	s2.push(100) ;

	Stack s3(5);
	s3.push(100) ;
	s3.push(200) ;
	Stack s4(s3);   // We don't see it in the output because we commented the copy constructor

	//viewContent(s2) ;

	//s2 = s1 ;
	//viewContent(s2) ;

	//Our Stack is now used here 
	Stack combination = concatStack(s1, s2);
	viewContent(combination);

	//cout<<Stack::getCounter() ; //OR: s1.getCounter();//but has no meaning.

	getch() ;
return 0;
}