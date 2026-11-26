// https://codeforces.com/contest/2231/problem/D

#include <bits/stdc++.h>

using ll = long long;
using ull = unsigned long long;
using i128 = __int128_t;

constexpr int inf = 1e9;
constexpr ll linf = 4e18;
constexpr int mod = 998244353;




void solve() {
    ll mn = -2e12;

    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;
    s = " " + s;

    std::vector<ll> a(n + 1), c(n + 1), ans(n + 1);

    for(int i = 1; i <= n; i ++) std::cin >> a[i];
    for(int i = 1; i <= n; i ++) std::cin >> c[i];

    std::vector<int> pre(n + 1, -1);
    for(int i = 1; i <= n; i ++) {
        if(s[i] == '0') pre[i] = i;
        else pre[i] = pre[i - 1];
    }

    ans = a;
    ll sum = 0;

    for(int i = 1; i <= n; i ++) {
        if(s[i] == '0') {
            if(i == 1 || c[i] > c[i - 1]) {
                ans[i] = c[i] - sum;
            }
            else {
                ans[i] = mn;
            }

            sum += ans[i];
        }
        else {
            if(i > 1 && c[i] > c[i - 1]) {
                if(c[i - 1] + a[i] < c[i]) {
                    std::cout << "NO\n";
                    return;
                }

                int ind = pre[i - 1];

                if(ind != -1) {
                    ll d = c[i - 1] - sum;
                    ans[ind] += d;
                    sum += d;
                    ll delta = c[i - 1] + a[i] - c[i];
                    ans[ind] -= delta;
                    sum -= delta;
                }
            }

            sum += a[i];
        }
    }

    sum = 0;
    ll mx = -linf;

    for(int i = 1; i <= n; i ++) {
        if(s[i] == '1' && ans[i] != a[i]) {
            std::cout << "NO\n";
            return;
        }

        sum += ans[i];
        mx = std::max(mx, sum);
        if(mx != c[i]) {
            std::cout << "NO\n";
            return;
        }
    }

    std::cout << "YES\n";
    for(int i = 1; i <= n; i ++) {
        std::cout << ans[i] << " ";
    }
    std::cout << "\n";
}


int main() { 
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int t = 1;
    std::cin >> t;
    while(t --) {
        solve();
    }
}
