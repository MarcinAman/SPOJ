//Marin Aman
//http://www.spoj.com/problems/OFFSIDE/

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	while (a != 0 && b != 0) {
		int *A = new int[a];
		int *B = new int[b];
		for (int i = 0; i < a; i++) cin >> A[i];
		for (int i = 0; i < b; i++) cin >> B[i];
		sort(A,A+a);
		sort(B,B+b);
		if (A[0] < B[1]) cout << "Y" << endl;
		else cout << "N" << endl;
		cin >> a >> b;
		delete(A);
		delete(B);
	}
	return 0;
}
