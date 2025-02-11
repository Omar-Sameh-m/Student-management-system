#ifndef STUDENTS_H
#define STUDENTS_H

#include <bits/stdc++.h>
using namespace std;

class Students
{
public:
    static const int size = 500;
    string name;
    string program;
    int rollno;
    float cgpa;
    string cnic;
    string phone_number;

    void show_all_students(Students s[], int current_size);
    void search_by_rollno(Students s[], int rollno, int current_size);
    void find_max_cgpa(Students s[], int current_size);
    void sort_by_name(Students s[], int current_size);
    void sort_by_cgpa(Students s[], int current_size);
    void add_new_student(Students s[], int &current_size);
    void save_student_to_file(Students s[], int current_size, const string &filename);

    bool operator<(Students &other);
    static bool compareByCgpa(Students &a, Students &b);
};

#endif // STUDENTS_H