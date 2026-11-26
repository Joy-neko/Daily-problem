// https://codeforces.com/contest/1620/problem/E

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using i128 = __int128_t;

constexpr int inf = 1e9;
constexpr ll linf = 4e18;
constexpr int mod = 998244353;

int f[500005];

struct node {
    int op, x, y;
};

void solve() {
    int q;
    std::cin >> q;

    std::vector<node> a(q + 1);
    for(int i = 1; i <= q; i ++) {
        int op;
        std::cin >> op;
        if(op == 1) {
            int x;
            std::cin >> x;

            a[i].op = op, a[i].x = x;
        }

        else {
            int x, y;
            std::cin >> x >> y;
            a[i].op = op, a[i].x = x, a[i].y = y;
        }
    }

    std::vector<int> ans;

    std::iota(f, f + 500001, 0);
    for(int i = q; i >= 1; i --) {
        if(a[i].op == 1) {
            ans.push_back(f[a[i].x]);
        }
        else {
            f[a[i].x] = f[a[i].y];
        }
    }

    std::reverse(ans.begin(), ans.end());
    for(auto x : ans) std::cout << x << " ";

    std::cout << '\n';
}


int main() { 
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int t = 1;
    //std::cin >> t;
    while(t --) {
        solve();
    }
}
