#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> relationTree[200000];

int main() {
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;

//        cout << relationTree[a][0];
        relationTree[a].push_back(b);
        relationTree[b].push_back(a);
    }

    queue<int> bfs;
    vector<bool> visited(n, false);
    visited[0] = true;
    bfs.push(0);
    int counter = 0;
    while (!bfs.empty()) {
        int temp = bfs.front();
//        cout << temp << ' ';
        bfs.pop();
        counter++;

        for(int i : relationTree[temp]) {
            if (!visited[i]) {
                bfs.push(i);
                visited[i] = true;
                counter--;
            }
        }
    }
    cout << counter;
}