//Marcin Aman
//http://www.spoj.com/problems/ABSYS/

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

string function(string x) {
	int pointer = 0;
	bool first = false;
	bool result = false;
	int add = 0;
	while (x[pointer] != 'm' && pointer < x.length()) {
		pointer++;
	}
	while (x[add] != '+' && add < x.length()) {
		add++;
	}
	int equal = 0;
	while (x[equal] != '=' && equal < x.length()) {
		equal++;
	}
	if (pointer > add && pointer < equal) {
		first = false;
		result = false;
	}
	else if (pointer > equal) {
		first = false;
		result = true;
	}
	else {
		first = true;
		result = false;
	}
	if (first) {
		string part_2 = x.substr(add + 2, equal - 2 - add);
		string part_3 = x.substr(equal + 2, x.length() - equal - 1);
		int part2i = stoi(part_2);
		int part3i = stoi(part_3);
		int resulti = part3i - part2i;
		return to_string(resulti) + " + " + part_2 + "= " + part_3;
	}
	if (!first && !result) {
		string part_1 = x.substr(0, add - 1);
		//cout << part_1 << "Part1" << endl;
		string part_3 = x.substr(equal + 2, x.length() - equal - 1);
		int part1i = stoi(part_1);
		int part3i = stoi(part_3);
		int resulti = part3i - part1i;
		return part_1 + " + " + to_string(resulti) + " = " + part_3;
	}
	if (result) {
		string part_1 = x.substr(0, add - 1);
		string part_2 = x.substr(add + 2, equal - 2 - add);
		int part1i = stoi(part_1);
		int part2i = stoi(part_2);
		int resulti = part1i + part2i;
		return part_1 + " + " + part_2 + "= " + to_string(resulti);
	}
}

int main() {
	int cases;
	cin >> cases;
	getchar();
	string *tab = new string[cases];
	for (int i = 0; i < cases; i++) {
		getchar();
		string current;
		getline(cin, current);
		tab[i] = function(current);
	}
	for (int j = 0; j < cases; j++) {
		cout << tab[j] << endl;
	}
	delete(tab);

	//getchar();
	// your code goes here
	return 0;
}
