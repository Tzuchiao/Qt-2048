C++2048 Homework Readme Report

A. 執行方式：
   下載之後make然後執行
B. 遊戲方式：
   使用Arrow鍵 , 上下左右去滑動
   堆疊的規則如正常版的2048相同
   如 0 2 2 0 往右邊滑會變成 0 0 0 4
   且在堆疊後會在剩下空格中隨機產生一個2
   如果遇到0 2 4 2 往右邊滑的話 , 因為被4擋住就不會執行
   且0 2 2 2 往右邊滑會變成後方先堆疊 0 0 2 4 不是 0 0 4 2
   
   Score會顯示在LCD上 , 堆疊出一個數字便加上去
   Restart鍵重新開始
   Quit鍵即退出程式

   而到達2048之後 , 會出現WIN圖片 , 也可以繼續Restart或是Quit

C. Code部份
   分為
   main.cpp
   //Gui 控制
   MainWindow.h
   MainWindow.cpp
   //2048堆疊規則與陣列資料
   Data.h
   Data.cpp
 
   在MainWindow Class中
   為GUI的控制
   setcolor函式為設定整體GUI的顏色
   readlowestScore和Writelowest函式為讀寫最低分紀錄
   keyPressEvent函式則是對應按鍵事件的 分為上下左右的移動 還有R作弊技能
   setlabel函式則是最初始化遊戲棋盤格,利用gridlayout和QVector來達到label的串列
   on_push_button_clicked函式是restart按鈕的對應事件 , 重新初始化資料
   on_push_button_clicked函式是quit按鈕的對應事件 , 離開程式

   在Data Class中
   為遊戲方式的控制
   init函式為初始化二維陣列的資料 , 並隨機分配一個2在陣列中 , score分數 , final(達到2048與否) , fullcount(棋盤格是否滿了 , 影響到create函式隨機分配的運作)
   create函式 , 隨機分配2在二維陣列當中 , fullcount滿16之後就不會動作了 , 另外fullcount會在create後+1 , 在merge過一個數字後-1
   stack函式為利用迴圈將數字上下左右移動 , 0 2 2 0 往右stack變為 0 0 2 2
   move函式則是先stack後利用迴圈將數字合併 , 並且合併後再stack一次
   swap函式是交換陣列數字的函式

D. Bonus
   Bonus是lowest score的製作 , 結束之後顯示Win的圖片