//Marks Start
int findStudent(int id) {
    for (int i = 0; i < studentCount; i++) {
        if (studentsID[i] == id) return i;
    }
    cout << "Invalid ID\n";
    return -1;
}

void recalc(int i) {
    float sum = 0;
    for (int s = 0; s < Subjects[i]; s++)
        sum += marks[i][s];
    totalMarks[i] = sum;
    percentage[i] = (sum / (Subjects[i] * 100)) * 100;
}

void addMarks() {
    int id;
    cout << "Enter student ID: ";
    cin >> id;
    int i = findStudent(id);
    if (i == -1) return;
    cout<<"Enter Number of subjects: ";
    cin>>Subjects[i];
    marks[i] = new float [Subjects[i]];
    for (int s = 0; s < Subjects[i]; s++) {
        cout << "Enter marks for subject " << s + 1 << ": ";
        cin >> marks[i][s];
    }
    recalc(i);
}

void updateMarks() {
    int id, sub;
    cout << "Enter student ID: ";
    cin >> id;
    int i = findStudent(id);
    if (i == -1) return;
    cout << "Enter subject number to update: ";
    cin >> sub;
    if (sub < 1 || sub > Subjects[i]) {
        cout << "Invalid subject\n";
        return;
    }
    cout << "Enter new marks: ";
    cin >> marks[i][sub - 1];
    recalc(i);
}

void calculateResults() {
    for (int i = 0; i < studentCount; i++) recalc(i);
}

void showTopper() {
    if (studentCount == 0) {
        cout << "No students\n";
        return;
    }
    int top = 0;
    for (int i = 1; i < studentCount; i++) {
        if (percentage[i] > percentage[top]) top = i;
    }
    cout << "Topper: " << names[top] << " (" << percentage[top] << "%)\n";
}

void printMarksheet() {
    int id;
    cout << "Enter student ID: ";
    cin >> id;
    int i = findStudent(id);
    if (i == -1) return;
    cout << "--- Marksheet ---\n";
    cout << "Name: " << names[i] << "\n";
    cout << "ID: " << studentsID[i] << "\n";
    for(int s = 0; s < Subjects[i]; s++)
        cout << "Subject " << s + 1 << ": " << marks[i][s] << "\n";
    cout << "Total: " << totalMarks[i] << "\n";
    cout << "Percentage: " << percentage[i] << "%\n";
}
//Marks End
