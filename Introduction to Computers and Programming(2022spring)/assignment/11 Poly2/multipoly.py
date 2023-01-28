
def poly (Ans, F, G) :

    k = len(F); l = len(G); m = k+l-1

    for w in range(k+l-1) :
        Ans.append(int(0))


    for a in range(0,l) :
        for b in range(0,k) :

            Ans[k+l-int(a)-int(b)-2] += int(G[l-int(a)-1]) * int(F[k-int(b)-1])

Data = [ ]

w = 0

while (True) :
    try :
        Data.append([])
        Data[w] = input().split()
        w += 1

    except EOFError :
        Data.remove([])
        break

Ans = []

num = len(Data)

for w in range(num-1) :

    if w == 0 :
        F = Data[w]; G = Data[w+1]
        poly(Ans, F, G)

    else :
        F.clear()
        for i in Ans :
            F.append(i)
        Ans.clear()
        G.clear()
        G = Data[w+1]

        poly(Ans, F, G)

Ans2 = map(str, Ans)
Ans3 = ' '.join(Ans2)

Ans4 = set(Ans3.split())

if Ans4 == {'0'} : print('0')

else: print(Ans3)