//Attendance Start
void MarkAttendance() {
    resizeAttendance(daysCount + 1, studentCount);
    char a;
    cout << "Attendance for Day " << daysCount + 1 << '\n';
    for (int i = 0; i < studentCount; i++) {
        cout << names[i] << " ";
        cin >> a;
        if (a == 'P' || a == 'p') {
            attendance[daysCount][i] = 1;
        } else {
            attendance[daysCount][i] = 0;
        }
    }
    daysCount++;
}

void showallAttendance() {
    for (int i = 0; i < studentCount; i++) {
        cout << names[i] << " ";
        for (int j = 0; j < daysCount; j++) {
            if (attendance[j][i]) {
                cout << "P ";
            } else {
                cout << "A ";
            }
        }
        cout << "\n";
    }
}

void calcTotalPresent() {
    for (int i = 0; i < studentCount; i++) {
        totalPresent[i] = 0;
        for (int j = 0; j < daysCount; j++) {
            if (attendance[j][i]) {
                totalPresent[i]++;
            }
        }
    }
}

void AttendancePercentage() {
    calcTotalPresent();
    cout << "ID\tName\tAttendance%\n";
    for (int i = 0; i < studentCount; i++) {
        if (daysCount > 0) {
            attendancePercentage[i] = (totalPresent[i] * 100.0f) / daysCount;
        } else {
            attendancePercentage[i] = 0;
        }
        cout << studentsID[i] << "\t" << names[i] << "\t" << attendancePercentage[i] << "%\n";
    }
}

void shortAttendanceStudents() {
    calcTotalPresent();
    cout << "Short Attendance Students Below 75%:\n";
    for (int i = 0; i < studentCount; i++) {
        float percent;
        if (daysCount > 0) {
            percent = (totalPresent[i] * 100.0f) / daysCount;
        } else {
            percent = 0;
        }
        if (percent < 75) { 
            cout << studentsID[i] << "\t" << names[i] << "\t" << percent << "%\n";
        }
    }
}
//Attendances End
