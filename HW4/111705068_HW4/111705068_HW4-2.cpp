#include<iostream>
using namespace std;
int main()
{
    class grade
    {
       private:
        float quiz1, quiz2, midterm, Final, average;
        char grade;
       public:
        void setQuiz1(float q1)
        {
            quiz1 = q1;
        }
        void setQuiz2(float q2)
        {
            quiz2 = q2;
        }
        void setMidterm(float m)
        {
            midterm = m;
        }
        void setFinal(float f)
        {
            Final = f;
        }
        void setAverage(float a)
        {
            average = a;
        }
        void setGrade(char g)
        {
            grade = g;
        }
        float getQuiz1()
        {
            return quiz1;
        }
        float getQuiz2()
        {
            return quiz2;
        }
        float getMidterm()
        {
            return midterm;
        }
        float getFinal()
        {
            return Final;
        }
        float getAverage()
        {
            return average;
        }
        char getGrade()
        {
            return grade;
        }
        void calculateAverage()
        {
            average = (quiz1 * 1.25+ quiz2 * 1.25 + midterm * 0.25 + Final * 0.5);
        }
        void calculateGrade()
        {
            if (average >= 90)
            {
                grade = 'A';
            }
            else if (average >= 80)
            {
                grade = 'B';
            }
            else if (average >= 70)
            {
                grade = 'C';
            }
            else if (average >= 60)
            {
                grade = 'D';
            }
            else
            {
                grade = 'F';
            }
        }
    };
    grade student;
    float q1, q2, m, f;
    cout << "Quiz 1 score (0-10), Quiz 2 score (0-10), Midterm score (0-100), Final score (0-100)"<<endl;
    cin >> q1 >> q2 >> m >> f;
    student.setQuiz1(q1);
    student.setQuiz2(q2);
    student.setMidterm(m);
    student.setFinal(f);
    student.calculateAverage();
    student.calculateGrade();
    cout << endl;
    cout << "Student Record:"<<endl;
    cout << "Quiz 1 score: " << student.getQuiz1() << endl;
    cout << "Quiz 2 score: " << student.getQuiz2() << endl;
    cout << "Midterm score: " << student.getMidterm() << endl;
    cout << "Final score: " << student.getFinal() << endl;
    cout << "Average Score: " << student.getAverage() << endl;
    cout << "Grade: " << student.getGrade() << endl;
    return 0;
}