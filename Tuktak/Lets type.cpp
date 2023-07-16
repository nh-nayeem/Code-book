ll, pb, mk, ff, ss, inf, N, mod (careful, with value 0), vi, pii, all(v), 

FastIO: ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

Debugger:

#define error(args...){string _s=#args;replace(_s.begin(),_s.end(),',',' ');stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it,args);}
void err(istream_iterator<string>it){cout<<endl;}
template<class H,class... T>void err(istream_iterator<string>it,H a,T... t){cerr<<*it<<" = "<<a<<" | ";err(++it,t...);}
template<class S,class T>ostream&operator<<(ostream&os,pair<S,T>p){os<<"["<<p.first<<", "<<p.second<<"]";return os;};
template<class T>auto&operator<<(ostream& os,vector<T>_v){bool a=1;for(auto x:_v){os<<(a?"":" ")<<x;a=0;}return os;}
template<class T>auto &operator<<(ostream& os,set<T>_s){for(auto x:_s){os<<x<<" ";}cout<<endl;return os;}


#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

//faster IO
inline int getint(){
    char ch = getchar(); int x = 0;
    while(ch < '0' || ch > '9') ch = getchar();
    while(ch >= '0' && ch <= '9'){
        x = x * 10 + ch - '0'; ch = getchar();
    }
    return x;
}
