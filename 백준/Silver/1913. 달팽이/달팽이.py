import sys
sys.setrecursionlimit(10**6)

N = int(input())
target = int (input())

dy = [1,0,-1,0]
dx = [0,1,0,-1]

board = [[0]*N for _ in range(N)]

def dfs (y, x , dir, value):
    board[y][x] = value

    ny = y + dy[dir]
    nx = x + dx[dir]

    if 0<=ny <N and 0<=nx<N and board[ny][nx] == 0:
        dfs(ny,nx,dir,value-1)
    else:
        dir = (dir+1)%4
        ny = y + dy[dir]
        nx = x + dx[dir]
        if board[ny][nx] == 0:
            dfs(ny,nx,dir,value-1)


dfs(0,0,0,N*N)

for row in board:
    print(" ".join(map(str, row)))


for i, row in enumerate(board):
    for j,col in enumerate(row):
        if col == target:
            print(i+1, j+1)