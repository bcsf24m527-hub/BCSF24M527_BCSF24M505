#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;

int studentCount = 0;
int daysCount = 0;
int *studentsID = nullptr;
string *names = nullptr;
float **marks = nullptr;
float *totalMarks = nullptr;
float *percentage = nullptr;
bool **attendance = nullptr;
int *totalPresent = nullptr;
float *attendancePercentage = nullptr;
int *Subjects = nullptr;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

#include "Students.cpp"
#include "Marks.cpp"
#include "Attendance.cpp"
#include "FilesFunction.cpp"
#include "BinaryFiles.cpp"
#include "MenuFunctions.cpp"

int main() {
    // loadfromFile();
    loadBinary();
    // loadStudents();
    int choice;
    
    do{
    SetConsoleTextAttribute(h, 2);
    cout << "\n--- Main Menu ---\n";
    cout << "1 - Student Management\n";
    cout << "2 - Marks Management\n";
    cout << "3 - Attendance Management\n";
    cout << "4 - Reports\n";
    cout << "5 - Add All Data to Respective Files\n";
    cout << "0 - Exit the program\n";
    SetConsoleTextAttribute(h, 15);
    cout << "\nEnter your choice: ";
    cin>>choice;
    switch (choice){
        case 1: studentManagementMenu();
        break;
        case 2: marksMenu();
        break;
        case 3: attendanceMenu();
        break;
        case 4: reportMenu();
        break;
        case 5: AddToFiles();
        break;
        default: choice = 0;
    }
    }while(choice != 0);
    saveBinary();
    SetConsoleTextAttribute(h, 7);  // Light Gray (default)
    // AddToFiles();
    return 0;
}