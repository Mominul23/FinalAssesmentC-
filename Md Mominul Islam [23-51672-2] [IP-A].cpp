#include <iostream>
#include <string>

using namespace std;


class User {
private:
    string name;
    int age;
    string bg;

protected:
    User(string n, int a, string bloodG) : name(n), age(a), bg(bloodG) {}

public:
    virtual void DisplayInfo() {
        cout << "                     Welcome to our portal system " << endl << "                           " << name << "," << endl;
        cout << endl;
        cout << "Name        : " << name << endl;
        cout << "Age         : " << age << " years old" << endl;
        cout << "Blood Group : " << bg << endl;
    }

    virtual ~User() {
        cout << "User Destructor Called" << endl;
    }
};

class Student : public User {
private:
    string SID;
    string courses[7];
    int courseCount;
    int cradits[7]; // Array to store credits for each course

public:
    Student(string sid, string n, int a, string bloodG) : User(n, a, bloodG), SID(sid), courseCount(0) {
        for (int i = 0; i < 7; i++) {
            cradits[i] = 0; // Initialize credits array
        }
    }

    void AddCourse(string course, int crdttt) {
        if (courseCount < 7) {
            courses[courseCount] = course;
            cradits[courseCount] = crdttt; // Store credits for the course
            courseCount++;
        } else {
            cout << "Cannot add more than 7 courses" << endl;
        }
    }

    int getCradit(int index) {
        return cradits[index];
    }

    void DisplayCourses() {
        cout << "Courses for upcoming Spring Semester :" << endl;
        cout << endl;
        cout << "    [Code]             [Course]            [Section]            [Credits]" << endl;
        cout << "    ......             ........           ..........           ..........." << endl;
        cout << endl;

        for (int i = 0; i < courseCount; i++) {
            cout << i + 1 << " : " << courses[i] <<endl<< "                                                                    " << getCradit(i) << endl;
        }


    }

    int getTotalCradit() {
        int totalCradit = 0;
        for (int i = 0; i < courseCount; i++) {
            totalCradit += cradits[i];
        }
        return totalCradit;
    }

    void DisplayInfo() override {
        User::DisplayInfo();
        cout << "Student ID  : " << SID << endl;
        cout << "............................................................................." << endl;
        cout << "" << endl;
        DisplayCourses();
        cout << "                                                               ............" << endl;
        cout<<endl;
        cout << "                                                Total Credits  : " << getTotalCradit()<< " Credits"  << endl;
    }

    ~Student() override {
        cout << "Student Destructor Called" << endl;
    }
};


int main() {

     //---------------------------------------Home Screen--------------------------------------------

     cout << "                     ------[IP-A] Final Assignment------" << endl;
     cout << "                             AIUB Portal System" << endl;
     cout << "                             For Spring(2023-24)" << endl;
     cout<< endl;

      //-----------------------------------------------------------------------------------

     cout << "...............................Student-1....................................." << endl;
        cout<< endl;

    Student s( /* Student ID */          "23-51672-2",
               /* Student Name */         "Md Mominul Islam",
               /* Student Age */          21 ,
               /* Student Blood Group */  "O+ (ve)"
               );

    s.AddCourse("01929 - PHYSICS 2 LAB [O]", 1);

    s.AddCourse("00877 - ENGLISH WRITING SKILLS & COMMUNICATIONS [FST/FE] [CCC]" ,3 );

    s.AddCourse("01305 - INTRODUCTION TO ELECTRICAL CIRCUITS [W]",3);

    s.AddCourse("01504 - OBJECT ORIENTED PROGRAMMING 1 (JAVA) [CC]",4 );

    s.AddCourse("01858 - INTRODUCTION TO ELECTRICAL CIRCUITS LAB [R]" ,1 );

    s.AddCourse("00586 - BANGLADESH STUDIES [FST] [F]" , 2 );





    s.DisplayInfo();
    cout<< endl;

    cout << "............................................................................." << endl;
        cout<< endl;



        //-----------------------------------------------------------------------------------

    Student s2( /* Student ID */           "23-51845-2",
                /* Student Name */         "Mst. Fahmida Akter",
                /* Student Age */          18,
                /* Student Blood Group */  "O+ (ve)"
                 );


    s2.AddCourse("01504 - OBJECT ORIENTED PROGRAMMING 1 (JAVA) [CC]", /* Creadit */              4 );
    s2.AddCourse("01858 - INTRODUCTION TO ELECTRICAL CIRCUITS LAB [R]", /* Creadit */              1 );
    s2.AddCourse("01305 - INTRODUCTION TO ELECTRICAL CIRCUITS [W]", /* Creadit */              3 );
    s2.AddCourse("00586 - BANGLADESH STUDIES [FST] [F]", /* Creadit */              3 );
    s2.AddCourse("01929 - PHYSICS 2 LAB [O]", /* Creadit */              3 );
    s2.AddCourse("01929 - PHYSICS 2 LAB [O]", /* Creadit */              1 );
    s2.AddCourse("01929 - PHYSICS 2 LAB [O]", /* Creadit */              1 );



    cout << "...............................Student-2....................................." << endl;
        cout<< endl;
    s2.DisplayInfo();
    cout << "" << endl;
    cout << "............................................................................." << endl;
        cout<< endl;

        //-----------------------------------------------------------------------------------

    Student s3( /* Student ID */           "23-51885-3",
               /* Student Name */          "Md Asif Iqbal Raihan",
                /* Student Age */          23,
                /* Student Blood Group */  "O+(ve)"
                );


    s3.AddCourse("01504 - OBJECT ORIENTED PROGRAMMING 1 (JAVA) [CC]", /* Creadit */              3 );
    s3.AddCourse("00586 - BANGLADESH STUDIES [FST] [F]", /* Creadit */              2 );
    s3.AddCourse("01858 - INTRODUCTION TO ELECTRICAL CIRCUITS LAB [R]", /* Creadit */              3 );
    s3.AddCourse("01305 - INTRODUCTION TO ELECTRICAL CIRCUITS [W]", /* Creadit */              2 );
    s3.AddCourse("00877 - ENGLISH WRITING SKILLS & COMMUNICATIONS [FST/FE] [CCC]", /* Creadit */              1 );
    s3.AddCourse("00877 - ENGLISH WRITING SKILLS & COMMUNICATIONS [FST/FE] [CCC]", /* Creadit */              1 );
    s3.AddCourse("01929 - PHYSICS 2 LAB [O]", /* Creadit */              3 );


    cout << "...............................Student-3....................................." << endl;

        cout<< endl;
    s3.DisplayInfo();
    cout << "" << endl;

    cout << "............................................................................." << endl;
        cout<< endl;

        //--------------------------------------------------------------------------



    return 0;
}
