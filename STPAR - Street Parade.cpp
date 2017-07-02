//Marcin Aman
//http://www.spoj.com/problems/STPAR/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool check_if_possible(stack<int>& stack_in, int n){
	if(n==1 or n==2 or n==3){ //it is always possible ;)
		return true;
	} 
	stack<int>stack_out;
	int current =1;
	while(!stack_in.empty()&&current!=n+1){
		if(stack_in.top()==current){
			current++;
			stack_in.pop();
		}
		else if(!stack_out.empty()&& stack_out.top()==current){
			stack_out.pop();
			current++;
		}
		else{
			stack_out.push(stack_in.top());
			stack_in.pop();
		}
	}
	while(!stack_out.empty()){
		if(current==stack_out.top()){
			stack_out.pop();
			current++;
		}
		else{
			return false;
		}
	}
	return true;
}


void get_data(){
	vector<string>results;
	int n;
	cin >> n;
	while(n!=0){
		int data;
		stack<int>stack_in;
		int *tab = new int[n];
		for(int i=n-1;i>=0;i--){
			cin >> data;
			tab[i]=data;		//Because input is reversed so i need to bring it to right order.
		}
		for(int i=0;i<n;i++){
			stack_in.push(tab[i]);
		}
		delete(tab);
		if(check_if_possible(stack_in,n)){
			results.push_back("yes");
			//cout << "yes" << endl;
		}
		else{
			results.push_back("no");
			//cout << "no" << endl;
		}
		cin >> n;
	}
	for(int i=0;i<results.size();i++){
		cout << results[i] << endl;
	}
}

int main(){
	get_data();
	return 0;
}
