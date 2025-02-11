#include "student_ms.h"
#include <fstream>

bool Students::operator<(Students &other)
{
    return name < other.name;
}

bool Students::compareByCgpa(Students &a, Students &b)
{
    return a.cgpa < b.cgpa;
}

void Students::show_all_students(Students s[], int current_size)
{
    if (current_size == 0)
    {
        cout << "No students available." << endl;
        return;
    }

    cout << left << setw(15) << "Name"
         << setw(20) << "CNIC"
         << setw(10) << "RollNo"
         << setw(8) << "CGPA"
         << setw(10) << "Program"
         << setw(15) << "Phone" << endl;
    cout << string(78, '-') << endl;

    for (int i = 0; i < current_size; i++)
    {
        cout << left << setw(15) << s[i].name
             << setw(20) << s[i].cnic
             << setw(10) << s[i].rollno
             << setw(8) << s[i].cgpa
             << setw(10) << s[i].program
             << setw(15) << s[i].phone_number
             << endl;
    }
}

void Students::search_by_rollno(Students s[], int rollno, int current_size)
{
    bool found = false;
    for (int i = 0; i < current_size; i++)
    {
        if (s[i].rollno == rollno)
        {
            if (!found)
            {
                cout << left << setw(15) << "Name"
                     << setw(20) << "CNIC"
                     << setw(10) << "RollNo"
                     << setw(8) << "CGPA"
                     << setw(10) << "Program"
                     << setw(15) << "Phone" << endl;
                cout << string(78, '-') << endl;
                found = true;
            }
            cout << left << setw(15) << s[i].name
                 << setw(20) << s[i].cnic
                 << setw(10) << s[i].rollno
                 << setw(8) << s[i].cgpa
                 << setw(10) << s[i].program
                 << setw(15) << s[i].phone_number << endl;
            break;
        }
    }
    if (!found)
    {
        cout << "The student with RollNo " << rollno << " was not found." << endl;
    }
}

void Students::find_max_cgpa(Students s[], int current_size)
{
    if (current_size == 0)
    {
        cout << "No students available to check CGPA." << endl;
        return;
    }

    Students *max_student = &s[0];
    for (int i = 1; i < current_size; i++)
    {
        if (s[i].cgpa > max_student->cgpa)
        {
            max_student = &s[i];
        }
    }

    cout << "Student with highest CGPA: " << endl;
    cout << "Name: " << max_student->name << "\t"
         << "Roll No: " << max_student->rollno << "\t"
         << "CGPA: " << max_student->cgpa << "\t"
         << "Program: " << max_student->program << "\t"
         << "CNIC: " << max_student->cnic << "\t"
         << "Phone: " << max_student->phone_number << "\n";
}

void Students::sort_by_name(Students s[], int current_size)
{
    sort(s, s + current_size);
    cout << "Students sorted by name !" << endl;
}

void Students::sort_by_cgpa(Students s[], int current_size)
{
    sort(s, s + current_size, Students::compareByCgpa);
    cout << "Students are sorted by CGPA !" << endl;
}

void Students::add_new_student(Students s[], int &current_size)
{
    if (current_size >= size)
    {
        cout << "You can't add more students!" << endl;
        return;
    }

    Students newStudent;
    cout << "Enter the name: " << endl;
    cin.ignore();
    getline(cin, newStudent.name);
    cout << "Enter the CNIC: " << endl;
    getline(cin, newStudent.cnic);
    cout << "Enter the roll no: " << endl;
    cin >> newStudent.rollno;
    cout << "Enter the CGPA: " << endl;
    cin >> newStudent.cgpa;
    cout << "Enter the degree program (Bs/Ms): " << endl;
    cin.ignore();
    getline(cin, newStudent.program);
    cout << "Enter the phone number: " << endl;
    getline(cin, newStudent.phone_number);

    s[current_size] = newStudent;
    current_size++;
    cout << "Student has been added successfully!" << endl;
}

void Students::save_student_to_file(Students s[], int current_size, const string &filename)
{
    ofstream out(filename);
    if (!out)
    {
        cout << "Unable to open the file!" << endl;
        return;
    }
    for (int i = 0; i < current_size; i++)
    {
        out << s[i].name << '\t'
            << s[i].cnic << '\t'
            << s[i].rollno << '\t'
            << s[i].cgpa << '\t'
            << s[i].program << '\t'
            << s[i].phone_number << endl;
    }
    out.close();
    cout << "Students have been saved successfully!" << endl;
}
