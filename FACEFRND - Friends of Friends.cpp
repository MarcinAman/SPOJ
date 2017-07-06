#include <iostream>
#include <vector>

using namespace std;

bool check_if_in_vector(vector<int>& arr,int value){
	for(int i=0;i<arr.size();i++){
		if(arr[i]==value) return true;
	}
	return false;
}
bool check_if_in_arr(int *arr, int size, int value){
	for(int i=0;i<size;i++){
		if(arr[i]==value) return true;
	}
	return false;
}


int get_values(int size){
	//first arr is an array with bob's friends
	int current_id,current_size,id,dif_ids=0;
	int *first_arr = new int[size];
	vector<int>f_of_f; //f_of_f are friends of friends ids
	for(int i=0;i<size;i++){
		scanf("%d%d",&current_id,&current_size);
		first_arr[i]=current_id;
		for(int j=0;j<current_size;j++){
			scanf("%d",&id);
			if(!check_if_in_vector(f_of_f,id)){ //it is possible to be in a f_of_f and be a bob's friend
				f_of_f.push_back(id);
			}
		}		
	}
	for(int i=0;i<f_of_f.size();i++){
		if(check_if_in_arr(first_arr,size,f_of_f[i])){
			f_of_f[i]=-1;
		}
	}
	for(int i=0;i<f_of_f.size();i++){
		if(f_of_f[i]!=-1) dif_ids++;
	}
	delete(first_arr);
	return dif_ids;
}


int main(){
	int size;
	scanf("%d",&size);
	printf("%d",get_values(size));
	return 0;
}
