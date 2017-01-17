class Solution {
public:

  bool isPal(const string &s, int begin, int end)
  {
    while(begin < end){
      if(s[begin--] != s[end--])
        return false;
    }
    return true;
  }

  vector<vector<string> > partition(string s) {
    
  }
};