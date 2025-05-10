import sys

N, D = map(int,input().split())
paths = []
dp = [ i for i in range(D+1)]
result = float('inf')
for i in range(N):
    start,dest, cost = map(int,input().split())
    if dest<=D:
        paths.append([start,dest,cost])

for i in range(D+1):
    if i>0:
        dp[i] = min (dp[i], dp[i-1]+1)

    for start,dest,cost in paths:
        if i == start:
            dp[dest] = min(dp[dest],dp[i]+cost)



print(dp[D])

