from collections import deque

# N, M 공백 기준으로 입력 받기
n, m = map(int, input().split())

# 2차원 맵 정보 리스트로 입력 받기
graph = []
for i in range(n):
    graph.append(list(map(int, input())))

# 좌표 이동 구현
dy = [0, 0, 1, -1]
dx = [1, -1, 0, 0]

def BFS(x, y):
    queue = deque()
    queue.append((y,x))

    while queue:
        y, x = queue.popleft() 

        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]

            if ny < 0 or ny >= n or nx < 0 or nx >= m: 
                continue
            if graph[ny][nx] != 1:
                continue
            
            graph[ny][nx] = graph[y][x] + 1
            queue.append((ny,nx))

    return graph[n-1][m-1]

print(BFS(0,0))