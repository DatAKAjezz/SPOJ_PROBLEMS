#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fil(a,x) memset(a,x,sizeof(a))
typedef pair <int ,int > ii;

const int  INF = 1e9 + 1;
const int max_n = 1e6 + 1;

vector<ii> a[max_n];
ll d[max_n];
ll num[max_n];

void dijkstra(int source){
    fil(d,INF);fil(num,0);
    priority_queue<ii,vector <ii > ,greater<ii>> pq;
    pq.push({0,source});
    d[source] = 0;
    num[1] = 1;
    while (!pq.empty()){
        ii top; top = pq.top();pq.pop();
        int u  = top.second;
        int du = top.first;

        for (int i = 0;i<a[u].size();i++){

            int v = a[u][i].second;
            int dv = a[u][i].first;
            if (d[u] != du) continue;
            if (d[v] > du + dv){

                d[v] = du + dv;
                pq.push(ii(d[v] , v));
                num[v] = num[u];
            }
            else if (d[v] == du + dv){
                    num[v] += num[u];                 }

        }
     }
}

void solve(){

    int n,m; cin >> n >> m;
    for (int i = 0;i<m;i++){

        int k,x,y,w; cin >>k>> x >> y >> w;
        if (k ==1 ){

            a[x].push_back(ii(w,y));

        }else {
            a[x].push_back(ii(w,y));
            a[y].push_back(ii(w,x));

        }

    }
    int u , v; cin >> u >> v;
    dijkstra(1);
    cout << d[n] << " " << num[n];
    //for (auto x : d) if (x<10) cout << x <<" ";
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    solve();

}