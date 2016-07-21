#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
	string getString;
	//long long int getNum = 0;
	int nowNum = 0;
	bool status = 1;
	while (cin >> getString && getString != "0"){
		cout << getString << " ";
		int strLen = getString.length();
		const char *getNum = getString.c_str();
		for (int i = 0 ; i<strLen; i++){
			if (status) {
				nowNum += getNum[i] - 48; 
			}else{
				nowNum -= getNum[i] - 48;
			}
			status = !status;
		}
		if ((abs(nowNum) % 11) == 0) {
			cout << "is a multiple of 11." << endl;
		} else {
			cout << "is not a multiple of 11." << endl;
		}
		nowNum = 0;
		status = 1;
	}
	return 0;
}
