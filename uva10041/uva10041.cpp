#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> num;

int main(){
	int doCount;
	cin >>doCount;
	int familyCount;
	while( doCount--) {
		cin >> familyCount;
		num.clear();
		for(int i =0; i<familyCount ;i++){
			int dim;
			dim = 0;
			cin >> dim;
			num.push_back(dim);		
		}
		sort(num.begin(),num.end());
		int mid = num[familyCount/2];
		int sum = 0;
		for(int j = 0;j < familyCount;j++){
			sum += abs(num[j]-mid);
		}	
		cout <<sum <<endl;
	}
	return 0;
}
