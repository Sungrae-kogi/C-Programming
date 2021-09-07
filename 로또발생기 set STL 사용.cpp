#include <iostream>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <random>

using namespace std;

void Add(map<string, string>& dic, string s, stirng v) {
	dic[s] = v;
}

void Search(map<string, string> dic, string s) {
	if (!dic[s].empty()) {
		cout << s << "의 의미는" << dic[s] << endl;
	}
	else {
		cout << "찾는 단어가 없습니다." << endl;
	}
}

void Delete(map<string, string>& dic, string s) {
	map<string, string>::iterator iter = dic.find(s);
	if (iter == dic.end()) {
		cout << "찾는 단어가 없습니다." << endl;
	}
	else {
		dic.erase(iter);
	}
}



int main() {
	map<string, string>dic;
	string s, value;
	dic["boy"] = "소년";
	dic["school"] = "학교";
	dic["office"] = "직장";
	dic["house"] = "집";
	dic["morning"] = "아침";
	dic["evening"] = "저녁";

	int sel;
	while (1) {
		cout << "1.단어 추가 2. 단어 검색 3.단어 삭제 4.EXIT" << endl;
		cout << ">>";
		cin >> sel;
		if (sel == 1) {
			cout << "단어 입력: ";
			cin >> s;
			cout << "뜻 입력: ";
			cin >> value;
			Add(dic, s, value);
		}
		else if (sel == 2) {
			cout << "단어 입력: ";
			cin >> s;
			Search(dic, s);
		}
		else if (sel == 3) {
			cout << "단어 입력: ";
			cin >> s;
			Delete(dic, s);
		}
		else if (sel == 4) {
			return 0;
		}
	}

	return 0;
}