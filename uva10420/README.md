# uva10420
每列資料包含了一個國家名稱及一個姓名，統計每個國家的人數，並在輸出時，依國家名稱進行排序。

### 輸入
```shell
3
Spain Donna Elvira
England Jane Doe
Spain Donna Anna
```
### 輸出
```shell
England 1
Spain 2
```

### 使用到

* sstream：切割字串。將國籍字串切割出來。
* set：判斷是否有重複的資料。
* map：存放將要輸出的結果，也利用其特性，直接將國家名稱進行排列。