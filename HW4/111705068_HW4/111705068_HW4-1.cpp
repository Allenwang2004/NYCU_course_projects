#include<iostream>

using namespace std;
int main()
{
    struct grade
    {
        double quiz1;
        double quiz2;
        double midterm;
        double Final;
        double average;
        char grade;
    };
    grade student;
    cout << "Quiz 1 score (0-10), Quiz 2 score (0-10), Midterm score (0-100), Final score (0-100)"<<endl;
    cin >> student.quiz1 >> student.quiz2 >> student.midterm >> student.Final;
    student.average = (student.quiz1 * 1.25 + student.quiz2 * 1.25 + student.midterm * 0.25+ student.Final * 0.5);
    if (student.average >= 90)
    {
        student.grade = 'A';
    }
    else if (student.average >= 80)
    {
        student.grade = 'B';
    }
    else if (student.average >= 70)
    {
        student.grade = 'C';
    }
    else if (student.average >= 60)
    {
        student.grade = 'D';
    }
    else
    {
        student.grade = 'F';
    }
    cout << endl;
    cout << "Student Record:"<<endl;
    cout << "Quiz 1 score: " << student.quiz1 << endl;
    cout << "Quiz 2 score: " << student.quiz2 << endl;
    cout << "Midterm score: " << student.midterm << endl;
    cout << "Final score: " << student.Final << endl;
    cout << "Average Score: " << student.average << endl;
    cout << "Grade: " << student.grade << endl;
    return 0;
}