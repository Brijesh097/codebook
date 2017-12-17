#define MOD 1e9+7
// Modular Arithmetic
int mod (int a, int b) {
	return ((a%b) + b)%b;
}
int add_mod (int a, int b) {
	return (((a%MOD)+(b%MOD))%MOD);
}
// Can use internal __gcd function in C++
int gcd (int a, int b) {
	return b ? gcd(b, a%b):a ;
}
// LCM
int lcm (int a, int b) {
	return a/gcd(a, b)*b;
}
// Power modding (a^b) mod m
int power_mod (int a, int b, int m) {
	int ret = 1;
	while (b) {
		if (b & 1) ret = mod(ret*a, m);
		a = mod(a*a, m); b >>= 1;
	}
	return ret;
}
//Finds x and y such that d = ax + by; returns d
int extended_euclid (int a, int b, int &x, int &y) {  
  int xx = y = 0;
  int yy = x = 1;
  while (b) {
    int q = a/b;
    int t = b; 
    b = a%b; a = t;
    t = xx; xx = x-q*xx; x = t;
    t = yy; yy = y-q*yy; y = t;
  }
  return a;
}
// Chinese Remainder Theorem: Find z such that z % x = a, z % y = b. 
pii chinese_remainder_theorem (int x, int a, int y, int b) {
  int s, t;
  int d = extended_euclid(x, y, s, t);
  if (a%d != b%d) return mp(0, -1);
  return mp(mod(s*b*x + t*a*y, x*y) / d, x*y / d);
}
// Chinese Remainder Theorem: Find z such that z % x[i] = a[i] for all i
pii chinese_remainder_theorem (const vi &x, const vi &a) {
  pii ans = mp(a[0], x[0]);
  for (int i = 1; i < x.size(); i++) {
    ans = chinese_remainder_theorem(ans.first, ans.second, x[i], a[i]);
    if (ans.second == -1) break;
  }
  return ans;
}