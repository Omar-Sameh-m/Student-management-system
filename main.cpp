#include "student_ms.cpp"
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int sz = Students::size;
    Students s[sz];
    string line;
    ifstream infile("Student.txt"); // the input file
    int currentSize = 0;
    while (getline(infile, line) && currentSize < sz)
    {
        stringstream ss(line);
        string name, cnic, program, phone;
        int rollno;
        float cgpa;
        ss >> name >> cnic >> rollno >> program >> phone;
        s[currentSize].name = name;
        s[currentSize].cnic = cnic;
        s[currentSize].rollno = rollno;
        s[currentSize].cgpa = cgpa;
        s[currentSize].program = program;
        s[currentSize].phone_number = phone;
        currentSize++;
    }
    infile.close();
    int choice;
    do
    {
        cout << "--------MENU--------" << endl;
        cout << "1. Show All Students" << endl;
        cout << "2. Search a student by roll no" << endl;
        cout << "3. Find the student with max CGPA" << endl;
        cout << "4. Sort the students by name" << endl;
        cout << "5. Sort the students by CGPA" << endl;
        cout << "6. Add a new student" << endl;
        cout << "7. Save the students to the file" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            s->show_all_students(s, currentSize);
            break;
        case 2:
            int rollno;
            cout << "Enter Roll No to search: " << endl;
            cin >> rollno;
            s->search_by_rollno(s, rollno, currentSize);
            break;
        case 3:
            s->find_max_cgpa(s, currentSize);
            break;
        case 4:
            s->sort_by_name(s, currentSize);
            cout << "Students sorted by name!" << endl;
            break;
        case 5:
            s->sort_by_cgpa(s, currentSize);
            cout << "Students sorted by CGPA!" << endl;
            break;
        case 6:
            s->add_new_student(s, currentSize);
            break;
        case 7:
            s->save_student_to_file(s, currentSize, "Student.txt");
            break;
        case 8:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice! Please enter a valid option." << endl;
            break;
        }
        cout << endl;
    } while (choice != 8);

    return 0;
}