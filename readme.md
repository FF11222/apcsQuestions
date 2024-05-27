# 這裡會寫我的解題過程

## 2024/04/22 [血緣關係](https://zerojudge.tw/ShowProblem?problemid=b967)
![img.png](source/img0.png)


首先我的想法就是bfs兩次，具體的作法是任意找一點做bfs，以此找到最深的點，然後再從最深的點做bfs到另一個最深的點， 並計算他們之間的距離。

### 遇到的問題:
1. 我一開始只用有向圖的方式去存，這樣bfs時會發生父節點無法遍歷
   1. 解決方法:既然有向圖會出問題，那就做成無向圖!
2. 怎麼計算距離?
   1. 我一開始想說我在每一個點遍歷鄰居完後加一個-1以表示一層 ，然後計算-1的數量當作兩點之間的距離，可是這會出現一個問題
   ，就是葉節點也會推入-1所以就無法得知真實距離
   ```cpp
   while (!bfs.empty()) {
        int temp = bfs.front();

        if (temp == -1) {
            counter++;
            bfs.pop();
            temp = bfs.front();
        }
        bfs.pop();

        for(int i : relationTree[temp]) {
            if (!visited[i]) {
                bfs.push(i);
                visited[i] = true;
            }
        }
        
        bfs.push(-1);
    }
   ```
   #### **最終解法:**
   我最後在書上看到了一種方法，也就是我現在用的方法，就是紀錄每個點跟開始的點的距離，每當向下一層去時，下一層的距離就是這一層的距離加一
   ```cpp
   while (!bfs.empty()) {
        int temp = bfs.front();
        bfs.pop();

        for(int i : relationTree[temp]) {
            if (!visited[i]) {
                bfs.push(i);
                visited[i] = true;
                distance[i] = distance[temp]+1;
            }
        }
    }
   ```
#### 完成時間: 2024/04/28

## 2024/04/29 [樹狀圖分析](https://zerojudge.tw/ShowProblem?problemid=c463)
![img.png](source/img1.png)
題目有兩個要求(找根節點和H(T))
1. 首先根節點我是直接利用set，先將所有點加入set，將每個輸入的子節點移除，最後剩下的就是根節點。
2. H(T)我原本想說直接從根節點dfs，然後計算每個點與根節點的距離，但題目的意思是計算每個節點到葉節點且為自己的子孫節點的距離。
因此要將做法改為從每一個葉節點開始dfs每個點取最大值。
```cpp
 vector<int> h(n+1, 0);
 for (auto leafPoint : leaf) {
     stack<int> dfs;
     dfs.push(leafPoint);

     vector<bool> visited(n+1, false);
     vector<int> distance(n+1, 0);
     visited[dfs.top()] = true;

     while (!dfs.empty()) {
         int temp = dfs.top();
         dfs.pop();
         if (temp == root) break;

         for (auto i : tree[temp]) {
             if (!visited[i]) {
                 visited[i] = true;
                 dfs.push(i);
                 distance[i] = distance[temp] + 1;
                 if (distance[i] > h[i]) h[i] = distance[i];
            }
        }
    }
 }
```
   1. 其中有一些細節需要注意:
      1. 由於此題是以1為底的，因此陣列長度要注意，而且for迴圈的次數也要注意。
#### 完成時間:2024/05/04

## 2024/05/05 [矩陣轉換](https://zerojudge.tw/ShowProblem?problemid=b965)
![](C:\Users\tingy\Documents\apcsQuestions\source\img2.png)
這題的題目有兩種對矩陣的操作-翻轉跟旋轉。

我首先的想法就是直接模擬旋轉跟翻轉的操作。
1. 旋轉:
![](source/img3.png)
在看題目的過程中，我發現了一個規律(左邊的矩陣稱為旋轉後的，右邊的稱為旋轉前) 

   `旋轉後的矩陣的第i,j個元素等於旋轉前的矩陣的第j,abs(i-row+1)個元素 `
2. 翻轉:
翻轉就恨簡單了，只要前後交換就好。

其中我有遇到一個小問題，就是在旋轉那邊，複製矩陣時，我原本是直接
```cpp
vector<vector<int>> temp = martrix;
martrix.clear();
```
然後再直接對原本的矩陣操作，但是這樣會直接炸開，所以我之後改成
```cpp
vector<int> a(matrix1.size());
vector<vector<int>> temp(matrix1[0].size(), a);
matrix1.swap(temp);
```
這樣就沒問題了。
#### 完成時間2024/05/12

## 2024/05/13 [磁軌移動序列](https://zerojudge.tw/ShowProblem?problemid=k733)
題目中有三種指令:T(後面接著的兩位數為磁軌移動到的位置),L(代表迴圈開始，後面接著的數字為重複次數),E(代表迴圈結束)。
這題最麻煩的是迴圈中還有迴圈
我一開始的想法是像處理四則運算的括號一樣用stack去處理，但是這樣會造成外面的迴圈無法記錄到內層迴圈的變更。
```cpp
void deloop() {
    stack<pair<int, int>> loop;
    string temp = command;
    command = "";

    for (int i = 0; i < temp.size(); i++) {
        if (temp[i] == 'L') {
            loop.push(make_pair(i+2, temp[i+1]-'0'));
            i++;
        } else if (temp[i] == 'E') {
            for (int j = 0; j < loop.top().second; j++) {
                command += temp.substr(loop.top().first, i-loop.top().first);
            }
            loop.pop();
        } else {
            command += temp[i];
        }
    }
}
```
我之後參考網路上的解法，也就是現在的解法。
#### 完成時間2024/05/21