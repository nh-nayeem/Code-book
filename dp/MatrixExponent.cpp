using ll = long long;
int mod = 1;
const int N = 3;
void make_identity(int a[][N]) {
    memset(a, 0, N * N * sizeof(int));
    for (int i = 0; i < N; i++) a[i][i] = 1;
}
void matmal(int a[][N], int b[][N]) {
    int c[N][N] = {{0}};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                c[i][j] = (c[i][j] + (a[i][k] * 1ll * b[k][j]) % mod);
                if (c[i][j] >= mod) c[i][j] -= mod;
            }
        }
    } 

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            a[i][j] = c[i][j];
        }
    }
}
const int base = 10000;
const int nd = 5;
int pw[nd + 1][base][N][N];
int fib[200], sz;
void pre() {
    memset(pw, 0, sizeof(pw));
    mod = 1000000;
    pw[0][0][1][0] = 1;
    pw[0][0][2][1] = 1;
    pw[0][0][0][2] = pw[0][0][1][2] = pw[0][0][2][2] = 1;
    for (int i = 0; i <= nd; i++) {
        if (i) {
            make_identity(pw[i][0]);
            for (int j = 1; j <= base; j++) {
                matmal(pw[i][0], pw[i - 1][0]);
            }
        }
        for (int j = 1; j < base; j++) {
            for (int x = 0; x < N; x++) {
                for (int y = 0; y < N; y++) {
                    pw[i][j][x][y] = pw[i][j - 1][x][y];
                }
            }
            matmal(pw[i][j], pw[i][0]);
        }
    }
    fib[1] = 1;
    fib[2] = 2;
    fib[3] = 3;
    for (int i = 4; ; i++) {
        fib[i] = fib[i - 1] + fib[i - 2] + fib[i - 3];
        if (fib[i] > 1000000) break;
        sz = i;
    }
}
void mat_expo(int t[][N], ll y) {
    for (int i = 0; i <= nd; i++) {
        int x = y % base;
        y /= base;
        if (x > 0) {
            matmal(t, pw[i][x - 1]);
        }
    }
}
