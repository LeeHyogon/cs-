import sys
import heapq

N, M = map(int, input().split())

# 사다리, 뱀 정보 저장 (맵핑용)
teleport = {}

for i in range(N + M):
    a, b = map(int, input().split())
    teleport[a] = b

visited = [[False] * 10 for _ in range(10)]
board = [[float('inf')] * 10 for _ in range(10)]
board[0][0] = 0

heap = []
heapq.heappush(heap, (0, 0, 0))

while heap:
    cost, y, x = heapq.heappop(heap)
    num = 10 * y + x + 1

    if num == 100:
        print(min(17, cost))
        break

    for i in range(1, 7):
        next_num = num + i
        if next_num > 100:
            continue

        # 사다리 또는 뱀이 있는 경우 목적지로 이동
        if next_num in teleport:
            next_num = teleport[next_num]

        ny = (next_num - 1) // 10
        nx = (next_num - 1) % 10

        if board[ny][nx] > cost + 1:
            board[ny][nx] = cost + 1
            heapq.heappush(heap, (cost + 1, ny, nx))
