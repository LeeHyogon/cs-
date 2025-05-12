string = input()
N = len(string)
string = sorted(string)  # 중복 제거를 위한 정렬

visited = [False] * N
answer = 0

def dfs(curr_str):
    global answer

    if len(curr_str) == N:
        answer += 1
        return

    prev_char = ''  # 이번 dfs 깊이에서 이전에 사용한 문자
    for i in range(N):
        if visited[i]:
            continue

        # 동일한 문자 중복 사용 방지 + 인접 문자 체크
        if string[i] == prev_char:
            continue
        if curr_str and curr_str[-1] == string[i]:
            continue

        prev_char = string[i]
        visited[i] = True
        dfs(curr_str + string[i])
        visited[i] = False

dfs("")
print(answer)
