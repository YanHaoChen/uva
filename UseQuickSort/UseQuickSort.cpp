#include <iostream>
#include <algorithm>
using namespace std;

int compare(const void* p,const void* q){
	return (*(int*)p-*(int*)q);
}

int main(){
	int numCount = 0;
	int tempCount = 0;
	cin >> numCount;
	if (numCount <= 0){
		return 0;
	}
	cin.ignore();
	int arr[numCount];
	while(numCount--){
		cin >> arr[tempCount++];
	}
	cout << "Original:" << endl;
	cout << "[" << arr[0];
	for(int i = 1;i< tempCount;i++){
		cout << "," << arr[i];
	}
	cout << "]" << endl;

	qsort(arr,tempCount,sizeof(int),compare);

	cout << "Sorted:" << endl;
	cout << "[" << arr[0];
	for(int i=1; i<tempCount;i++){
		cout << "," << arr[i];
	}
	cout << "]" << endl;
	return 0;
}
