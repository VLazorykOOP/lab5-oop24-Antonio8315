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
    //конструктор без параметрів
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

    //деструктор
    ~PIB() {
        cout << "Destructor ~PIB() \n";
    }

    //оператор присвоєння
    PIB& operator=(const PIB& s)
    {
        fname = s.fname;
        name = s.name;
        lname = s.lname;
        cout << " PIB operator=(PIB &) \n";
        return *this;
    }

    //функція запису в один рядок
    string toString() {
        string ts = "PIB: " + fname + " " + name + " " + lname + " ";
        return ts;
    }

    bool operator==(PIB& b) {
        return name == b.name &&
            fname == b.fname && lname == b.lname ? true : false;
    }

    //функція введення
    void Input() {
        cout << "Input fname "; cin >> fname;
        cout << "Input name "; cin >> name;
        cout << "Input lname "; cin >> lname;
    }
    friend ostream& operator<<(ostream& os, PIB& a);
    friend istream& operator>>(istream& os, PIB& a);
};

class Student {
protected:
    int kurs, ID;
    PIB name;
public:
    //конструктор без параметрів
    Student() {
        kurs = 0;
        ID = 0;
        cout << " Default constructor Person \n";
    }

    //конструктор з параметрами
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

    //деструктор
    ~Student() {
        cout << "Destructor Person\n";
    }

    //функція вибору курсу
    void setkurs(int a) {
        if (a >= 0 && a <= 6)
            kurs = a;
        else
            cout << "Age " << a << " not allow, kurs is " << kurs << endl;;
    }

    //функція вибору ID
    void setID(int w) {
        ID = w;
    }

    //функція запису в один рядок
    string toString() {
        string r, a, w;
        a = to_string(kurs);
        w = to_string(ID);
        r = name.toString() + " kurs: " + a + " ID: " + w;
        return r;
    }

    //функція введення
    void Input() {
        name.Input();
        cout << "Input kurs "; while (!(cin >> kurs) || (kurs < 0 || kurs > 6)) {
            cin.clear();
            cin.ignore(MAXSHORT, '\n');
            fflush(stdin);
            cout << "bad input kurs is 1 to 6 \n";
        };

        cout << "Input ID "; while (!(cin >> ID) || (ID < 0 || ID > 9999999)) {

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
    //коструктор без параметрів
    Student_diplomnik() {
        string tem_of_diplom = "somthing";
        cout << " Default constructor Student_diplomnik() \n";
    }

    //коструктор з параметрами
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

    //деструктор
    ~Student_diplomnik() {
        cout << "\tDestructor Student_diplomnik\n";
    }

    //функція вибору теми диплому
    void settem_of_diplom(string i) {
        tem_of_diplom = i;

    }

    //функція запису в один рядок
    string toString() {
        string stem_of_diplom;
        stem_of_diplom = tem_of_diplom;
        string s = Student::toString() + " tem_of_diplom: " + stem_of_diplom + "\n ";
        return s;
    }

    //функція введення
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

    //функція виведення
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

////////////////////////////////////////////////////////////////////////////////////////

class Kimnata {

public:
    string plosha;

    //конструктор без параметрів
    Kimnata() {
        plosha = "0";
    }

    //конмтруктор з параметрами
    Kimnata(string ki) {
        plosha = ki;
        cout << "Constructor Kimnata(string ki) \n";
    }

    //деструктор
    ~Kimnata() {
        cout << "Destructor ~Kimnata() \n";
    }

    //функція вводу
    void Input() {
        cout << "Input Ploshu kimnatu: "; cin >> plosha;
    }

    //функція запису в один рядок
    string toString() {
        string ts = "Plosha kimnatu: " + plosha + "";
        return ts;
    }
};

class odn_kvartira {
    Kimnata plosha;
    double kuhnia;
    int poverh;
public:
    //конструктор без параметрів
    odn_kvartira() {
        kuhnia = 0;
        poverh = 0;
    }

    //конструктор з параметрами
    odn_kvartira(double ku, double plosha, int po) {
        kuhnia = ku;
        poverh = po;
        plosha = plosha;
    }
    odn_kvartira(double ku, Kimnata& plosha, int po) {
        kuhnia = ku;
        poverh = po;
        plosha = plosha;
    }

    //деструктор
    ~odn_kvartira() {
        cout << "Destructor odn_kvartira\n";
    }

    //функція вводу данних
    void Input() {
        plosha.Input();
        cout << "Input kuhnia "; while (!(cin >> kuhnia)) {
            cin.clear();
            cin.ignore(MAXSHORT, '\n');
            fflush(stdin);
        };

        cout << "Input poverh "; while (!(cin >> poverh))
             {

            cin.clear();
            cin.ignore(MAXSHORT, '\n');
            fflush(stdin);

        };
    }

    //функція запису в один рядок
    string toString() {
        string r, a, w;
        a = to_string(kuhnia);
        w = to_string(poverh);
        r = plosha.toString() + " Plosha kuhni: " + a + " Poverh: " + w;
        return r;
    }
};

class public1:public odn_kvartira {
    string misto;
    public:
    //коструктор без параметрів
    public1() {
        string misto = "No misto";
        cout << " Default constructor Misto() \n";
    }

    //конструктор з параметрами
    public1(double ku, double pl, int po, string mi):
        odn_kvartira(ku, pl, po) {
        string misto = mi;
        cout << " Constructor Misto(int a, int w, PIB& pib, string i) \n";
    }

   //деструктор
    ~public1() {
        cout << "\tDestructor public1\n";
    }

    //функція запису в один рядок
    string toString() {
        string smisto;
        smisto = misto;
        string s = odn_kvartira::toString() + " Misto: " + smisto + "\n ";
        return s;
    }

    //функція друку
    void Input() {
        odn_kvartira::Input();
        cout << "Input Misto ";
        while (!(cin >> misto)) {
            cin.clear();
            cin.ignore(MAXSHORT, '\n');
            fflush(stdin);

        };
    }

    //функція виведення
    void Output() {
        cout << toString() << endl;
    }
};

//////////////////////////////////////

class SportGame {
protected:
    string name;  //назва спортивної гри
    string players;  //кількість гравців

public:
    //конструктор класу SportGame
    SportGame() {
        name = "No name of sport";
        players = "0";
        cout << " Default constructor SportGame() \n";
    }

    //конструктор класу SportGame
    SportGame(const std::string& n, string p) : name(n), players(p) {}

    //конструктор копіювання
    SportGame(const SportGame& other) : name(other.name), players(other.players) {}

    //конструктор перенесення
    SportGame(SportGame&& other) noexcept : name(std::move(other.name)), players(other.players) {}

    //деструктор
    ~SportGame() {}

    //метод для виводу інформації про гру
    void Output(){
        std::cout << "Sport: " << name << ", Players: " << players << std::endl;
    }

    //метод для введення даних про гру
    void Input() {
        std::cout << "Enter sport name: ";
        std::cin >> name;
        std::cout << "Enter number of players: ";
        std::cin >> players;
    }

    //оператор присвоювання для копіювання
    SportGame& operator=(const SportGame& other) {
        if (this != &other) {
            name = other.name;
            players = other.players;
        }
        return *this;
    }

    //оператор присвоювання для перенесення
    SportGame& operator=(SportGame&& other) noexcept {
        if (this != &other) {
            name = std::move(other.name);
            players = other.players;
        }
        return *this;
    }

    string toString() {
        string ts = "Name of Game: " + name + " Number of players: " + players + " ";
        return ts;
    }

    
};

class Football : public SportGame {
private:
    std::string team;  //назва футбольної команди

public:
    //конструктор без параметрів
    Football() {
        name = "No name of team";
        players = "0";
        cout << " Default constructor Football() \n";
    }
    //конструктор класу Football
    Football(const std::string& n, string p, const std::string& t) : SportGame(n, p), team(t) {}

    //конструктор копіювання
    Football(const Football& other) : SportGame(other), team(other.team) {}

    //конструктор перенесення
    Football(Football&& other) noexcept : SportGame(std::move(other)), team(std::move(other.team)) {}

    //деструктор
    ~Football() {
        cout << "Destructor team name";
    }

    //перевизначений метод для виводу інформації про футбольну гру
    void Output(){
        std::cout << "Sport: " << name << ", Players: " << players << ", Team: " << team << std::endl;
    }
    //Problem!!!
    //перевизначений метод для введення даних про футбольну гру
    void Input() {
        SportGame::Input();////
        cout << "Input Name of team: ";
        while (!(cin >> team)) {
            cin.clear();
            cin.ignore(MAXSHORT, '\n');
            fflush(stdin);

        };
    }

    //перевизначений оператор присвоювання для копіювання
    Football& operator=(const Football& other) {
        if (this != &other) {
            SportGame::operator=(other);
            team = other.team;
        }
        return *this;
    }

    //перевизначений оператор присвоювання для перенесення
    Football& operator=(Football&& other) noexcept {
        if (this != &other) {
            SportGame::operator=(std::move(other));
            team = std::move(other.team);
        }
        return *this;
    }

    string toString() {
        string steam;
        steam = team;
        string s = SportGame::toString() + " Team Name: " + steam + "\n ";
        return s;
    }
};
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
       
        case 'q': break;
        default:
            cout << " ??? Choice {1,2, ..., 7 or q} \n";
        }
    } while (Choice != 'q');
    cout << " Exit from test! Bye! \n";


////////////////////////////////////////////////////////////////////////////////////////////


    //завдання 2
    cout << " Task 2! \n";

    //виведення конструктора без параметрів
    public1 test;
    cout << test.toString() << " \n";

    //виведення функції для вводу
    cout << " Введіть : Площу квартири, Полщу кухні, Поверх, Назву міста: \n";
    test.Input();
    cout << " Введено " << test.toString() << " \n";

    //завдання 3
    cout << " Task 3! \n"; 

    //виведення конструктора без параметрів
    Football test1;
    cout << test1.toString() << " \n";

    //виведення програми для вводу даних
    cout << " Введіть : Вид спорту, кількість усасників, назву команди: \n";
    test1.Input();
    cout << " Введено " << test1.toString() << " \n";

    return 0;
}