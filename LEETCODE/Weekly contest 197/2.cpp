class Solution {

public:
  int modInverse(int a, int m)
  {
    int m0 = m;
    int y = 0, x = 1;

    if (m == 1)
      return 0;

    while (a > 1)
    {
      // q is quotient
      int q = a / m;
      int t = m;

      // m is remainder now, process same as
      // Euclid's algo
      m = a % m, a = t;
      t = y;

      // Update y and x
      y = x - q * y;
      x = t;
    }

    // Make x positive
    if (x < 0)
      x += m0;

    return x;
  }
  int numSub(string s) {
    long long int count = 0;
    long long int ans = 0;
    long long int mod = 1000000007;
    long long int val = modInverse(2, mod);
    for (int i = 0; i < s.length();)
    {
      count = 0;
      while (i < s.size() && s[i] == '1') {
        i++;
        count++;
      }
      ans += (((count % mod) * (count % mod + 1) % mod) % mod * (val) % mod) % mod;
      if (count == 0)
        i++;
    }
    return ans;
  }
};