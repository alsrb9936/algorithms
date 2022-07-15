#include <bits/stdc++.h>
using namespace std;

int board[101][101];
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
int N, M;

void BFS(int posy, int posx){
    //시작 
    queue<pair<int,int>> q;
    q.push({posy, posx});
    board[posy][posx] = 0;

    while(!q.empty()){
        pair<int,int> cur = q.front(); q.pop();
        for(int i=0; i<4; ++i){
            //현재 좌표에서의 움직임
            int ny = dy[i] + cur.first;
            int nx = dx[i] + cur.second;

            //범위를 벗어난 이동인지 확인, 방문기록 확인
            if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if(board[ny][nx]!=1) continue;

            q.push({ny,nx});
            //방문기록과 탐색 순서 동시 저장
            board[ny][nx] += board[cur.first][cur.second];
        }
    }
}

int main(){
    cin >> N >> M;

    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            scanf("%1d", &board[i][j]);
        }
    }

    BFS(0,0);
    cout << board[N-1][M-1]+1;
}