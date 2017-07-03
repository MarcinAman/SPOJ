//Marcin Aman
//http://www.spoj.com/problems/MAXLN/

#include <iostream>
#include <math.h>

using namespace std;

int main(){
	int long long cases,r;
	cin >> cases;
	for(int i=0;i<cases;i++){
		cin >> r;
		long long int s=pow(r,2)*4;
		cout<<"Case "<<i+1<<": "<<s<<".25"<<endl;
	}
	return 0;
}
