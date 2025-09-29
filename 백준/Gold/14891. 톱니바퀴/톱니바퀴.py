wheel = []
for i in range(4):
    wheel.append(list(map(int,input())))
K = int(input())

def moveWheel(num, dir) :
    if dir == 1 :
        wheel[num] =[wheel[num][-1]] + wheel[num][:-1]
    elif dir == -1 :
        wheel[num] = wheel[num][1:] + [wheel[num][0]]

def pick(num, dir, visited):
    visited[num] = 1
    ori_wheel = wheel[num]
    
    moveWheel(num,dir)
    if 0<=num<=2 and ori_wheel[2] != wheel[num+1][6] and visited[num+1] == 0:
        pick(num+1,dir * -1, visited)

    if 1<=num<=3 and (ori_wheel[6] != wheel[num-1][2]) and visited[num-1] == 0:
        pick(num-1,dir * -1 ,visited)
    


for cnt in range(K):
    visited = [0]*4
    wheel_num, dir= map(int,input().split())
    pick(wheel_num-1,dir, visited)

ans = 0
ans += wheel[0][0]
ans += wheel[1][0]*2
ans += wheel[2][0]*4
ans += wheel[3][0]*8

print(ans)

