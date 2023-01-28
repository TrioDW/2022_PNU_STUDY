
import sys

data = [sys.stdin.readline().strip() for i in range(0,5)]

In1 = data[1].split()
In2 = data[2].split()
In3 = data[3].split()
In4 = data[4].split()


N, M = map(int, data[0].split())

all_blocks = N * M


panel = [[''] * N for x in range(M)]

n = 0
move = -1
x_limit = N-1
y_limit = M


x = 0
y = M

while True :
    if n == N * M :
        break

    for i in range(y_limit) :
        n += 1
        y += move
        panel[y][x] = n

    y_limit -= 1
    move = -move


    if n == N * M :
        break

    for i in range(x_limit) :
        n += 1
        x += move
        panel[y][x] = n

    x_limit -= 1



# 1번 input
if len(In1) == 1 and int(data[1]) > all_blocks :
    print("0 0")

elif len(In1) == 1 and int(data[1]) <= all_blocks :
    for i in range(0,M) :
        if int(data[1]) in panel[i] :
            print(panel[i].index(int(data[1]))+1, M-i)

elif len(In1) == 2 :
    print( panel [M - int(In1[1])] [int(In1[0]) - 1] )




# 2번 input
if len(In2) == 1 and int(data[2]) > all_blocks :
    print("0 0")

elif len(In2) == 1 and int(data[2]) <= all_blocks :
    for i in range(0,M) :
        if int(data[2]) in panel[i] :
            print(panel[i].index(int(data[2]))+1, M-i)

elif len(In2) == 2 :
    print(panel [M - int(In2[1])] [int(In2[0]) - 1] )



# 3번 input
if len(In3) == 1 and int(data[3]) > all_blocks :
    print("0 0")

elif len(In3) == 1 and int(data[3]) <= all_blocks :
    for i in range(0,M) :
        if int(data[3]) in panel[i] :
            print(panel[i].index(int(data[3]))+1, M-i)

elif len(In3) == 2 :
    print(panel [M - int(In3[1])] [int(In3[0]) - 1] )



# 4번 input
if len(In4) == 1 and int(data[4]) > all_blocks :
    print("0 0")

elif len(In4) == 1 and int(data[4]) <= all_blocks :
    for i in range(0,M) :
        if int(data[4]) in panel[i] :
            print(panel[i].index(int(data[4]))+1, M-i)

elif len(In4) == 2 :
    print(panel [M - int(In4[1])] [int(In4[0]) - 1] )










sys.exit()