def clockwise(arr):
    newarr = [[0 for _ in range(3)] for _ in range(3)]
    for i in range(3):
        for j in range(3):
            newarr[i][j] = arr[2-j][i]
    return newarr

def anticlockwise(arr):
    newarr = [[0 for _ in range(3)] for _ in range(3)]
    for i in range(3):
        for j in range(3):
            newarr[i][j] = arr[j][2-i]
    return newarr


def move(c):
    global cube
    if c == "U+":
        cube[4][0], cube[3][0], cube[5][0], cube[2][0] = cube[2][0], cube[4][0], cube[3][0], cube[5][0]
        cube[0] = clockwise(cube[0])
        return
    elif c == "U-":
        cube[5][0], cube[3][0], cube[4][0], cube[2][0] = cube[2][0], cube[5][0], cube[3][0], cube[4][0]
        cube[0] = anticlockwise(cube[0])
        return
    elif c == "D-":
        cube[4][2], cube[3][2], cube[5][2], cube[2][2] = cube[2][2], cube[4][2], cube[3][2], cube[5][2]
        cube[1] = anticlockwise(cube[1])
        return
    elif c == "D+":
        cube[5][2], cube[3][2], cube[4][2], cube[2][2] = cube[2][2], cube[5][2], cube[3][2], cube[4][2]
        cube[1] = clockwise(cube[1])
        return
    elif c == "F+":
        a, b, c = cube[4][0][2], cube[4][1][2], cube[4][2][2]
        cube[4][0][2], cube[4][1][2], cube[4][2][2] = cube[1][0][0], cube[1][0][1], cube[1][0][2]
        cube[1][0][0], cube[1][0][1], cube[1][0][2] = cube[5][2][0], cube[5][1][0], cube[5][0][0]
        cube[5][2][0], cube[5][1][0], cube[5][0][0] = cube[0][2][2], cube[0][2][1], cube[0][2][0]
        cube[0][2][2], cube[0][2][1], cube[0][2][0] = a, b, c
        cube[2] = clockwise(cube[2])
        return
    elif c == "F-":
        a, b, c = cube[4][0][2], cube[4][1][2], cube[4][2][2]
        cube[4][0][2], cube[4][1][2], cube[4][2][2] = cube[0][2][2], cube[0][2][1], cube[0][2][0]
        cube[0][2][2], cube[0][2][1], cube[0][2][0] = cube[5][2][0], cube[5][1][0], cube[5][0][0]
        cube[5][2][0], cube[5][1][0], cube[5][0][0] = cube[1][0][0], cube[1][0][1], cube[1][0][2]
        cube[1][0][0], cube[1][0][1], cube[1][0][2] = a, b, c
        cube[2] = anticlockwise(cube[2])
        return
    elif c == "B+":
        a, b, c = cube[4][0][0], cube[4][1][0], cube[4][2][0]
        cube[4][0][0], cube[4][1][0], cube[4][2][0] = cube[0][0][2], cube[0][0][1], cube[0][0][0]
        cube[0][0][2], cube[0][0][1], cube[0][0][0] = cube[5][2][2], cube[5][1][2], cube[5][0][2]
        cube[5][2][2], cube[5][1][2], cube[5][0][2] = cube[1][2][0], cube[1][2][1], cube[1][2][2]
        cube[1][2][0], cube[1][2][1], cube[1][2][2] = a, b, c
        cube[3] = clockwise(cube[3])
        return
    elif c == "B-":
        a, b, c = cube[4][0][0], cube[4][1][0], cube[4][2][0]
        cube[4][0][0], cube[4][1][0], cube[4][2][0] = cube[1][2][0], cube[1][2][1], cube[1][2][2]
        cube[1][2][0], cube[1][2][1], cube[1][2][2] = cube[5][2][2], cube[5][1][2], cube[5][0][2]
        cube[5][2][2], cube[5][1][2], cube[5][0][2] = cube[0][0][2], cube[0][0][1], cube[0][0][0]
        cube[0][0][2], cube[0][0][1], cube[0][0][0] = a, b, c
        cube[3] = anticlockwise(cube[3])
        return
    elif c == "L+":
        a, b, c = cube[0][0][0], cube[0][1][0], cube[0][2][0]
        cube[0][0][0], cube[0][1][0], cube[0][2][0] = cube[3][2][2], cube[3][1][2], cube[3][0][2]
        cube[3][2][2], cube[3][1][2], cube[3][0][2] = cube[1][0][0], cube[1][1][0], cube[1][2][0]
        cube[1][0][0], cube[1][1][0], cube[1][2][0] = cube[2][0][0], cube[2][1][0], cube[2][2][0]
        cube[2][0][0], cube[2][1][0], cube[2][2][0] = a, b, c
        cube[4] = clockwise(cube[4])
        return
    elif c == "L-":
        a, b, c = cube[0][0][0], cube[0][1][0], cube[0][2][0]
        cube[0][0][0], cube[0][1][0], cube[0][2][0] = cube[2][0][0], cube[2][1][0], cube[2][2][0]
        cube[2][0][0], cube[2][1][0], cube[2][2][0] = cube[1][0][0], cube[1][1][0], cube[1][2][0]
        cube[1][0][0], cube[1][1][0], cube[1][2][0] = cube[3][2][2], cube[3][1][2], cube[3][0][2]
        cube[3][2][2], cube[3][1][2], cube[3][0][2] = a, b, c
        cube[4] = anticlockwise(cube[4])
        return
    elif c == "R+":
        a, b, c = cube[0][0][2], cube[0][1][2], cube[0][2][2]
        cube[0][0][2], cube[0][1][2], cube[0][2][2] = cube[2][0][2], cube[2][1][2], cube[2][2][2]
        cube[2][0][2], cube[2][1][2], cube[2][2][2] = cube[1][0][2], cube[1][1][2], cube[1][2][2]
        cube[1][0][2], cube[1][1][2], cube[1][2][2] = cube[3][2][0], cube[3][1][0], cube[3][0][0]
        cube[3][2][0], cube[3][1][0], cube[3][0][0] = a, b, c
        cube[5] = clockwise(cube[5])
        return
    else:
        a, b, c = cube[0][0][2], cube[0][1][2], cube[0][2][2]
        cube[0][0][2], cube[0][1][2], cube[0][2][2] = cube[3][2][0], cube[3][1][0], cube[3][0][0]
        cube[3][2][0], cube[3][1][0], cube[3][0][0] = cube[1][0][2], cube[1][1][2], cube[1][2][2]
        cube[1][0][2], cube[1][1][2], cube[1][2][2] = cube[2][0][2], cube[2][1][2], cube[2][2][2]
        cube[2][0][2], cube[2][1][2], cube[2][2][2] = a, b, c
        cube[5] = anticlockwise(cube[5])
        return


T = int(input())
for test_case in range(T):
    cube = [[['w','w','w'],['w','w','w'],['w','w','w']],[['y','y','y'],['y','y','y'],['y','y','y']],[['r','r','r'],['r','r','r'],['r','r','r']],[['o','o','o'],['o','o','o'],['o','o','o']],[['g','g','g'],['g','g','g'],['g','g','g']],[['b','b','b'],['b','b','b'],['b','b','b']]]
    N = int(input())
    commands = list(input().split())
    for command in commands:
        move(command)
    for i in range(3):
        ans = ''.join(cube[0][i])
        print(ans)