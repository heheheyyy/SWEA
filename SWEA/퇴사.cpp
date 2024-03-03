#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
#define x firt
#define y second

int n = 5, m = 5;
int arr[8] = { 1,2,3,4,4 };
bool visited[8];
vector<int> ans(8, 0);

void bt(int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; i++)
            cout << ans[i] << ' ';
        cout << '\n';
        return;
    }

    int prev = 0;
    for (int i = 0; i < n; i++) {
        if (visited[i] == 1 || prev == arr[i]) continue;

        prev = arr[i];


        visited[i] = 1;
        ans[cnt] = arr[i];
        bt(cnt + 1);
        ans[cnt] = 0;
        visited[i] = 0;

    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);

    /*cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> arr[i];*/

    sort(arr, arr + n);

    bt(0);
}