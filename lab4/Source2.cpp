#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <vector>
using namespace std;

class fileMethods {
public:
	fileMethods() {};
	fileMethods(string str) {
		inputfile.open(str);
		string a = "јЅ¬√ƒ≈®Є∆«» ЋћЌќѕ–—“”‘я€а";
		string b = " ,;:.";
	};
	void upper_lower() {
		string tmp;
		unsigned int count = 0, upCount = 0, lowCount = 0;
		while (!inputfile.eof()) {
			inputfile >> tmp;
			for (int i = 0; i < tmp.length(); ++i) {
				if ((tmp[i] >= 32 && tmp[i] <= 64) || (tmp[i] >= 91 && tmp[i] <= 96) || (tmp[i] >= 123 && tmp[i] <= 127)) {
					continue;
				}
				if (tmp[i] < 0) {
					if ((tmp[i] >= -64 && tmp[i] <= -33) || tmp[i] == -88) {
						upCount++;
						count++;
						continue;
					}
					else {
						lowCount++;
						count++;
						continue;
					}
				}
				if (isupper(tmp[i])) {
					upCount++;
					count++;
					continue;
				}
				else {
					lowCount++;
					count++;
				}
			}
		}
		double percentUp;
		cout.precision(2);
		cout << 100 / double(count) * upCount << " " <<  100 - (100 / double(count) * upCount) << endl;
		cout << count << ' ' << upCount << ' ' << lowCount << endl;
	}
	void symbol_line() {
		string tmp;
		char sym;
		cin >> sym;
		int count, symcount, num = 1;
		while (!inputfile.eof()) {
			inputfile >> tmp;
			count = 0;
			symcount = 0;
			for (int i = 0; i < tmp.length(); ++i) {
				count++;
				if (tmp[i] == sym) symcount++;
			}
			double percent;
			cout << "¬ строке є" << num << ": " << 100 / double(count) * symcount << "%" << endl;
			num++;
		}
	}
	void symbol_text() {
		string tmp;
		char sym;
		cin >> sym;
		int count = 0, symcount = 0;
		while (!inputfile.eof()) {
			inputfile >> tmp;
			for (int i = 0; i < tmp.length(); ++i) {
				count++;
				if (tmp[i] == sym) symcount++;
			}
		}
		double percent;
		cout << "¬еро€тность по€влени€ символа в тексте: " << 100 / double(count) * symcount << "%" << endl;
	}
	void sort() {
		vector <string> vec;
		string tmp;
		int alphabet, pos; // 1 - русский, 2 - английский
		char sym;
		bool flag; //
		getline(inputfile, tmp);
		vec.insert(vec.begin(), tmp);
		if (tmp[0] < 0) alphabet = 1;
		else alphabet = 2;
		switch (alphabet) { // если символ заглавный +32 
			case 1: 
				while (getline(inputfile, tmp)) {
					flag = true; // нужен чтобы вставить строку в конец вектора
					pos = 0;
					sym = tmp[0];
					if (sym <= -33) sym += 32;
					for (auto i = vec.begin(); i < vec.end(); ++i) {
						char symtmp = i[0][0];
						if (symtmp <= -33) symtmp += 32;
						if (sym <= symtmp) {
							advance(i, pos);
							vec.insert(i, tmp);
							flag = false;
							break;
						}
					}
					if (flag) {
						vec.insert(vec.end(), tmp);
					}
				}
				break;
			case 2:
				while (getline(inputfile, tmp)) {
					flag = true; // нужен чтобы вставить строку в конец вектора
					pos = 0;
					sym = tmp[0];
					if (sym <= 90) sym += 32;
					for (auto i = vec.begin(); i < vec.end(); ++i) {
						char symtmp = i[0][0];
						if (symtmp <= 90) symtmp += 32;
						if (sym <= symtmp) {
							advance(i, pos);
							vec.insert(i, tmp);
							flag = false;
							break;
						}
					}
					if (flag) {
						vec.insert(vec.end(), tmp);
					}
				}
				break;
		}
	}
private:
	ifstream inputfile;
};

int main() {
	setlocale(LC_ALL, "RU");
	fileMethods a("write1.txt");
	a.sort();
	string abc = "/521.,";
	return 1;
}