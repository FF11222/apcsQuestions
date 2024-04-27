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
    vector<int> distance(n, 0);
    int furthest;
    while (!bfs.empty()) {
        int temp = bfs.front();
        bfs.pop();

        for(int i : relationTree[temp]) {
            if (!visited[i]) {
                bfs.push(i);
                visited[i] = true;
                distance[i] = distance[temp]+1;
                furthest = i;
            }
        }
    }

    fill(visited.begin(), visited.end(), false);
    fill(distance.begin(), distance.end(), 0);
    visited[furthest] = true;
    bfs.push(furthest);
    int furthestD = -1;
    while (!bfs.empty()) {
        int temp = bfs.front();
        bfs.pop();

        for(int i : relationTree[temp]) {
            if (!visited[i]) {
                bfs.push(i);
                visited[i] = true;
                distance[i] = distance[temp]+1;
                if (distance[i] > furthestD) furthestD = distance[i];
            }
        }
    }

    cout << furthestD;
}