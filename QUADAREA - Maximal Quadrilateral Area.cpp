//Marcin Aman
//http://www.spoj.com/problems/QUADAREA/

#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

double count_area(double a, double b, double c, double d){
	double s = (a+b+c+d)/(double)2;
	//cout << s << endl;
	return sqrt((s-a)*(s-b)*(s-c)*(s-d));
}

int main(){
	int cases;
	double a,b,c,d;
	scanf("%d",&cases);
	for(int i=0;i<cases;i++){
		cin >> a >> b >> c >> d;
		cout << setprecision(2) << fixed << count_area(a,b,c,d) << endl;
	}
	return 0;
}
