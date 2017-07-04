//Marcin Aman
//http://www.spoj.com/problems/AMR10G/
#include <iostream>
#include <math.h>
using namespace std;

void print_array(int *arr,int size){
	for(int i=0;i<size;i++){
		cout << arr[i] <<" ";
	}
	cout << endl;
}

void mergetwo(int a, int b, int *&tab, int *&tab_d) {
	int middle = (b + a) / 2;
	int pointer = a;
	int current_a = a;
	int current_mid = middle;
	while (pointer != b) {
		if (current_a == middle) {
			while (current_mid != b) {
				tab_d[pointer] = tab[current_mid];
				current_mid++;
				pointer++;
			}
		}
		else if (current_mid == b) {
			while (current_a != middle) {
				tab_d[pointer] = tab[current_a];
				pointer++;
				current_a++;
			}
		}
		else {
			if (tab[current_a]>tab[current_mid]) {
				tab_d[pointer] = tab[current_mid];
				pointer++;
				current_mid++;
			}
			else {
				tab_d[pointer] = tab[current_a];
				pointer++;
				current_a++;
			}
		}
	}
	for (int j = a; j<b; j++) {
		tab[j] = tab_d[j];
	}
}


void mergesort(int a, int b, int *&tab, int *&tab_d) {
	if (a + 1<b) {
		int sr = (b + a) / 2;
		mergesort(a, sr, tab, tab_d);
		mergesort(sr, b, tab, tab_d);
		mergetwo(a, b, tab, tab_d);
	}
}

int diff(int *arr, int l, int r){
	//cout << "from: " << arr[l] << " to: " << arr[r] << endl; 
	int min = arr[l], max=arr[l];
	for(int i=l;i<=r;i++){
		if(arr[i]>max){
			max=arr[i];
		}
		else if(arr[i]<min){
				min=arr[i];
		}
	}
	//cout << "max= " << max << " min= " << min << endl;
	return (max-min);
}

int get_input(int size,int req){
	int data;
	int *arr = new int [size];
	int *arr2 = new int[size];
	for(int i=0;i<size;i++){
		cin>>data;
		arr[i]=data;
	}
	if(req==1 or req == 0) return 0;
	req--;
	mergesort(0,size,arr,arr2);
	delete(arr2);
//	print_array(arr,size);
	int min_diff = diff(arr,0,req);
	for(int i=0;i<size-req;i++){
		int current_diff = diff(arr,i,i+req);
		if(current_diff<min_diff){
			min_diff=current_diff;
		}
	}
	delete(arr);
	return min_diff;
}

int main(){
	int cases,K,N;
	cin >> cases;
	int *results = new int[cases];
	for(int i=0;i<cases;i++){
		cin >> K >> N;
		results[i]=get_input(K,N);
	}
	for(int i=0;i<cases;i++){
		cout << results[i] << endl;
	}
	delete(results);
	return 0;
}
