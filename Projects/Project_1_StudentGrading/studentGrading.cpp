// Project 1 (Week 5): Student Grading System using Arrays. (per person;
// documenting: Requirement/Design/Coding/...)

#include<iostream>
#include<conio.h>
using namespace std;
#define NUM_STUDENTS 2
#define NUM_COURSES 5
struct Student{
    string name;
    int id;
    int courses [NUM_STUDENTS]; // Assuming 5 subjects
};
struct Course{
    float attendance;
    float assignment;
    float midterm;
    float finalExam;
    float bonusMarks;
    float totalMarks;
    float totalCourseMarks;
    float percentage; // Assuming each course is out of 100
};
int main(){
    system("cls");
    Student students[NUM_STUDENTS];
    Course courses[NUM_COURSES];
    cout<<"STUDENT GRADING SYSTEM BSC SPRING 2025"<<endl;
    cout<<"_______________________________________"<<endl;
    int choice;
    while(true){
        cout<<endl;
        cout<<"Menu:"<<endl;
        cout<<"---------------------------------------"<<endl;
        cout<<"1. Add Student"<<endl;
        cout<<"2. Show result for students"<<endl;
        cout<<"3. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"Adding a new student..."<<endl;
                // Code to add a student would go here
                for(int i=0; i<NUM_STUDENTS; i++){
                    cin.ignore(); // Clear the input buffer
                    cout<<"Student "<<i+1<<": "<<endl;
                    cout<<"Name: ";
                    getline(cin, students[i].name);
                    cout<<"ID: ";
                    cin>>students[i].id;
                    cout<<"Enter mark for attendance : ";
                    cin>>courses[i].attendance; // Assuming attendance is the first mark
                    cout<<"Enter assignment marks : ";
                    cin>>courses[i].assignment;
                    cout<<"Enter midterm marks : ";
                    cin>>courses[i].midterm;
                    cout<<"Enter final exam marks : ";
                    cin>>courses[i].finalExam;
                    cout<<"Enter bonus marks : ";
                    cin>>courses[i].bonusMarks;
                    courses[i].totalMarks = courses[i].attendance + courses[i].assignment + courses[i].midterm + courses[i].finalExam + courses[i].bonusMarks;
                    courses[i].percentage = (courses[i].totalMarks / 400) * 100; // Assuming each course is out of 100
                    
                }
                break;
            case 2:
                cout<<"Showing result for students..."<<endl;
                // Code to add a student would go here
                for(int i=0; i<NUM_STUDENTS; i++){
                    cout<<"Student "<<i+1<<": "<<students[i].name<<endl;
                    cout<<"ID: "<<students[i].id<<endl;
                    cout<<"Attendance: "<<courses[i].attendance<<endl;
                    cout<<"Assignment: "<<courses[i].assignment<<endl;
                    cout<<"Midterm: "<<courses[i].midterm<<endl;
                    cout<<"Final Exam: "<<courses[i].finalExam<<endl;
                    cout<<"Bonus Marks: "<<courses[i].bonusMarks<<endl; 
                    cout<<"Total Marks: "<<courses[i].totalMarks<<endl;
                    cout<<"Percentage: "<<courses[i].percentage<<"%"<<endl;
                }
                break;
            case 3:
                cout<<"Exiting the program."<<endl;
                return 0;
            default:
                cout<<"Invalid choice, please try again."<<endl;
        }
    }

     
    for(int i=0; i<NUM_STUDENTS; i++){
        cout<<"Student "<<i+1<<": "<<endl;
        cout<<"Name: ";
        cin>>students[i].name;
        cout<<"ID: ";
        cin>>students[i].id;
        for(int j=0; j<NUM_COURSES; j++){
            cout<<"Enter marks for course "<<j+1<<": ";
            cin>>students[i].courses[j];
        }
    }

    getch();
    return 0;
}