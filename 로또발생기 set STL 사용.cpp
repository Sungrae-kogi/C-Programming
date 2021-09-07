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
		cout << s << "�� �ǹ̴�" << dic[s] << endl;
	}
	else {
		cout << "ã�� �ܾ �����ϴ�." << endl;
	}
}

void Delete(map<string, string>& dic, string s) {
	map<string, string>::iterator iter = dic.find(s);
	if (iter == dic.end()) {
		cout << "ã�� �ܾ �����ϴ�." << endl;
	}
	else {
		dic.erase(iter);
	}
}



int main() {
	map<string, string>dic;
	string s, value;
	dic["boy"] = "�ҳ�";
	dic["school"] = "�б�";
	dic["office"] = "����";
	dic["house"] = "��";
	dic["morning"] = "��ħ";
	dic["evening"] = "����";

	int sel;
	while (1) {
		cout << "1.�ܾ� �߰� 2. �ܾ� �˻� 3.�ܾ� ���� 4.EXIT" << endl;
		cout << ">>";
		cin >> sel;
		if (sel == 1) {
			cout << "�ܾ� �Է�: ";
			cin >> s;
			cout << "�� �Է�: ";
			cin >> value;
			Add(dic, s, value);
		}
		else if (sel == 2) {
			cout << "�ܾ� �Է�: ";
			cin >> s;
			Search(dic, s);
		}
		else if (sel == 3) {
			cout << "�ܾ� �Է�: ";
			cin >> s;
			Delete(dic, s);
		}
		else if (sel == 4) {
			return 0;
		}
	}

	return 0;
}