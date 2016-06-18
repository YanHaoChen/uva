#include <iostream>
using namespace std;

int lenCount(int num){
         int len = 1;
         while (num != 1){
                 if (num % 2) {
                         num = num * 3 + 1;
                 }else{
                         num /= 2;
                 }
                 len++;
         }
         return len;
}
int main() {
	int a,b;
	while (cin >> a >> b) {
		cout << a << " " << b << " ";
		int maxNum,minNum;
		if (a >= b) {
			maxNum = a;
			minNum = b;
		}else {
			maxNum = b;
			minNum = a;
		}
		int maxLen = 0;
		for (int i = minNum; i <= maxNum; i++){
		   	int tmpLen = lenCount(i);
			maxLen = tmpLen > maxLen ? tmpLen : maxLen; 		
		}
		cout << maxLen <<endl;
	}
}

