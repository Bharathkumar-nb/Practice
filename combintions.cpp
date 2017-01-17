#include <iostream>
#include <vector>
#include <tuple>
#include <map>

using namespace std;

class Solution {
  std::map<tuple <int, int, int>, vector<vector<int> > > map;
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int>> combinations;
        
        combinations = find_combinations(1, n, k);

        return combinations;
    }

    vector<vector<int> > find_combinations(int begin, int n, int k)
    {
      vector<vector<int>> combinations;
      if (k==1)
      {
        for (int i = begin; i <= n; ++i)
        {
          combinations.push_back({i});
        }
      }
      else{
        vector<vector<int>> temp;
        int len;
        for (int i = begin; i <= n-k+1; ++i)
        {
          if (map.find(make_tuple(i+1,n,k-1)) == map.end())
          {
            temp = find_combinations(i+1, n, k-1);
          }
          else
          {
            temp = map[make_tuple(i+1,n,k-1)];
          }
          len = temp.size();
          for (int j = 0; j<len; ++j)
          {
            temp[j].insert(temp[j].begin(), i);
            combinations.push_back(temp[j]);
          }
        }
      }
      
      map[make_tuple(begin, n, k)] = combinations;
      return combinations;
    }
};

int main(int argc, char const *argv[])
{
  //Solution::combine(3,2);
  return 0;
}