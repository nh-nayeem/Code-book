const int mod = 1e9 + 7;
typedef long long ll;
typedef vector<vector<ll> > matrix;
matrix getmat(int r, int c, ll val = 0)
{
    vector<vector<ll> > ret(r, vector<ll>(c, val));
    return ret;
}
matrix Identity(int r)
{
    auto ret = getmat(r, r);
    for (int i = 0; i < r; i++) ret[i][i] = 1;
    return ret;
}
matrix matmal(matrix x, matrix y)
{
    int r1 = x.size(), c1 = x[0].size(), r2 = y.size(), c2 = y[0].size();
    assert(c1 == r2);
    auto  ret = getmat(r1, c2);
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            for (int k = 0; k < r2; k++)
            {
                ret[i][j] += (x[i][k] * y[k][j]) % mod;
                ret[i][j] %= mod;
            }
        }
    }
    return ret;
}
matrix bigmod(matrix x, ll b)
{
    if (b == 0) return Identity(x.size());
    auto ret = bigmod(x, b >> 1);
    ret = matmal(ret, ret);
    if (b & 1) ret = matmal(ret, x);
    return ret;
}
