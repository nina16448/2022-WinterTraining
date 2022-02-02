#include <iostream>
#include <queue>
#include <vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long lint;
int N, n, ID, t, ansp, ansm;
int graph[110][110];

void greedy(){
    for(int k = 1; k <= N; k++){
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> N && N){
        for(int i = 0; i < 110; i++){
            for(int j = 0; j < 110; j++){
                graph[i][j] = 0x3f3f3f3f;
                if(i == j) graph[i][j] = 0;
            }
        }

        for(int i = 1; i <= N; i++){
            cin >> n;
            while(n--){
                cin >> ID >> t;
                graph[i][ID] = t;
            }
        }

        greedy();

        ansm = 0x3f3f3f3f;
        for(int i = 1; i <= N; i++){
            int rec = 0;
            for(int j = 1; j <= N; j++){
                rec = max(rec, graph[i][j]);
            }
            if(rec < ansm){
                ansm = rec;
                ansp = i;
            }
        }

        if(ansm == 0x3f3f3f3f) cout << "disjoint\n";
        else cout << ansp << " " << ansm << "\n";
    }

    return 0;
}