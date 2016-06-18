#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int a = 123;
	double pi=3.14159,x=-1.83;
	char ch,str[64],line[64];
	int num;
	float value;

	cin >> num;

	cout << setw(8)  << setfill('0') << num << endl;
	return 0;
}
