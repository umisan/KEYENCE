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
  string s;
  cin >> s;
  for(int i = 0; i < s.size(); i++)
  {
    for(int j = i; j < s.size() - 1; j++)
    {
      string temp = s.substr(0, i + 1);
      temp += s.substr(j + 1, s.size());
      if(temp == "keyence")
      {
        cout << "YES" << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}
