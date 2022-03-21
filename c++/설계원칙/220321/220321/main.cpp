#include <iostream>
#include <string>
using namespace std;
// 서비스 코드 클래스 
class Person
{
protected:
    string name;
    int age;
    string phone;
public:
    Person(const string n = "", int a = 0, const string& ph = "") :name(n), age(a), phone(ph) { }
    virtual void Print()const {
        cout << "name:" << name << ',' << "age:" << age << ',' << "phone:" << phone << endl;
    }
    void SetName(const string& n) {
        name = n;
    }
    const string GetName()const {
        return name;
    }
};
class Student : public Person {
    int grade;
public:
    Student(const string n = "", int a = 0, const string ph = "", int g = 0) :Person(n, a, ph),
        grade(g) { }
    void Print()const { //함수 재정의
        Person::Print();
        cout << "grade:" << grade << endl;
    }
    int GetGrade()const {
        return grade;
    }
};
/// 클라이언트 코드
int main() {
    Person p1("홍길동", 20, "010-1123-5678");
    cout << p1.GetName() << endl;

    Student s1("김학생", 22, "010, 2-3452-1234", 2);
    cout << s1.
}

//#include <iostream>
//#include <string>
//using namespace std;
//class Person
//{
//protected:
//    string name;
//    int age;
//    string phone;
//public:
//    Person(const string n = "", int a = 0, const string& ph = "") :name(n), age(a), phone(ph) { }
//    virtual void Print()const {
//        cout << "name:" << name << ',' << "age:" << age << ',' << "phone:" << phone << endl;
//    }
//    void SetName(const string& n) {
//        name = n;
//    }
//    const string GetName()const {
//        return name;
//    }
//};
//class Student : public Person {
//    int grade;
//public:
//    Student(const string n = "", int a = 0, const string ph = "", int g = 0) :Person(n, a, ph),
//        grade(g) { }
//    void Print()const {//함수 재정의
//        Person::Print();
//        cout << "grade:" << grade << endl;
//    }
//    int GetGrade()const {
//        return grade;
//    }
//};
//int main() {
//    Person p1;
//    Student s1;
//
//    Person& rp = s1;   //O
//    Person* pp = &s1;  //O
//
//    rp.Print(); //다형적인 메소드
//    pp->Print(); //다형성....
//}