// https://oj.shumeng.tech/p/CSP202609D

#include <bits/stdc++.h>

using ll = long long;
using ull = unsigned long long;
using i128 = __int128_t;

constexpr int inf = 1e9;
constexpr ll linf = 4e18;
constexpr int mod = 998244353;


class DSU {
public:
    std::vector<int> fa;
    int n;
    DSU(int _n) {
        n = _n;
        for(int i = 0; i <= n + 5; i ++) fa.push_back(i);
    }

    int find(int x) {
        if(x == fa[x]) return x;
        return fa[x] = find(fa[x]);
    }

    void merge(int a, int b) {
        int ra = find(a), rb = find(b);
        if(ra == rb) return;
        fa[ra] = rb;
    }
};

class Fenwick {
public:
    std::vector<int> sum;
    int n;

    Fenwick(int _n) {
        n = _n;
        sum.resize(n + 1);
    }

    int lowbit(int x) {
        return x & (-x);
    }

    void modify(int x, int v) {
        for(int i = x + 1; i <= n; i += lowbit(i)) {
            sum[i] += v;
        }
    }

    int query(int x) {
        int ans = 0;
        for(int i = x; i; i -= lowbit(i)) {
            ans += sum[i];
        }
        return ans;
    }

    int query(int l, int r) {
        return query(r) - query(l);
    }
};

void solve() {
    int n, op;
    ll k;
    std::cin >> n >> k >> op;

    std::vector<ll> a(n);
    for(int i = 0; i < n; i ++) std::cin >> a[i];
    std::sort(a.begin(), a.end());

    std::vector<i128> pw;
    for(i128 x = 1; x <= a.back(); x *= k) {
        pw.push_back(x);
    }

    std::vector<ll> band(n);
    for(int i = 0; i < n; i ++) {
        band[i] = std::upper_bound(pw.begin(), pw.end(), (i128)a[i]) - pw.begin() - 1;
    }

    if(op == 0) {
        bool ok = 0;
        for(int i = 0; i < n; i ++) {
            i128 x = (i128)a[i] * k;
            auto it = std::lower_bound(a.begin(), a.end(), x);
            
            if(it != a.end() && (i128)*it == x) {
                ok = 1;
                break;
            }
        }

        if(!ok) {
            std::cout << 1 << '\n';
            std::cout << n << ' ';
            for(int i = 0; i < n; i ++) std::cout << a[i] << " ";
            std::cout << '\n';
        }

        else {
            std::array<std::vector<ll>, 2> ans;
            for(int i = 0; i < n; i ++) {
                ans[band[i] % 2].push_back(a[i]);
            }

            std::cout << 2 << '\n';
            for(int i = 0; i < 2; i ++) {
                std::cout << ans[i].size() << ' ';
                for(auto x : ans[i]) {
                    std::cout << x << ' ';
                }
                std::cout << '\n';
            }
            
        }

        return;
    }

    Fenwick tr[2] = {Fenwick(n), Fenwick(n)};
    DSU s(n);

    std::vector<std::array<int, 4>> seg;
    for(int i = 0; i < n; i ++) {
        int l1, r1, l2, r2;
        l1 = std::upper_bound(a.begin(), a.end(), a[i] / (k + 1)) - a.begin();
        r1 = std::upper_bound(a.begin(), a.end(), a[i] / k) - a.begin();

        l2 = std::lower_bound(a.begin(), a.end(), (i128)a[i] * k) - a.begin();
        r2 = std::lower_bound(a.begin(), a.end(), (i128)a[i] * (k + 1)) - a.begin();

        seg.push_back({l1, r1, l2, r2});
    }

    bool flag = 0;

    std::vector<int> c(n, -1);

    auto dfs = [&](auto& self, int u, int cc) -> bool {
        c[u] = cc;
        s.fa[u] = s.find(u + 1);

        tr[cc].modify(u, 1);

        auto [l1, r1, l2, r2] = seg[u];
        if(l1 < r1 || l2 < r2) {
            flag = 1;
        }

        if(tr[cc].query(l1, r1) ||
           tr[cc].query(l2, r2)) {
            return false;
        }

        int v = s.find(l1);

        while(v < r1) {
            if(!self(self, v, cc ^ 1)) return false;
            v = s.find(v);
        }

        v = s.find(l2);

        while(v < r2) {
            if(!self(self, v, cc ^ 1)) return false;
            v = s.find(v);
        }

        return true;
    };
    
    bool ok = 1;
    for(int i = 0; i < n; i ++) {
        if(c[i] != -1) continue;
        ok = dfs(dfs, i, 0);
        if(!ok) {
            break;
        }
    }

    if(ok) {
        if(!flag) {
            std::cout << 1 << '\n';
            std::cout << n << " ";
            for(int i = 0; i < n; i ++) std::cout << a[i] << " ";
            std::cout << '\n';

            return;
        }
        std::array<std::vector<ll>, 2> ans;
        for(int i = 0; i < n; i++) {
            ans[c[i]].push_back(a[i]);
        }

        std::cout << 2 << '\n';
        for(int i = 0; i < 2; i ++) {
            std::cout << ans[i].size() << ' ';
            for(auto x : ans[i]) std::cout << x << ' ';
            std::cout << '\n';
        }
    }
    else {
        std::array<std::vector<ll>, 3> ans;
        for(int i = 0; i < n; i++) {
            ans[band[i] % 3].push_back(a[i]);
        }

        std::cout << 3 << '\n';
        for(int i = 0; i < 3; i ++) {
            std::cout << ans[i].size() << ' ';
            for(auto x : ans[i]) std::cout << x << ' ';
            std::cout << '\n';
        }
    }
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
