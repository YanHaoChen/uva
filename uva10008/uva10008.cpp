#include <iostream>
#include <cctype>
using namespace std;

int main(){
	char c;
	int count[256]={0};
	int len = 0;
	while(cin >> c){
		len++;
		count[toupper(c)]++;
	}
	while(--len){
		for(char i = 'A'; i <= 'Z';i++){
			if(count[i] == len){
				cout << i << " " << count[i] << endl; 
			}
		}
	}
	return 0;
}
