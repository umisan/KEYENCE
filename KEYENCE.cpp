#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <math.h>

using namespace std;
using ll = long long int;
using p = pair<int, ll>;

bool judge(const vector<int> &target)
{
  for(int i = 0; i < target.size(); i++)
  {
    for(int j = 0; j < target.size(); j++)
    {
      if(i == j) continue;
      if(target[i] == target[j]) {
        return false;
      }
    }
  }
  return true;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  vector<int> b(m);
  for(int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  for(int j = 0; j < m; j++)
  {
    cin >> b[j];
  }

  vector<vector<int>> grid(n, vector<int>(m, 0));

  //gridの各マスに条件を設定
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < m; j++)
    {
        grid[i][j] = min(a[i], b[j]);
    }
  }

  for(auto e : grid)
  {
    for(auto e1 : e)
    {
      cout << e1 << "\t";
    }
    cout << endl;
  }

  //各数字をおける場所をカウント
  vector<p> pos(n * m + 1);
  for(int i = 0; i < n * m + 1; i++)
  {
    pos[i] = {i, 0};
  }
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < m; j++)
    {
      int current_reg = grid[i][j];
      pos[current_reg].second++;
    }
  }

  //累積和の計算
  for(int i = n * m - 1; i > 0; i--)
  {
    pos[i].second += pos[i + 1].second;
  }
 
  //不可能性の判定とai == bjとなる場所をaiを探す
  bool can = judge(a);
  map<int, int> only;
  if(!can)
  {
    cout << 0 << endl;
    return 0;
  }
  can = judge(b);
  if(!can){
    cout << 0 << endl;
  }
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < m; j++)
    {
      if(a[i] == b[j])
      {
        only[a[i]] = 1;
      }
    }
  }

  for(auto e : pos){
    //cout << e.first << " " << e.second << endl;
  }

  //数え上げ
  //おけない数字が出たら不可能
  ll result = 1;
  int index = n * m;
  for(int i = n * m; i > 0; i--)
  {
    int possible = pos[i].second - (n * m - i);
    if(possible == 0)
    {
      cout << 0 << endl;
      return 0;
    }
    if(!only.count(i))
    {
      result = (result * possible) % 1000000007;
    }
  }
  cout << result << endl;
  return 0;
}
