#include <iostream>
#include <algorithm>
using namespace std;

int n,m;


bool cmp(int a,int b){
	int aOdd = abs(a%2);
	int bOdd = abs(b%2);
	if (a%m != b%m) return a%m < b%m;
	else if(aOdd != bOdd) return aOdd > bOdd;
	else if(aOdd) return  a > b;
	else return a < b; 
}

int main(){
	int arr[10000];
	while(cin >> n >> m){
		cout << n << " " << m << endl;
		if(n==0)
			break;
		for(int i=0; i < n;i++)
			cin >> arr[i];
		sort(arr,arr+n,cmp);
		for(int i=0;i<n;i++)
			cout << arr[i] << endl;
	}
	return 0;
}
