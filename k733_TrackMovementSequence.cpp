#include <bits/stdc++.h>
#define ull unsigned long long
#define pii pair<long long, long long>
using namespace std;

string command;

ull solve() {
    ull mul = 1;
    stack<pii> stack;//第一個數字, 次數
    int now = 10;
    ull ans = 0;

    for (int i = 0; i < command.size(); i++) {
        if (command[i] == 'T') {
            int next = stoi(command.substr(i+1, 2));
            vector<pii> temp;
            ans += abs(next - now) * mul;
            while (!stack.empty() && stack.top().first == -1) {
                temp.push_back({next, stack.top().second});
                mul *= stack.top().second;
                stack.pop();
            }
            reverse(temp.begin(), temp.end());
            for (auto j : temp) {
                stack.push(j);
            }
            now = next;
            i+=2;
        } else if (command[i] == 'L') {
            int times = (int)(command[i+1]-'0');
            stack.push({-1, times});
            i++;
        } else if (command[i] == 'E') {
            int times = stack.top().second;
            int num = stack.top().first;

            mul /= times;
            ans += abs(now - num) * (times-1) * mul;
            stack.pop();
        }
    }
    return ans;
}

int main() {
    cin >> command;

    cout << solve();
    return 0;
}