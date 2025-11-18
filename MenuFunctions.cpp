//MENU FUNCTIONS START
void studentManagementMenu(){
    int choice;
    string name;
    int rollno;
    do{
        SetConsoleTextAttribute(h, 14);
        cout << "\nStudent Management Menu:\n";
        cout << "1 - Add Student\n";
        SetConsoleTextAttribute(h, 12);
        cout << "2 - Delete student By Name\n";
        cout << "3 - Delete Student By Roll Number\n";
        SetConsoleTextAttribute(h, 14);
        cout << "4 - Search Student By Name\n";
        cout << "5 - Search Student By Roll Number\n";
        cout << "6 - Display All Students\n";
        cout << "0 - Go back to main menu\n";
        SetConsoleTextAttribute(h, 15);
        cout << "\nEnter Your Choice: ";
        cin>>choice;
        switch (choice){
            case 1: addStudent();
            SetConsoleTextAttribute(h, 10);
            system("pause");
            break;
            case 2: 
                cout<<"Enter Name of that Student You Want to Delete: ";
                cin.ignore();
                getline(cin,name);
                deleteStudentNames(name);
                SetConsoleTextAttribute(h, 10);
                system("pause");
            break;
            case 3: 
                cout<<"Enter Roll Number of that Student You Want to Delete: ";
                cin>>rollno;
                deleteStudentrollNumber(rollno);
                SetConsoleTextAttribute(h, 10);
                system("pause");
            break;
            case 4: 
                cout<<"Enter Name of that Student You Want to Search: ";
                cin.ignore();
                getline(cin,name);
                searchStudentNames(name);
                SetConsoleTextAttribute(h, 10);
                system("pause");
            break;
            case 5: 
                cout<<"Enter Roll Number of that Student You Want to Search: ";
                cin>>rollno;
                searchStudentrollNumber(rollno);
                SetConsoleTextAttribute(h, 10);
                system("pause");
            break;
            case 6:
                showallStudents();
                SetConsoleTextAttribute(h, 10);
                system("pause");
                break;
            default: choice = 0;
        }
    }while(choice != 0);
}
void marksMenu() {
    int choice;
    do{
        SetConsoleTextAttribute(h, 3);
        cout << "\nMarks Management Menu:\n";
        cout << "1 - Add marks for a student\n";
        cout << "2 - Update marks for a student\n";
        cout << "3 - Calculate all students' results\n";
        cout << "4 - Show the student with highest percentage\n";
        cout << "5 - Print a student's marksheet\n";
        cout << "0 - Go back to main menu\n";
        SetConsoleTextAttribute(h, 15);
        cout << "\nEnter Your Choice: ";
        cin>>choice;
        switch (choice){
            case 1: addMarks();
            SetConsoleTextAttribute(h, 10);
            system("pause");
            break;
            case 2: updateMarks();
            SetConsoleTextAttribute(h, 10);
            system("pause");
            break;
            case 3: calculateResults();
            SetConsoleTextAttribute(h, 10);
            system("pause");
            break;
            case 4: showTopper();
            SetConsoleTextAttribute(h, 10);
            system("pause");
            break;
            case 5: printMarksheet();
            SetConsoleTextAttribute(h, 10);
            system("pause");
            break;
            default: choice = 0;
        }
    }while(choice != 0);
}

void attendanceMenu() {
    int choice;
    do{
        SetConsoleTextAttribute(h, 5);
        cout << "\nAttendance Menu:\n";
        cout <<"1 - Mark attendance for today\n";
        cout <<"2 - Show all attendance records\n";
        cout <<"3 - Show attendance percentages\n";
        cout <<"4 - List students below 75% attendance\n";
        cout <<"0 - Go back to main menu\n";
        SetConsoleTextAttribute(h, 15);
        cout <<"\nEnter your choice: ";
        cin>>choice;
        switch (choice){
            case 1: MarkAttendance();
            SetConsoleTextAttribute(h, 10);
            system("pause");
            break;
            case 2: showallAttendance();
            SetConsoleTextAttribute(h, 10);
            system("pause");
            break;
            case 3: AttendancePercentage();
            SetConsoleTextAttribute(h, 10);
            system("pause");
            break;
            case 4: shortAttendanceStudents();
            SetConsoleTextAttribute(h, 10);
            system("pause");
            break;
            default: choice = 0;
        }
    }while(choice != 0);
}

void reportMenu() {
    int choice;
    do{
        SetConsoleTextAttribute(h, 9);
        cout << "\nReports Menu:\n";
        cout << "1 - List all students\n";
        cout << "2 - Show the topper\n";
        cout << "3 - Print a student's marksheet\n";
        cout <<"0 - Return to main menu\n";
        SetConsoleTextAttribute(h, 15);
        cout << "\nEnter your choice: ";
        cin>>choice;
        switch(choice){
            case 1: showallStudents();
            SetConsoleTextAttribute(h, 10);
            system("pause");
            break;
            case 2: showTopper();
            SetConsoleTextAttribute(h, 10);
            system("pause");
            break;
            case 3: printMarksheet();
            SetConsoleTextAttribute(h, 10);
            system("pause");
            break;
            default: choice = 0;
        }
    }while(choice != 0);
}
//MENU FUNCTIONS END
