#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <math.h>

using namespace std;
using ll = long long int;

int main()
{
  int n;
  cin >> n;
  vector<ll> a(n);
  vector<ll> b(n);
  for(int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  for(int i = 0; i < n; i++)
  {
    cin >> b[i];
  }

  //可能性の判定
  ll rest = 0;
  ll lack = 0;
  vector<ll> rest_sub;
  int lack_count = 0;
  for(int i = 0; i < n; i++)
  {
    if(a[i] >= b[i])
    {
      rest += a[i] - b[i];
      rest_sub.push_back(a[i] - b[i]);
    }else{
      lack += b[i] - a[i];
      lack_count++;
    }
  }
  if(rest - lack < 0)
  {
    cout << -1 << endl;
    return 0;
  }
  if(lack == 0)
  {
    cout << 0 << endl;
    return 0;
  }

  //最小を計算
  sort(rest_sub.begin(), rest_sub.end());
  reverse(rest_sub.begin(), rest_sub.end());
  vector<ll> sum(rest_sub.size(), 0);
  sum[0] = rest_sub[0];
  for(int i = 1; i < rest_sub.size(); i++)
  {
    sum[i] = sum[i - 1] + rest_sub[i];
  }
  for(int i = 0; i < rest_sub.size(); i++)
  {
    if(lack <= sum[i])
    {
      cout << lack_count + i + 1 << endl;
      break;
    }
  }
  return 0;
}
