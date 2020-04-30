#include <stdio.h>

void arr_func(int* arr_pt){
	for (int i = 0; i < sizeof(arr_pt); i++){
		printf("%d\n", arr_pt[i]);
	}
}	

int main(){
	int arr[4] = {10, 20, 30};
	int* arr_p = arr;

	//printf("%d %d %d", arr_p[0], arr_p[1], arr_p[2]);
	arr_func(arr);
	return 0;
}
