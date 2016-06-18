#include <iostream>

using namespace std;

void divide(int nb,int arr[],int &cnt){
	for(cnt=0; nb!=0 ;cnt++){
		arr[cnt] = nb % 10;
		nb /=10;
	}
}

int main() {
	int nb1,nb2;
	while(cin>>nb1>>nb2 && (nb1 != 0 || nb2 != 0)){
		int len1,len2;
		int array1[11]={},array2[11]={};
		int arraySum[12]={};
		divide(nb1,array1,len1);
		divide(nb2,array2,len2);
		int maxL=max(len1,len2);
		int ans = 0;
		for (int i=0;i<maxL;i++){
			arraySum[i] = array1[i]+array2[i];
			if (arraySum[i]>=10){
				arraySum[i+1]++;
				ans++;
			}
		}
		if(ans==0){
			cout<<"No carry operation.\n"<<endl;
		}else if(ans==1){
			cout<<"1 carry operation.\n"<<endl;
		}else {
			cout<<ans<<" carry operations.\n"<<endl;
		}
	}
	return 0;
}
