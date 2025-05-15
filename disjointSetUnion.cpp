// ######      ###      #######    #######    ##     #     #####        ###     ##### //
// #     #    #   #          #        #       # #    #    #     #      #   #     ###  //
// #     #   #     #        #         #       #  #   #   #       #    #     #    ###  //
// ######   #########      #          #       #   #  #   #           #########    #   //
// #     #  #       #     #           #       #    # #   #    ####   #       #    #   //
// #     #  #       #    #            #       #     ##   #    #  #   #       #        //
// ######   #       #   #######    #######    #      #    #####  #   #       #    #   //

#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> ppl;
#define ain(a, n) \
  for (ll i = 0; i < (n); ++i) cin >> (a)[i];
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define loop(i, n) for (ll i = 0; i < (n); ++i)
#define FOR(i, a, b) for (ll i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (ll i = (a); i >= (b); --i)
#define cases \
  ll T = 0;   \
  cin >> T;   \
  while (T--)
#define ff first
#define ss second
#define all(v) v.begin(), v.end()
#define END "\n"
#define pb push_back
#define mp make_pair
#define go(c, itr) for (auto itr = (c).begin(); itr != (c).end(); ++itr)
// #define back(c,itr) for(auto itr=(c).rbegin(); itr!=(c).rend(); ++itr)
#define PI 3.14159265359
#define inf 9e18
#define MOD 1000000007
#define MODU 998244353
#define fast                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL);
#define MAXN 1000005
const string alpha = "abcdefghijklmnopqrstuvwxyz";
const ll N = 1005;
const long double epsilon = 1e-9;

// Utility Functions
ll binexp(ll a, ll b, ll m)
{
  a %= m;
  ll res = 1;
  while (b > 0)
  {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}

ll modinvfermat(ll a, ll m)
{
  return binexp(a, m - 2, m);
}

void task(bool flag)
{
  if (flag)
    cout << "YES\n";
  else
    cout << "NO\n";
}

ll lcm(ll a, ll b)
{
  return ((1LL * a * b) / (__gcd(a, b)));
}

// // Solution Class as per your example
// class Solution {
// public:
//     int findNumbers(vl& nums) {
//         int count = 0;
//         for (int i : nums) {
//             // Calculate the number of digits using log10
//             int digit = log10(i) + 1; // log10(n) + 1 gives the number of digits
//             if (!(digit & 1)) { // If the number of digits is even
//                 count++;
//             }
//         }
//         return count;
//     }
// };

class DSU
{
  vector<int> rank, parent, size;

 public:
  DSU(int n)
  {
    rank.resize(n + 1, 0);
    parent.resize(n + 1);
    size.resize(n + 1);
    for (int i = 0; i <= n; i++)
    {
      parent[i] = i;
      size[i] = i;
    }
  }
  int findParent(int node)
  {
    if (node == parent[node]) return node;
    return parent[node] = findParent(parent[node]);
  }
  void findUnionByRank(int a, int b)
  {
    int parent_a = parent[a];
    int parent_b = parent[b];

    if (parent_a == parent_b) return;
    if (rank[parent_a] < rank[parent_b])
    {
      parent[a] = parent_b;
    }
    else if (rank[parent_b] < rank[parent_a])
    {
      parent[b] = parent_a;
    }
    else
    {
      parent[b] = parent_a;
      rank[a]++;
    }
  }
  void findUnionBySize(int a, int b)
  {
    int parent_a = parent[a];
    int parent_b = parent[b];

    if (parent_a == parent_b) return;
    if (size[parent_a] < size[parent_b])
    {
      parent[parent_a] = parent_b;
      size[parent_b] += size[parent_a];
    }
    else
    {
      parent[parent_b] = parent_a;
      size[parent_a] += size[parent_b];
    }
  }
};

signed main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  fast

      DSU ds(7);
  ds.findUnionBySize(1, 2);
  ds.findUnionBySize(2, 3);
  ds.findUnionBySize(4, 5);
  ds.findUnionBySize(6, 7);
  ds.findUnionBySize(5, 6);
  if (ds.findParent(3) == ds.findParent(7))
  {
    cout << "Same" << endl;
  }
  else
    cout << "Not Same" << endl;

  ds.findUnionByRank(3, 7);

  if (ds.findParent(3) == ds.findParent(7))
  {
    cout << "Same" << endl;
  }
  else
    cout << "Not Same" << endl;

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec\n";
#endif
  return 0;
}
