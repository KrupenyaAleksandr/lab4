#include <iostream>
#include <string>
#include <list>
#include <fstream>
using namespace std;

class user {
public:
	user() {};
	user(string login, int login_count = 1) {
		this->login = login;
		this->login_count = login_count;
	}
private:
	friend class usersList;
	string login;
	int login_count;
};

class usersList {
public:
	void setList() {
		string tmp, usertmp;
		int pos;
		bool flag = true;
		ifstream inputfile("write.txt");
		inputfile >> tmp;
		pos = tmp.find_first_of('/');
		site.push_back(user(tmp.substr(0, pos)));
		while (!inputfile.eof()) {
			inputfile >> tmp;
			pos = tmp.find_first_of('/');
			usertmp = tmp.substr(0, pos);
			flag = true;
			for (auto i = site.begin(); i != site.end(); ++i) {
				if (i->login == usertmp) {
					i->login_count++;
					flag = false;
					break;
				}
			}
			if (flag) site.push_back(user(tmp.substr(0, pos)));
		}
		inputfile.close();
	}
	void checkLogins() {
		int count = 0;
		for (auto i = site.begin(); i != site.end(); ++i) {
			if (i->login_count == 1) count++;
		}
		cout << count;
	}
private:
	list <user> site;
};

int main() {
	usersList github;
	github.setList();
	github.checkLogins();
	return 1;
}