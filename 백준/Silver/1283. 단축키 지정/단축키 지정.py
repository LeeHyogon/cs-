import sys

N = int(input())

words = [[] for _ in range(N+1)] 
seens = set()

def chg_str ( string, idx):
    str = ""

    for i, c in enumerate(string):
        if i == idx:
            str = str + '[' + c + ']'
        else:
            str = str + c

    return str

def all_first (strings):
    chk = False

    for i, string in enumerate(strings):
        lower_str = string.lower()

        if lower_str[0] not in seens:
            return i
    
    return -1

for i in range (N):
    strings = list(input().split())

    is_all_first = all_first(strings)
    
    if is_all_first != -1 :
        for j ,string in enumerate(strings):
            if j == is_all_first:
                seens.add(string[0].lower())
                words[i].append(chg_str(string,0))
            else:
                words[i].append(string)

    else:
        for str_i, string in enumerate(strings):
            lower_str = string.lower()    
        
            is_save = -1
            for idx, ch in enumerate(lower_str):
                if idx == 0:
                    continue
                if ch not in seens:
                    is_save = idx
                    break
            if is_save != -1:
                #단어 저장 글자 
                seens.add(lower_str[is_save])
                words[i].append(chg_str(string,is_save))

                #나머지 뒤의 string 다 넣고 탈출
                for j in range(str_i+1, len(strings)) :
                    words[i].append(strings[j])   
                break
            else:
                words[i].append(string)


for i in range (N):
    for k, word in enumerate(words[i]):
        if k == len(words[i]) - 1:
            print(word)
        else:
            print(word+ " ", end ="")


        

        
        