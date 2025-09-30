#import sys
#sys.stdin = open("input.txt", "r")

def distance (y1, x1, y2, x2) :
    return abs(y1-y2) + abs(x1-x2)
        
T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    # ///////////////////////////////////////////////////////////////////////////////////

    N = int(input())
    nums = list(map(int,input().split()))
    ans = 987654321
    cy, cx = nums[0], nums[1]
    hy, hx = nums[2], nums[3]
    customers = []
    for i in range(N):
        cuy, cux = nums[4+2*i], nums[5+2*i]
        customers.append([cuy,cux])

    def permutation (arr,visited, N, value):
        global ans
        if value >= ans:
            return

        if len(arr) == N:
            ly, lx = customers[arr[len(arr)-1]]
            value += distance(ly,lx,hy,hx)
            ans = min(ans,value)            
            return
    
        for i in range(N):
            if visited[i] == 0:
                visited[i] = 1
                ny, nx = customers[i]
                ly, lx = customers[arr[len(arr)-1]]
                permutation(arr+[i], visited, N, value+distance(ly,lx,ny,nx))
                visited[i] = 0
                
    for i in range(N):
        visited = [0]*N
        visited[i]=1
        ny,nx = customers[i]
        value = 0
        value+= distance(cy,cx,ny,nx)
        permutation([i],visited, N, value)

    print('#' + str(test_case) + ' ' + str(ans))

