#include <iostream>
#include <string>
using namespace std;
// ���� �ڵ� Ŭ���� 
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
    void Print()const { //�Լ� ������
        Person::Print();
        cout << "grade:" << grade << endl;
    }
    int GetGrade()const {
        return grade;
    }
};
/// Ŭ���̾�Ʈ �ڵ�
int main() {
    Person p1("ȫ�浿", 20, "010-1123-5678");
    cout << p1.GetName() << endl;

    Student s1("���л�", 22, "010, 2-3452-1234", 2);
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
//    void Print()const {//�Լ� ������
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
//    rp.Print(); //�������� �޼ҵ�
//    pp->Print(); //������....
//}