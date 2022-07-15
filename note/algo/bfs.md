# 너비 우선 탐색 (Breadth-First Search)
그래프 검색 알고리즘의 하나이다. 
현재 탐색 노드에 연결된 모든 노드들을 탐색후 다음 탐색을 진행한다.   
그래프에서 가장 일반적으로 사용되는 연결된 모든 노드를 탐색하는 알고리즘이다. 

## 구현
 
![Untitled](../../assets/img/algo/Breadth-First-Search-Algorithm.gif)

다음과 같은 순서로 탐색이 진행된다. 이를 구현하기 위해자 료구조 큐(Queue)의 선입선출 특성을 이용해 구현한다.  

1. 탐색 시작 노드를 큐에 넣는다.
2. 현재 큐 FrontTop의 노드와 연결된 모든 노드를 큐에 넣는다.
3. Pop 연산을 진행한다.
4. 2번으로 돌아가 방문한 노드가 없을 때까지 loop 를 진행한다.

![Untitled](../../assets/img/algo/BFS-Array.png)
보통 코테에서는 2차원 배열로 트리를 구성하거나 
2차원 배열 자체를 맵으로 사용해 BFS 적용 시키는 경우가 많다.
일단 기본적으로 외워야하는 코드는 다음과 같다
```cpp
//map 방문 기록
int board[map_y][map_x];
int visited[map_y][map_x];
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
// N = y좌표 , M = x좌표
int N, M;

void BFS(int posy, int posx){
    //시작 노드 큐에 넣기
    queue<pair<int,int>> q;
    q.push({posy,posx});
    visited[posy][posx] = 1;
    //2번 과정 이후 loop문
    while(!q.empty()){
        pair<int, int> cur = q.front(); q.pop();
        for(int i=0;i<4;++i){
            int ny = dy[i] + cur.first;
            int nx = dx[i] + cur.second;
            //map 범위를 벗어난 좌표이동
            if(ny < 0 || ny >= N || nx < 0 || nx >= M ) continue;
            //없는 경로거나 이미 방문했던 곳
            if(board[ny][nx]!=1 || visited[ny][nx]) continue;
            visited[ny][nx] = 1;
            q.push({ny,nx});
        }
    }
}

