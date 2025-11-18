void resizeAttendance(int newDays, int newStudents) {
    int minDays;
    int minStudents;
    bool **temp = new bool*[newDays];
    for (int i = 0; i < newDays; i++) {
        temp[i] = new bool[newStudents]{0};
    }
    if(attendance != nullptr){
        minDays = min(daysCount, newDays);
    }
    else    minDays = 0;
    if(studentCount > 0 && newStudents > 0){
        minStudents = min(studentCount, newStudents);
    }
    else    minStudents = 0;
    if (attendance != nullptr) {
        for (int i = 0; i < minDays; i++) {
            for (int j = 0; j < minStudents; j++) {
                temp[i][j] = attendance[i][j];
            }
        }
        for (int i = 0; i < daysCount; i++) {
            if (attendance[i] != nullptr) delete[] attendance[i];
        }
        delete[] attendance;
    }
    attendance = temp;
    int* tempTotal = new int[newStudents];
    float* tempPerc = new float[newStudents];
    for (int i = 0; i < newStudents; i++) {
        tempTotal[i] = 0;
        tempPerc[i] = 0.0f;
    }
    for (int i = 0; i < minStudents; i++) {
        if (totalPresent != nullptr) tempTotal[i] = totalPresent[i];
        if (attendancePercentage != nullptr) tempPerc[i] = attendancePercentage[i];
    }
    delete[] totalPresent;
    delete[] attendancePercentage;
    totalPresent = tempTotal;
    attendancePercentage = tempPerc;

    int* tempSubjects = new int[newStudents];
    for (int i = 0; i < newStudents; i++) tempSubjects[i] = 0;
    if (Subjects != nullptr) {
        for (int i = 0; i < minStudents; i++) {
            tempSubjects[i] = Subjects[i];
        }
        delete[] Subjects;
    }
    Subjects = tempSubjects;

    float **tempmarks = new float*[newStudents];
    for (int i = 0; i < newStudents; i++) tempmarks[i] = nullptr;

    int limit = min(studentCount, newStudents);

    if (marks != nullptr && Subjects != nullptr) {
        for (int i = 0; i < limit; i++) {
            // int subjCount = (Subjects[i] > 0) ? Subjects[i] : 0;
            if (Subjects[i] > 0) {
                tempmarks[i] = new float[Subjects[i]];
                if (marks[i] != nullptr) {
                    for (int j = 0; j < Subjects[i]; j++) {
                        tempmarks[i][j] = marks[i][j];
                    }
                } else {
                    for (int j = 0; j < Subjects[i]; j++) {
                        tempmarks[i][j] = 0.0f;
                    }
                }
            } else {
                tempmarks[i] = nullptr;
            }
        }
    }

    if (marks != nullptr) {
        for (int i = 0; i < studentCount; i++) {
            if (marks[i] != nullptr) delete[] marks[i];
        }
        delete[] marks;
    }

    marks = tempmarks;

    float *tempTotalMarks = new float[newStudents];
    for (int i = 0; i < newStudents; i++) tempTotalMarks[i] = 0.0f;
    if (totalMarks != nullptr) {
        for (int i = 0; i < limit; i++) tempTotalMarks[i] = totalMarks[i];
    }
    delete[] totalMarks;
    totalMarks = tempTotalMarks;

    float *tempPercentage = new float[newStudents];
    for (int i = 0; i < newStudents; i++) tempPercentage[i] = 0.0f;
    if (percentage != nullptr) {
        for (int i = 0; i < limit; i++) tempPercentage[i] = percentage[i];
    }
    delete[] percentage;
    percentage = tempPercentage;
}

void addStudent() {
    resizeAttendance(daysCount, studentCount + 1);
    string studentName;
    cout << "Enter Name: ";
    getline(cin >> ws, studentName);

    string* tempNames = new string[studentCount + 1];
    int* tempIDs = new int[studentCount + 1];

    if (names != nullptr) {
        for (int i = 0; i < studentCount; i++) {
            tempNames[i] = names[i];
            tempIDs[i] = studentsID[i];
        }
    } 
    else {
        for (int i = 0; i < studentCount; i++) {
            tempNames[i] = "";
            tempIDs[i] = 0;
        }
    }

    tempNames[studentCount] = studentName;
    tempIDs[studentCount] = studentCount + 1;

    delete[] names;
    delete[] studentsID;

    names = tempNames;
    studentsID = tempIDs;
    studentCount++;

}

void deleteStudent(int k) {
    if (k < 0 || k >= studentCount) return;
    string* tempNames = new string[studentCount - 1];
    int* tempIDs = new int[studentCount - 1];
    int* tempTotal = new int[studentCount - 1];
    float* tempPerc = new float[studentCount - 1];
    for (int i = 0, j = 0; i < studentCount; i++) {
        if (i == k) continue;
        tempNames[j] = names[i];
        tempIDs[j] = studentsID[i];
        tempTotal[j] = totalPresent[i];
        tempPerc[j] = attendancePercentage[i];
        j++;
    }
    delete[] names;
    delete[] studentsID;
    delete[] totalPresent;
    delete[] attendancePercentage;
    names = tempNames;
    studentsID = tempIDs;
    totalPresent = tempTotal;
    attendancePercentage = tempPerc;
    studentCount--;
    resizeAttendance(daysCount, studentCount);
}

void deleteStudentrollNumber(int rollNumber) {
    int flag = 0;
    for (int i = 0; i < studentCount; i++) {
        if (studentsID[i] == rollNumber) {
            deleteStudent(i);
            flag = 1;
            break;
        }
    }
    if(flag)    cout<<"Successfully Deleted!!\n";
    else    cout<<"Student Not Found!!!!\n";
}

void deleteStudentNames(string NAME) {
    int flag = 0;
    for (int i = 0; i < studentCount; i++) {
        if (names[i] == NAME) {
            deleteStudent(i);
            flag = 1;
            break;
        }
    }
    if(flag)    cout<<"Successfully Deleted!!!\n";
    else    cout<<"Student Not Found";
}

void searchStudent(int k) {
    if (k >= 0 && k < studentCount)
        cout << studentsID[k] << "\t" << names[k] << "\n";
}

void searchStudentrollNumber(int rollNumber) {
    for (int i = 0; i < studentCount; i++) {
        if (studentsID[i] == rollNumber) {
            searchStudent(i);
            return;
        }
    }
    cout << "Not found\n";
}

void searchStudentNames(string NAME) {
    for (int i = 0; i < studentCount; i++) {
        if (names[i] == NAME) {
            searchStudent(i);
            return;
        }
    }
    cout << "Not found\n";
}

void showallStudents() {
    cout << "Ids\tNames\n";
    for (int i = 0; i < studentCount; i++) {
        cout << studentsID[i] << "\t" << names[i] << "\n";
    }
}
