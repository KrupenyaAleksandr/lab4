#include <iostream>
#include <string>
using namespace std;

class human {
public:
	friend class student;
	human(){};
	human(string name, int age, char sex) {
		this->name = new string(name);
		this->age = age;
		this->sex = sex;
	}
	~human(){};
	
	void print() {
		cout << *this->name << " " << this->age << " " << this->sex << endl;
	}

private:
	string* name;
	int age;
	char sex;
};

class student : public human {
public:
	student(){};
	student(string name, int age, char sex, int course, string group) : human(name, age, sex) {
		this->course = course;
		this->group = new string(group);
	}
	~student(){};

	void print() {
		cout << *this->name << " " << this->age << " " << this->sex << " " << this->course << " " << *this->group << endl;
	}

	void changeGroup(string group) {
		*this->group = group;
	}

private:
	int course;
	string* group;
};

int main() {
	human a("Bebra", 21, 'M');
	a.print();
	a.~human();
	student b("Bebrovich", 20, 'F', 3, "PRI-20");
	b.print();
	b.changeGroup("SPIS-20");
	b.print();
	b.~student();
	return 1;
}