#include <iostream>
#include <string>
#include <stack>
#include <iomanip>
using namespace std;

int main(){
	stack<string> ans;
	long long getNum=0;
	string modString[] = {" shata"," hajar"," lakh"," kuti"};
	int mod[]={100,10,100,100};
	long long outputCount = 1;
	while (cin >> getNum){
		int modCount = 1;
		int stringModCount = 0;
		if (getNum == 0){
			ans.push(" "+to_string(0));
		}else if(getNum % 100 != 0){
			ans.push(" "+to_string(getNum % 100));
		}
		getNum /= 100;
		while (getNum){
			int getModNum = 0;
			int nowMod = modCount%4;
			int nowStringMod = stringModCount%4;
			getModNum = getNum % mod[nowMod];
			if (getModNum != 0){
				ans.push(" "+to_string(getModNum)+modString[nowStringMod]);
			}else if (nowStringMod == 3 && getNum > 100){
			ans.push(" kuti");
			}
			getNum /= mod[nowMod];
			modCount++;
			stringModCount++;			
		}
		cout <<setw(4)<<right<< outputCount++ <<".";
		while(!ans.empty()){
			cout << ans.top();
			ans.pop();
		}
		cout <<endl;
	}	
	return 0;
}
