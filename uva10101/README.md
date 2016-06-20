# uva-10101 非遞迴式寫法

學習Cpp中，```stack```、```string ```及```iomanip```用法。

## 此題須注意的地方

* 單位跟數字間的空白
* 每題的編號，都須為4個字元

```shell
   1. xxxxxxxxxx
    . xxxxxxxxxx
    . xxxxxxxxxx
    . xxxxxxxxxx
  23. xxxxxxxxxx
```
* 第二輪的單位，如第一輪沒有數值，則需補單位

```shell
input:1234567
   1. 12 lakh 34 hajar 5 shata 67
input:12345678
   2. 1 kuti 23 lakh 45 hajar 6 shata 78
input:123456780034567
   3. 1 kuti 23 lakh 45 hajar 6 shata 78 kuti 34 hajar 5 shata 67
input:123456001234567
   4. 1 kuti 23 lakh 45 hajar 6 shata kuti 12 lakh 34 hajar 5 shata 67
input:123456000000000
   5. 1 kuti 23 lakh 45 hajar 6 shata kuti
```
## 使用到

* stack：利用先進後出的特性，讓最後輸出的結果，符合所需格式。
* string：建立string陣列，儲存錢幣單元，並透過它把字串相加及利用其```to_string```方法，達到數字轉字串的需求。
* iomanip：管理輸出格式，本題在答案輸出時，有需要特別的格式，所以使用到它。

## 程式碼
```cpp
#include <iostream>
#include <string>
#include <stack>
#include <iomanip>
using namespace std;
 
int main(){
    stack<string> ans;
    long long getNum=0;
    //modString為單位名稱
    string modString[] = {" shata"," hajar"," lakh"," kuti"};
    //mod為單位之間，由小到大的差距間隔
    int mod[]={100,10,100,100};
    long long outputCount = 1;
    while (cin >> getNum){
        int modCount = 1;
        int stringModCount = 0;
        
        //因小於100的數值沒有實際單位符號，所以先單獨處理
		//if：如為零，直接將0放入ans中
        if (getNum == 0){
            ans.push(" "+to_string(0));
            
        //else if：如數值不為零，將數值放入ans中
        }else if(getNum % 100 != 0){
            ans.push(" "+to_string(getNum % 100));
        }
        getNum /= 100;
	
		//接下來就是把數值切開並結合單位，放入ans中
        while (getNum){
            int getModNum = 0;
            int nowMod = modCount%4;
            int nowStringMod = stringModCount%4;
            getModNum = getNum % mod[nowMod];
	    
	    	//如數值不為零，就把數值跟單位結合後，放入ans
            if (getModNum != 0){
                ans.push(" "+to_string(getModNum)+modString[nowStringMod]);
	    
	    	//else if的觸發條件
            //1. getModNum == 0 -> 切出來的數值為0
            //2. nowStringMod == 3 -> 單位在kuti
            //3. getNum > 100 -> 還有第二輪的數值存在
	    	//達成以上條件，補上kuti
            }else if (nowStringMod == 3 && getNum > 100){
            		ans.push(" kuti");
            }
            getNum /= mod[nowMod];
            modCount++;
            stringModCount++;           
        }
        
		//設定好答案編號，再把ans的資料都吐出來，就是答案
        cout <<setw(4)<<right<< outputCount++ <<".";
        while(!ans.empty()){
            cout << ans.top();
            ans.pop();
        }
        cout <<endl;
    }   
    return 0;
}
```
