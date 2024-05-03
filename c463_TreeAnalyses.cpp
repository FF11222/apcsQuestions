#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> tree[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    vector<int> leaf;
    set<int> isRoot;

    for (int i = 1; i <= n; i++) isRoot.insert(i);
    for (int i = 1; i <= n; i++) {
        int k, temp;
        cin >> k;
        if (k == 0) {
            leaf.push_back(i);
            continue;
        }
        for (int j = 0; j < k; j++) {
            cin >> temp;
            tree[temp].push_back(i);
            isRoot.erase(temp);
        }
    }

    int root;
    for (auto i : isRoot) {
        cout << i;
        root = i;
    }

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

    int hTotal = 0;
    for (int i : h) {
        hTotal+=i;
    }
    cout << '\n' << hTotal;
}