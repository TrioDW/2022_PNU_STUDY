
numsym = list("0123456789")

in_str = list(input())
C = list()

Num1 = 0

E_combo = 0
U_combo = 0
D_combo = 0

total = 0


for w in in_str :
    if not w in numsym :
        Num1 = -1
        break


if Num1 == -1 :
    print(-1)

else :
    in_int = list(map(int,in_str))

    for x in range(0,len(in_int)-1) :

        if   in_int[x+1] == in_int[x]    : C.append('e')
        elif in_int[x+1] == in_int[x] +1 : C.append('u')
        elif in_int[x+1] == in_int[x] -1 : C.append('d')
        else                             : C.append('n')


    for y in range(0,len(C)) :

        if C[y] == 'n' :
            E_combo = 0
            U_combo = 0
            D_combo = 0

        elif C[y] == 'e' :
            total += 1 + E_combo
            E_combo += 1
            U_combo = 0
            D_combo = 0

        elif C[y] == 'u' :
            total += 1 + U_combo
            E_combo = 0
            U_combo += 1
            D_combo = 0

        elif C[y] == 'd' :
            total += 1 + D_combo
            E_combo = 0
            U_combo = 0
            D_combo += 1

        



    print(total)