import sys
sys.setrecursionlimit(10**6)

string = input()
N = len(string)

visited = [False] * N

answer = 0
rec = set()

def luck_str(str):

    for i in range(len(str)-1):
        if str[i] == str[i+1]:
            return False
    return True

def dfs (str, visited) :
    global answer
    
    if str in rec:
        return

    if len(str) == N:
        rec.add(str)

        answer+=1
        return

    for i in range(N):
        if visited[i] == False:
            if str and str[-1] == string[i]:
                continue

            visited[i] = True
            dfs(str+string[i],visited)
            visited[i] = False

    return

dfs("",visited)

print(answer)

