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
    Employee empl1;
    for (int i = 1; i <=1; i++ ){
        cout<<"Enter the name of the employee : ";
        cin>>empl1.name;
        cout<<"Enter the age : ";
        cin>>empl1.age;
        cout<<"Enter the code : ";
        cin>>empl1.code;
        cout<<"Enter the salary : ";
        cin>>empl1.salary;
        cout<<"Enter the deduction : ";
        cin>>empl1.deduction;
        cout<<"Enter the overtime : ";
        cin>>empl1.overtime;
    }
    int netSalary1;
    netSalary1 = empl1.salary + empl1.overtime - empl1.deduction;
    cout<<"The salary of "<<empl1.code<<". "<<empl1.name<<" is "<<netSalary1<<"$"<<endl;

    getch();
    return 0;
}