/* Euler Totient Function */
#define MAX 10000000

int phi[MAX];
bool pr[MAX];

void totient() {
  for (int i = 0; i < MAX; ++i) {
    phi[i] = i;
    pr[i] = true;
  }
  for (int i = 2; i < MAX; ++i) {
    if (pr[i]) {
      for(int j = i; j < MAX; j+=i){
        pr[j] = false;
        phi[j] = phi[j] - (phi[j] / i);
      }
      pr[i] = true;
    }
  }
}