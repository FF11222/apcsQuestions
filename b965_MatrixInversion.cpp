#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> matrix1;

void spin() {
    vector<int> a(matrix1.size());
    vector<vector<int>> temp(matrix1[0].size(), a);
    matrix1.swap(temp);

    int column = temp.size(), row = temp[0].size();
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            matrix1[i][j] = temp[j][abs(i-row+1)];
        }
    }
}

void flip() {
    for (int i = 0; i * 2 < matrix1.size(); i++) {
        for (int j = 0; j < matrix1[0].size(); j++) {
            swap(matrix1[i][j], matrix1[matrix1.size()-i-1][j]);
        }
    }
}

int main() {
    int row, column, m;
    cin >> row >>  column >> m;

    for (int i = 0; i < row; i++) {
        vector<int> temp;
        for (int j = 0; j < column; j++) {
            int a;
            cin >> a;
            temp.push_back(a);
        }
        matrix1.push_back(temp);
    }

    bool inversion[m];
    for (int i = m-1; i >= 0; i--) {
        cin >> inversion[i];
    }


    for (auto i : inversion) {
        i ? flip() : spin();
    }

    int i, j;
    string ans;
    for (i = 0; i < matrix1.size(); i++) {
        for (j = 0; j < matrix1[0].size(); j++) {
            ans += to_string(matrix1[i][j]);
            ans += ' ';
        }
        ans.pop_back();
        ans += '\n';
    }

    cout << i << ' ' << j << '\n' << ans;
}