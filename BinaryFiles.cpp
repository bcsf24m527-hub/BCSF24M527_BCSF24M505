// Save binary
void saveBinary() {
    ofstream out("Backup.dat", ios::binary);

    // Save student count
    out.write((char*)&studentCount, sizeof(studentCount));

    // Save student info
    for (int i = 0; i < studentCount; i++) {
        out.write((char*)&studentsID[i], sizeof(studentsID[i]));
        int len = names[i].size();
        out.write((char*)&len, sizeof(int));
        for(int j = 0; j < len; j++){
            out.write((char*)&names[i][j],1);
        }
        // Subjects countarr
        out.write((char*)&Subjects[i], sizeof(Subjects[i]));

        // Marks
        for (int j = 0; j < Subjects[i]; j++) {
            out.write((char*)&marks[i][j], sizeof(float));
        }
    }

    // Save attendance
    out.write((char*)&daysCount, sizeof(daysCount));
    for (int d = 0; d < daysCount; d++) {
        for (int s = 0; s < studentCount; s++) {
            out.write((char*)&attendance[d][s], sizeof(bool));
        }
    }
    out.close();
}

// Load binary
void loadBinary() {
    ifstream in("Backup.dat", ios::binary);
    if(!in) loadfromFile();
    // Read student count
    else{
    in.read((char*)&studentCount, sizeof(int));
    // Allocate arrays
    studentsID = new int[studentCount];
    names = new string[studentCount];
    Subjects = new int[studentCount];
    marks = new float*[studentCount];
    totalMarks = new float[studentCount];
    percentage = new float[studentCount];
    totalPresent = new int[studentCount];
    attendancePercentage = new float[studentCount];

    for (int i = 0; i < studentCount; i++) {
        totalMarks[i] = 0;
        percentage[i] = 0;
        totalPresent[i] = 0;
        attendancePercentage[i] = 0;
    }

    // Read student info
    for (int i = 0; i < studentCount; i++) {
        // ID
        in.read((char*)&studentsID[i], sizeof(studentsID[i]));

        // Name
        int len;
        in.read((char*)&len, sizeof(len));

        char* temp = new char[len + 1];
        for (int j = 0; j < len; j++) {
            in.read(&temp[j], sizeof(char));
        }
        temp[len] = '\0';
        names[i] = temp;
        delete[] temp;
        // Subjects
        in.read((char*)&Subjects[i], sizeof(Subjects[i]));
        // Marks
        marks[i] = new float[Subjects[i]];
        for (int j = 0; j < Subjects[i]; j++) {
            in.read((char*)&marks[i][j], sizeof(float));
        }

        recalc(i);
    }

    // Attendance
    in.read((char*)&daysCount, sizeof(daysCount));
    attendance = new bool*[daysCount];
    for (int d = 0; d < daysCount; d++) {
        attendance[d] = new bool[studentCount];
        for (int s = 0; s < studentCount; s++) {
            in.read((char*)&attendance[d][s], sizeof(bool));
        }
    }

    // Recalculate attendance percentage
    calcTotalPresent();
    for (int i = 0; i < studentCount; i++) {
        if (daysCount > 0) {
            attendancePercentage[i] = (totalPresent[i] * 100.0f) / daysCount;
        } else {
            attendancePercentage[i] = 0;
        }
    }
    }
    in.close();
}