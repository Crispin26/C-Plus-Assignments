#include<iostream>

using namespace std;
struct Employee
{
    string name;
    int age;
    float salary;
};

//Function to create a new employee 
Employee NewEmployee(){
    Employee emp;
    cin.ignore(); //To fix buffer issuess
    cout<< "Enter Employee name : ";
    getline(cin,emp.name); //Allows full name input

    cout<< "Enter Age : ";
    cin>> emp.age;

    cout<<"Enter Salary : ";
    cin>>emp.salary;

    return emp; //We return the structure with filled details
}

//Function to display employee details
void DisplayEmployee(Employee emp){
    cout<<"\nEmployee Details\n";
    cout<< "Name : "<<emp.name<<endl;
    cout<< "Age : "<<emp.age<<endl;
    cout<< "Salary : "<<emp.salary<<endl;
}

int main(){
    Employee emp = NewEmployee();
    DisplayEmployee(emp);
    return 0;
}
