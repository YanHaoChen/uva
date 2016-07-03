#include <iostream>
#include <sstream>
#include <map>
#include <set>
using namespace std;

int main(){
	map<string,int> count;
	map<string,int>::iterator iter;
	set<string> exist;
	stringstream ss;
	string entire_s,frist_s;

	char entire_c[76] = {0};
	int inputCount=0;
	cin >> inputCount;
	cin.ignore();
	while(inputCount--){
		cin.getline(entire_c,76);
		entire_s = entire_c;
		if (exist.count(entire_s) <= 0){
			exist.insert(entire_s);
			ss.str("");
			ss.clear();
			ss << entire_s;
			ss >> frist_s;
			count[frist_s]++;
		}
	}
	for(iter=count.begin();iter != count.end();iter++){
		cout << iter->first << " ";
		cout << iter->second << endl;		
	}
	return 0;
}
