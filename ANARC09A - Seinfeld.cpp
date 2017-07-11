//Marcin Aman
//http://www.spoj.com/problems/ANARC09A/
#include <iostream>
#include <vector>

using namespace std;

int changing_brackets(string s){
	int stack=0,i=0,result=0;
	while(i<s.length()){
		if(s[i]=='{') stack++;
		else if(s[i]=='}' and stack==0){
			stack ++;
			result ++;
		}
		else{
			stack--;
		}
		i++;
	}
	result += stack/2;
	if(stack%2==1) result++;
	return result;
}

int main(){
	vector<int>arr;
	string a;
	cin >> a;
	while(a[0]!='-'){
		arr.push_back(changing_brackets(a));
		cin >> a;
	}
	for(int i=0;i<arr.size();i++){
		cout << i+1 << ". " << arr[i] << endl; 
	}
	return 0;
}
