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

class Solution
{
 public:
  string convert(string s, int numRows)
  {
    if (numRows == 1) return s;

    string ans;                         // The final answer string in zigzag order.
    int cycleLength = 2 * numRows - 2;  // The length of the repeating zigzag cycle.

    // Loop through each row.
    for (int currentRow = 1; currentRow <= numRows; ++currentRow)
    {
      // The interval depends on the current row and alternates within each zigzag cycle.
      int interval = (currentRow == numRows) ? cycleLength : 2 * numRows - 2 * currentRow;
      int currentIndex = currentRow - 1;  // The starting index in the original string for this row.

      // Loop through characters in the row.
      while (currentIndex < s.length())
      {
        ans.push_back(s[currentIndex]);  // Append character to the answer string.
        cout << "val:" << char(s[currentIndex]) << endl;
        currentIndex += interval;           // Move to the next character in the zigzag pattern.
        interval = cycleLength - interval;  // Alternate the interval for the zigzag pattern.

        // The interval should not be zero; if it is, reset it to the cycle length.
        if (interval == 0)
        {
          interval = cycleLength;
        }
      }
    }

    return ans;
  }
};

signed main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  string s;
  cin >> s;
  cout<<"inp:"<<s<<endl;
  fast int n;
  cin >> n;
  Solution sol;
  string result = sol.convert(s, n);
  cout << result << endl;

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec\n";
#endif
  return 0;
}
