//Marcin Aman
//http://www.spoj.com/problems/LASTDIG2/
#include <iostream>
#include <math.h>
using namespace std;

int last_digit(string a, string b){
	if(b=="0"){
		return 1;
	}
	int last_a = a[a.length()-1]-48;
	int b_mod = 0;
	for(int i=0;i<b.length();i++){
		b_mod = b_mod*10+b[i]-'0';
		b_mod=b_mod%4;
	}
	if(b_mod==0) b_mod=4;
	
		int result = (int)pow(last_a,b_mod)%10;
		return result;
	
}

int main(){
	int cases;
	string a, b;
	cin >> cases;
	int *arr = new int[cases];
	for(int i=0;i<cases;i++){
		cin >> a >>b;
		arr[i]=last_digit(a,b);
	}
	for(int i=0;i<cases;i++){
		cout << arr[i] << endl;
	}
	delete(arr);
	return 0;
}
