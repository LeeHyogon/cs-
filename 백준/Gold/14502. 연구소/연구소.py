import sys
import copy
from collections import deque


N, M = map(int, input().split())

board = [ list(map(int,input().split())) for _ in range(N)]
# 벽 3개 세우기
# 세운 벽에 대해서 dfs or bfs
# 안전 영역 크기 최대값 구하기

dy = [-1,0,1,0]
dx = [0,1,0,-1]

answer = 0
def bfs(ori_lab):
    lab = copy.deepcopy(ori_lab) 
    dq = deque()
    for i in range(N):
        for j in range(M):
            if lab[i][j] == 2:
                dq.append((i,j))

    
    while dq:
        y, x = dq.pop()
        for dir in range(4):
            ny = y+dy[dir]
            nx = x+dx[dir]
            if ny>=0 and ny<N and nx>=0 and nx<M and lab[ny][nx] == 0:
                lab[ny][nx] = 2
                dq.append((ny,nx))

    ret = 0

    
    for i in range(N):
        for j in range(M):
           if lab[i][j] == 0:
               ret+=1
    return ret
           
def make_wall(cnt, lab):
    global answer
    if cnt == 3:
        answer = max(answer, bfs(lab))
        return
    
    for i in range(N):
        for j in range(M):
            if lab[i][j] == 0:
                lab[i][j] = 1
                make_wall(cnt+1, lab)
                lab[i][j] = 0



make_wall(0,board)

print(answer)
