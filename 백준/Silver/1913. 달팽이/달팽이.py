N = int(input())
target = int (input())

dy = [1,0,-1,0]
dx = [0,1,0,-1]

board = [[0]*N for _ in range(N)]

value = N*N

y = 0
x = 0

ans_y =0
ans_x =0
dir = 0
while 1:
    if value == target:
        ans_y = y+1
        ans_x = x+1
    
    if value == 1:
        board[y][x] = value
        break

    board[y][x] = value
    
    ny = y + dy[dir]
    nx = x + dx[dir]    
    
    if 0<=ny <N and 0<=nx<N and board[ny][nx] == 0:
        y = ny
        x = nx
        dir = dir
        value -=1
    else:
        dir = (dir+1)%4
        y = y + dy[dir]
        x = x + dx[dir]        
        value = value -1
            

for row in board:
    print(" ".join(map(str, row)))

print(ans_y, ans_x)