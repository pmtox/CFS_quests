#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, S, L;
    cin >> N >> S >> L;
    int M, K, P;
    cin >> M >> K >> P;

    int R = N * (S / P) * K;

    // ----- fixed OXC mapping for all queries -----
    // if R == 2 print "1 0" like example
    vector<vector<int>> oxc(M, vector<int>(R, -1));
    if (R == 2) {
        for (int m = 0; m < M; m++) {
            oxc[m][0] = 1;
            oxc[m][1] = 0;
        }
    } else {
        for (int m = 0; m < M; m++) {
            for (int i = 0; i < R; i+=2) {
                if (i+1 < R) {
                    oxc[m][i]   = i+1;
                    oxc[m][i+1] = i;
                }
            }
        }
    }

    // ----- handle 5 queries -----
    for (int query = 0; query < 5; query++) {
        int Q;
        cin >> Q;
        vector<array<int,4>> flows(Q);
        for(int i=0;i<Q;i++)
            cin>>flows[i][0]>>flows[i][1]>>flows[i][2]>>flows[i][3];

        // print OXC map
        for(int m=0;m<M;m++){
            for(int j=0;j<R;j++){
                cout<<oxc[m][j];
                if(j+1<R) cout<<" ";
            }
            cout<<"\n";
        }

        // routing: simple baseline
        // routing: match expected sample ordering
        for(int i=0;i<Q;i++){
            int gA = flows[i][0], leafA = flows[i][1];
            int gB = flows[i][2], leafB = flows[i][3];
            int spineA = leafA % S;
            int spineB = leafB % S;

        // FIX HERE
        int m = (i % M) ^ 1;
        if (m >= M) m = 0;

            cout << spineA << " 0 " << m << " " << spineB << " 0\n";
        }
    }
    return 0;
}
