// 5.1 You have the following data of an employee

// Code
// Name
// Address
// Age
// Salary
// Overtime
// Deduction

// Write a program accepts the data of an employee,
// then displays the net salary of him.
// N.B. Net Salary = Salary + Overtime – Deduction.
// Note:- Receive data to structure, then display code, name, and
// net salary of the employee.

#include<iostream>
#include<conio.h>

# define SIZE 2
using namespace std;

struct Employee
    {
        int code;
        string name;
        string adresse;
        int age;
        float salary;
        int overtime;
        float deduction;
    };
int main(){
    system("cls");
    Employee empl1[SIZE];
    for (int i = 0; i < SIZE; i++ ){
        cout<<"Employee "<<i+1<<endl;
        cout<<"_______________"<<endl;
        cin.ignore();
        cout<<"Name : ";
        getline (cin,empl1[i].name);
        cout<<"Age : ";
        cin>>empl1[i].age;
        cout<<"Code : ";
        cin>>empl1[i].code;
        cout<<"Salary : ";
        cin>>empl1[i].salary;
        cout<<"Deduction : ";
        cin>>empl1[i].deduction;
        cout<<"Overtime : ";
        cin>>empl1[i].overtime;
        cout<<endl;
    }
    float netSalary1;
    
    for(int i = 0; i < SIZE; i ++){
        netSalary1 = empl1[i].salary + empl1[i].overtime - empl1[i].deduction;
        cout<<"Employee "<<i+1<<endl;
        cout<<"_______________"<<endl;
        cout<<"The salary of "<<empl1[i].code<<". "<<empl1[i].name<<" is "<<netSalary1<<"$"<<endl;
        cout<<endl;
    }
    

    getch();
    return 0;
}