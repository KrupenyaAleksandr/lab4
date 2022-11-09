#include <iostream>
#include <string>
#include <list>
#include <fstream>
using namespace std;

class fileMethods {
public:
	fileMethods() {};
	fileMethods(string str) {
		inputfile.open(str);
		string a = "ÀÁÂÃÄÅ¨¸ÆÇÈÊËÌÍÎÏÐÑÒÓÔßÿà";
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
private:
	ifstream inputfile;
};

int main() {
	fileMethods a("write1.txt");
	a.upper_lower();
	string abc = "/521.,";
	return 1;
}