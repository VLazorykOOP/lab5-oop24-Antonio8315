// OOPLab5T.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <windows.h>
using namespace std;
using std::cout;
// Ваші файли загловки 
//
//#include "Lab5Exmaple.h"

struct PIB
{
    string fname;
    string name;
    string lname;
    PIB() {
        fname = "NoFirstName";
        name = "NoName";
        lname = "NoLastName";
        cout << "Default constructor PIB \n";
    }
    PIB(string fn) {
        fname = "NoFirstName";
        name = fn;
        lname = "NoLastName";
        cout << "Constructor PIB(string fn) \n";
    }
    PIB(string fn[3]) {
        fname = fn[0];
        name = fn[1];
        lname = fn[2];
        cout << "Constructor PIB(string fn[]) \n";
    }
    PIB(const PIB& s) {
        fname = s.fname;
        name = s.name;
        lname = s.lname;
        cout << "Constructor Copy PIB(const PIB &) \n";
    }
    PIB(PIB&& s) {
        fname = s.fname;
        name = s.name;
        lname = s.lname;
        cout << " Constructor Move PIB(PIB &&) \n";
        s.fname = "NoFirstName";
        s.name = "NoName";
        s.lname = "NoLastName";
    }
    PIB(const char* fn, const char* n, const char* ln) {
        fname = fn;
        name = n;
        lname = ln;
        cout << " Constructor PIB(const char * ... ) \n";
    }
    ~PIB() {
        cout << "Destructor ~PIB() \n";
    }
    PIB& operator=(const PIB& s)
    {
        fname = s.fname;
        name = s.name;
        lname = s.lname;
        cout << " PIB operator=(PIB &) \n";
        return *this;
    }
    string toString() {
        string ts = "PIB: " + fname + " " + name + " " + lname + " ";
        return ts;
    }
    bool operator==(PIB& b) {
        return name == b.name &&
            fname == b.fname && lname == b.lname ? true : false;
    }
    void Input() {
        cout << "Input fname "; cin >> fname;
        cout << "Input name "; cin >> name;
        cout << "Input lname "; cin >> lname;
    }
    friend ostream& operator<<(ostream& os, PIB& a);
    friend istream& operator>>(istream& os, PIB& a);
};

//PROBLEM
/*
ostream& operator<<(ostream& os, PIB& a) {
    os << a.fname << endl;
    os << a.name << endl;
    os << a.lname << endl;
    return os;
}
istream& operator>>(istream& is, PIB& a) {
    is >> a.name;
    is >> a.fname;
    is >> a.lname;
    return is;
}
*/

class Student {
protected:
    int kurs, ID;
    PIB name;
public:
    Student() {
        kurs = 0;
        ID = 0;
        cout << " Default constructor Person \n";
    }

    Student(int a, int w, string n) {
        kurs = a;
        ID = w;
        name = n;
        cout << " Constructor Person(int a, int w, string n) \n";
    }

    Student(int a, int w, PIB& n) {
        kurs = a;
        ID = w;
        name = n;

        cout << " Constructor Person(int a, int w, PIB &n) \n";
    }



    ~Student() {
        cout << "Destructor Person\n";
    }

    void setkurs(int a) {
        if (a >= 0 && a <= 6)
            kurs = a;
        else
            cout << "Age " << a << " not allow, kurs is " << kurs << endl;;
    }

    void setID(int w) {
        ID = w;
    }

    string toString() {
        string r, a, w;
        a = to_string(kurs);
        w = to_string(ID);
        r = name.toString() + " kurs: " + a + " ID: " + w;
        return r;
    }

    void Input() {
        name.Input();
        cout << "Input kurs "; while (!(cin >> kurs) || (kurs < 0 || kurs > 6)) {
            cin.clear();
            cin.ignore(MAXSHORT, '\n');
            fflush(stdin);
            cout << "bad input kurs is 1 to 6 \n";
        };

        cout << "Input ID "; while (!(cin >> ID) || (ID < 0 || ID > 9999999)
            ) {

            cin.clear();
            cin.ignore(MAXSHORT, '\n');
            fflush(stdin);

        };
    }
    friend ostream& operator<<(ostream& os, Student& a);
    friend istream& operator>>(istream& os, Student& a);

};

ostream& operator<<(ostream& os, Student& a) {
    os << a.name;
    os << a.kurs << endl;
    os << a.ID << endl;
    return os;
}
istream& operator>>(istream& is, Student& a) {
    is >> a.name;
    is >> a.kurs;
    is >> a.ID;
    return is;
}


class Student_diplomnik : public Student {
    string tem_of_diplom;
public:
    Student_diplomnik() {
        string tem_of_diplom = "somthing";
        cout << " Default constructor Student_diplomnik() \n";
    }
    Student_diplomnik(int a, int w, string n, string i) :
        Student(a, w, n) {
        string tem_of_diplom = i;
        cout << " Constructor Student_diplomnik(int a, int w, string n, string i) \n";
    }
    Student_diplomnik(int a, int w, PIB& pib, string i) :
        Student(a, w, pib) {
        string tem_of_diplom = i;
        cout << " Constructor Student_diplomnik(int a, int w, PIB& pib, string i) \n";
    }
    ~Student_diplomnik() {
        cout << "\tDestructor Student_diplomnik\n";
    }

    void settem_of_diplom(string i) {
        tem_of_diplom = i;

    }
    string toString() {
        string stem_of_diplom;
        stem_of_diplom = tem_of_diplom;
        string s = Student::toString() + " tem_of_diplom: " + stem_of_diplom + "\n ";
        return s;
    }

    void Input() {
        Student::Input();
        cout << "Input Tem_of_diplom ";
        while (!(cin >> tem_of_diplom)) {
            cin.clear();
            cin.ignore(MAXSHORT, '\n');
            fflush(stdin);
            cout << "bad input ID \n";
        };
    }
    void Output() {
        cout << toString() << endl;
    }
    friend ostream& operator<<(ostream& os, Student_diplomnik& a);
    friend istream& operator>>(istream& os, Student_diplomnik& a);

};

ostream& operator<<(ostream& os, Student_diplomnik& a) {
    os << a.name;
    os << a.kurs << endl;
    os << a.ID << endl;
    os << a.tem_of_diplom << endl;
    return os;
}
istream& operator>>(istream& is, Student_diplomnik& a) {
    is >> a.name;
    is >> a.kurs;
    is >> a.ID;
    is >> a.tem_of_diplom;
    return is;
}
int main()
{
    std::cout << " Lab #5  !\n";
    setlocale(LC_CTYPE, "ukr");
    char Choice = 'n';
    do {
        cout << "\n\n\n Main menu \n";
        cout << "1 - Default constructor Student-diplomnik \n";
        cout << "2 - Default constructor Student-diplomnik input \n";
        cout << "3 - Constructor Student-diplomnik (int a, int w, PIB pib, string i) \n";
        cout << "4 - Set kurse \n";
        cout << "5 - Set ID \n";
        cout << "6 - Set tem of diplom \n";
        cout << "7 - Input from file \n";
        cout << "8 - Input array of Student-diplomnik and save file \n";
        cout << "q - Quit \n";
        cout << "Ваш вибiр (you choice ): ";
        cin >> Choice;
        switch (Choice)
        {
        case '1': {
            Student_diplomnik test;
            cout << test.toString() << " \n";
        }
                break;
        case '2': {
            Student_diplomnik test;
            cout << " Введіть : Прізвище Імя По-батькові, Курс ID, тему диплому (ПІБ - Англ.  мовою) \n";
            test.Input();
            cout << " Введено " << test.toString() << " \n";
        }
                break;

        case '3': {
            PIB pib("Zuzak", "Boris", "Petrovich");
            Student_diplomnik t(1, 1, pib, "something");
            string rez = t.toString();
            cout << rez;
        }
                break;

        case '4': {
            PIB pib("Zuzak", "Boris", "Petrovich");
            Student_diplomnik t(1, 1, pib, "something");
            t.toString();
            cout << t.toString() << endl;
            cout << " Input new # of kurs Boris ";
            int newkurs;
            while (!(cin >> newkurs)) {
                cin.clear();
                cin.ignore(MAXSHORT, '\n');
                fflush(stdin);
                cout << "bad input \n";
            };
            t.setkurs(newkurs);
            cout << " New recoeds " << t.toString() << endl;
        }
                break;

        case '5': {
            PIB pib("Zuzak", "Boris", "Petrovich");
            Student_diplomnik t(1, 1, pib, "something");
            t.toString();
            cout << t.toString() << endl;
            cout << " Input new ID Boris ";
            int newID;
            while (!(cin >> newID)) {
                cin.clear();
                cin.ignore(MAXSHORT, '\n');
                fflush(stdin);
                cout << "bad input \n";
            };
            t.setID(newID);
            cout << " New recoeds " << t.toString() << endl;
        }
                break;

        case '6': {
            PIB pib("Zubenko", "Mihail", "Petrovich");
            Student_diplomnik t(1, 1, pib, "something");
            t.toString();
            cout << t.toString() << endl;
            cout << " Input new tem_of_diplom Boris ";
            string new_tem_of_diplom;
            while (!(cin >> new_tem_of_diplom)) {
                cin.clear();
                cin.ignore(MAXSHORT, '\n');
                fflush(stdin);

                cout << "bad input \n";
            };
            t.settem_of_diplom(new_tem_of_diplom);
            cout << " New recoeds " << t.toString() << endl;
        }
                break;
        case '7': {
            ifstream fileStudent_diplomnik("fileStudent-diplomnik.txt");
            int n, i;
            fileStudent_diplomnik >> n;
            if (n > 0)
            {
                Student_diplomnik* pMas;
                pMas = new Student_diplomnik[n];
                for (i = 0; i < n; i++)
                    fileStudent_diplomnik >> pMas[i];
                cout << "Student-diplomnik in file \n";
                for (i = 0; i < n; i++)
                    cout << pMas[i].toString() << endl;
                cout << " delete \n";
                delete[] pMas;
            }
        }
                break;
        case '8': {
            ofstream fileStudent_diplomnik("fileStudent_diplomnik1.txt");
            int n, i;
            cout << " Input num Student-diplomnik ";
            while (!(cin >> n) || n < 0) {
                cin.clear();
                cin.ignore(MAXSHORT, '\n');
                fflush(stdin);
                cout << "bad input num \n";
            };
            Student_diplomnik* pMas;
            pMas = new Student_diplomnik[n];
            for (i = 0; i < n; i++)
                pMas[i].Input();
            cout << "Student-diplomnik in input e \n";
            for (i = 0; i < n; i++)
                cout << pMas[i].toString() << endl;
            fileStudent_diplomnik << n << endl;
            for (i = 0; i < n; i++)
                fileStudent_diplomnik << pMas[i];
            cout << "Student-diplomnik save in file \n";
            cout << " delete \n";
            delete[] pMas;
        }
        case 'q': break;
        default:
            cout << " ??? Choice {1,2, ..., 7 or q} \n";
        }
    } while (Choice != 'q');
    cout << " Exit from test! Bye! \n";
    return 0;

    //  Код виконання завдань
    //  Головне меню завдань
    //  Функції та класи можуть знаходитись в інших файлах проекту
    /*
    int chain = 2;
    if (chain == 1) chain = mainExample1();
    if (chain == 2) chain = mainExample2();
    if (chain == 3) chain = mainExample3();
    if (chain == 4) chain = mainExample4();
    if (chain == 5) chain = mainExample5();
    */
}
