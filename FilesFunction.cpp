//Files Function
// Save Students
void addStudentsToFile() {
    ofstream fout("Students.txt");
    fout << "Students_Count: " << studentCount << '\n';
    for (int i = 0; i < studentCount; i++) {
        fout << studentsID[i] << ' ' << names[i] << '\n';
    }
    fout.close();
}

// Save Marks
void addMarksToFile() {
    ofstream fout("Marks.txt");
    for (int i = 0; i < studentCount; i++) {
        fout << studentsID[i] << ' ' << Subjects[i] << ' ';
        for (int j = 0; j < Subjects[i]; j++)
            fout << marks[i][j] << ' ';
        fout << '\n';
    }
    fout.close();
}

// Save Attendance
void addAttendancesToFile() {
    ofstream fout("Attendance.txt");
    fout << daysCount << '\n';
    for (int d = 0; d < daysCount; d++) {
        for (int i = 0; i < studentCount; i++)
            fout << attendance[d][i] << ' ';
        fout << '\n';
    }
}
void AddToFiles(){
    addStudentsToFile();
    addMarksToFile();
    addAttendancesToFile();
}
//Loading from file
// Load Students
void loadStudents() {
    ifstream fin("Students.txt");
    if (!fin) return; // file not found
    string temp;
    fin >> temp >> studentCount; // "Students_Count: N"

    // Allocate arrays
    names = new string[studentCount];
    studentsID = new int[studentCount];
    Subjects = new int[studentCount]{0};
    marks = new float*[studentCount]{nullptr};
    totalMarks = new float[studentCount]{0};
    percentage = new float[studentCount]{0};
    totalPresent = new int[studentCount]{0};
    attendancePercentage = new float[studentCount]{0};

    fin.ignore(); // skip newline
    for (int i = 0; i < studentCount; i++) {
        fin >> studentsID[i];
        fin.ignore();
        getline(fin, names[i]);
    }
    fin.close();
}

// Load Marks
void loadMarks() {
    ifstream fin("Marks.txt");
    if (!fin) return;

    for (int i = 0; i < studentCount; i++) {
        int id;
        fin >> id >> Subjects[i];
        marks[i] = new float[Subjects[i]];
        for (int j = 0; j < Subjects[i]; j++)
            fin >> marks[i][j];
        recalc(i); // calculate totalMarks and percentage
    }
    fin.close();
}

// Load Attendance
void loadAttendance() {
    ifstream fin("Attendance.txt");
    if (!fin) return;

    fin >> daysCount;
    attendance = new bool*[daysCount];
    for (int d = 0; d < daysCount; d++)
        attendance[d] = new bool[studentCount]{0};

    for (int d = 0; d < daysCount; d++)
        for (int i = 0; i < studentCount; i++)
            fin >> attendance[d][i];

    calcTotalPresent(); // recalc totals and percentages
    for (int i = 0; i < studentCount; i++) {
        if (daysCount > 0)
            attendancePercentage[i] = (totalPresent[i] * 100.0f) / daysCount;
        else
            attendancePercentage[i] = 0;
    }

    fin.close();
}

// Load All
void loadfromFile() {
    loadStudents();
    loadMarks();
    loadAttendance();
}
