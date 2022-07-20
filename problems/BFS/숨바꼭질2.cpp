#include <bits/stdc++.h>
using namespace std;

int vis[100001];
int cnt1, cnt2;
int N,K;

int main(){
    cin >> N >> K;

    if(N == K){
        cout << 0 << '\n' << 1;
        return 0;
    }
    queue<pair<int,int>> q;
    q.push({N,0});

    while(!q.empty()){
        pair<int,int> cur = q.front();q.pop();
        int num = cur.first;
        int level = cur.second;
        vis[num] = 1;

        if(cnt1 == level && num == K) cnt2++;

        if(!cnt1 && num == K) {
            cnt2++;
            cnt1 = level;
            continue;
        }

        for(auto cal: {num + 1, num - 1, num * 2 }){
            if(cal >= 0 && cal <=100001 && vis[cal] == 0 ){
                q.push({cal,level+1});
            }
        }
    }
    cout << cnt1 << '\n' << cnt2;
}