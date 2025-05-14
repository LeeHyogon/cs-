from collections import deque

def solution(land):
    answer = 0
    n = len(land)
    m = len(land[0])
    
    result = [0 for _ in range(m)]
    visited = [[ 0 for _ in range(m)] for _ in range(n)]

    dy = [-1,0,1,0]
    dx = [0,-1,0,1]
                
    for i in range(n):
        for j in range(m):
            if visited[i][j]==0 and land[i][j] == 1:
                visited[i][j]=1
                q = deque()
                q.append((i,j))
                count = 0
                min_y = j
                max_y = j
                while q:
                    y, x = q.popleft()
                    count += 1
                    
                    min_y = min(min_y, x)  # 열 기준
                    max_y = max(max_y, x)
                    for d in range(4):
                        ny = y + dy[d]
                        nx = x + dx[d]
                        if ny>=0 and ny < n and nx>=0 and nx<m and visited[ny][nx]== 0 and land[ny][nx] ==1 :
                            visited[ny][nx] = 1
                            q.append((ny,nx))
                            
                for k in range(min_y,max_y+1):
                    result[k] += count

    
    answer = max(result)

    return answer
