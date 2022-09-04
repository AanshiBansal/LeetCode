class Solution {
private:
    vector<int> res;
    void dfs(int num, int n, int k) {
      if (n == 0)
          res.push_back(num);
      else {
          int dig = num % 10;
          if (dig + k <= 9)
              dfs(num * 10 + dig + k, n - 1, k);
          if (k!=0 && dig >= k)
              dfs(num * 10 + dig - k, n - 1, k);
        }
    }
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        for (int num = 1; num <= 9; num++) 
            dfs(num, n - 1, k);
        return res;
    }
};