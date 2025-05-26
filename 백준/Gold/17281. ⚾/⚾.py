import sys
from itertools import permutations

N = int(input())
ining = [list(map(int,input().split())) for _ in range(N)]

ans = 0

for seq in permutations([i for i in range(1,9)],8):
    seq = list(seq)
    seq.insert(3, 0)
    score = 0
    cur = 0
    for time in range(N):
        out = base1 = base2 = base3 = 0
        while out < 3:
            if ining[time][seq[cur]] == 0 :
                out+=1

            elif ining[time][seq[cur]] == 1 :
                score += base3
                base3 = base2
                base2 = base1
                base1 = 1
            elif ining[time][seq[cur]] == 2 :
                score += (base3+base2)
                base3 = base1
                base2 = 1
                base1 = 0
            elif ining[time][seq[cur]] == 3 :
                score += (base3+base2+base1)
                base3 = 1
                base2 = 0
                base1 = 0
            else:
                score += (base1+base2+base3+1)
                base1 = base2 = base3 = 0
            cur = (cur+1)%9

    ans = max(ans,score)

print(ans)

        