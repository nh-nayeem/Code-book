//precalculate fact up to N
ll inv[N];
inv[N-2] = bigmod(fact[N-2], mod-2);
for(int i=N-3; i>=0; i--) inv[i] = (inv[i+1] * (ll)(i+1)) % mod;
