#include <iostream>
#include <string>
using namespace std;
class Person
{
private:
    string name;
    int age;
    string phone;
public:
    Person(const string n = "", int a = 0, const string& ph = "") :name(n), age(a), phone(ph) { }
    void Print()const {
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
    void Print()const {//�Լ� ������
        Person::Print();
        cout << "grade:" << grade << endl;
    }
    int GetGrade()const {
        return grade;
    }
};
int main() {
    Person p1;
    Student s1;

    Person& rp = s1; // O
    Person* pp = &s1; // O

    rp.Print(); // �������� �޼ҵ�
    pp->Print(); // ������...
}

//#include <iostream>
//#include <string>
//using namespace std;
//class Person
//{
//private:
//    string name;
//    int age;
//    string phone;
//public:
//    Person(const string n = "", int a = 0, const string& ph = "") :name(n), age(a), phone(ph) { }
//    void Print()const {
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
//    p1 = s1; // X // �л�(Student)�� ���(Person)�̴�
//    Student& rp = s1; // O
//    Student* pp = &s1; // O
//}

//#include <iostream>
//#include <string>
//using namespace std;
//class Person
//{
//private:
//    string name;
//    int age;
//    string phone;
//public:
//    Person(const string n = "", int a = 0, const string& ph = "") :name(n), age(a), phone(ph) { }
//    void Print()const {
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
//    Student s1("���л�", 20, "010-1234-5555", 1);
//
//    s1.Print();
//    cout << s1.GetName() << endl;
//    cout << s1.GetGrade() << endl;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//class Person // ��ü ����� �߻��� ���� class Person
//{
//private:
//	string name;
//	int age;
//	string phone;
//public:
//	Person(const string n = "", int a = 0, const string& ph = "") : name(n), age(a), phone(ph) {}
//	void Print() const {
//		cout << "name:" << name << ',' << "age:" << age << ',' << "phone:" << phone << endl;
//	};
//	void SetName(const string& n) {
//		name = n;
//	};
//	const string GetName() const {
//		return name;
//	};
//};
//class Student : public Person {
//	int grade;
//public:
//	Student(const string n = "", int a = 0, const string ph = "", int g = 0) : Person(n,a,ph, g),
//		grade(g){ }
//	void Print()const { // �Լ� ������
//		Person::Print();
//		cout << "grade;" << grade << endl;
//	}
//	int GetGrade()const {
//		return grade;
//	}
//};
//int main() {
//	Student s1("���л�", 20, "010-1234-5555", 1);
//
//	s1.Print();
//	cout << s1.GetName() << endl;
//	cout << s1.GetGrade() << endl;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//class Person // ��ü ����� �߻��� ���� class Person
//{
//private:
//	string name;
//	int age;
//	string phone;
//public:
//	Person(const string n = "", int a = 0, const string& ph = "") : name(n), age(a), phone(ph) {}
//	void Print() const {
//		cout << "name:" << name << ',' << "age:" << age << ',' << "phone:" << phone << endl;
//	};
//	void SetName(const string& n) {
//		name = n;
//	};
//	const string GetName() const {
//		return name;
//	};
//};
//class Student {
//	string name;
//	int age;
//	string phone;
//	int grade;
//public:
//	Student(const string n = "", int a = 0, const string ph = "", int g=0) :
//		name(n), age(a), phone(ph), grade(g) {}
//	void Print() const {
//		cout << "name:" << name << ',' << "age:" << age << ',' << "phone:" << phone <<
//			"grade:" << grade << endl;
//	};
//	void SetName(const string& n) {
//		name = n;
//	};
//	const string GetName() const {
//		return name;
//	};
//	int GetGrade() const {
//		return grade;
//	}
//
//};
//int main() {
//	Person per1("ȫ�浿", 23, "010-1234-5678");
//
//	// main() �Լ��� per1 ��ü���� Print�޽����� ������.
//	per1.Print(); // per1 ��ü�� Print() �޼ҵ�(����Լ�)�� ȣ���Ѵ�.
//	per1.SetName("ȫ����");
//	per1.Print();
//}

//#include <iostream>
//#include <string>
//using namespace std;
//
//class Person // ��ü ����� �߻��� ���� class Person
//{
//private:
//	string name;
//	int age;
//	string phone;
//public:
//	Person(const string n = "", int a = 0, const string& ph = "") : name(n), age(a), phone(ph) {}
//	void Print() const;
//	void SetName(const string& n);
//	const string GetName() const;
//};
//
//int main()
//{
//	Person per1("ȫ�浿", 23, "010-1234-5678");
//	Person* p1 = new Person("������", 25, "010-5678-2222");
//
//	per1.Print();
//	p1->Print();
//
//	per1.SetName("ȫ����");
// 	main() �Լ��� per1 ��ü���� Print�޽����� ������.
//	per1.Print(); // per1 ��ü�� Print() �޼ҵ�(����Լ�)�� ȣ���Ѵ�.
//	p1->Print();
//
//	delete p1;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//
//class Person // ��ü ����� �߻��� ���� class Person
//{
//private:
//	string name;
//	int age;
//	string phone;
//public:
//	Person(const string n = "", int a = 0, const string& ph = "") : name(n), age(a), phone(ph) {}
//	void Print() const {
//		cout << "name:" << name << ',' << "age:" << age << ',' << "phone:" << phone << endl;
//	}
//	void SetName(const string& n) {
//		name = n;
//	}
//	const string GetName() const {
//		return name;
//	}
//};
//
//int main()
//{
//	Person per1("ȫ�浿",23,"010-1234-5678");
//	Person* p1 = new Person("������",25,"010-5678-2222");
//
//	per1.Print();
//	p1->Print();
//
//	per1.SetName("ȫ����");
//	per1.Print();
//	p1->Print();
//
//	delete p1;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//
//class Person // ��ü ����� �߻��� ���� class Person
//{
//private:
//	string name;
//	int age;
//	string phone;
//public:
//	Person(const string n="", int a=0, const string& ph="") : name(n), age(a), phone(ph) {}
//	void Print() const {
//		cout << "name:" << name << ',' << "age:" << ',' << "phone:" << phone << endl;
//	}
//	void SetName(const string& n) {
//		name = n;
//	}
//	const string GetName() const {
//		return name;
//	}
//};
//
//int main()
//{
//	Person per1;
//	Person* p1 = new Person();
//
//	per1.Print();
//	p1->Print();
//
//	delete p1;
//}