
Ux = input().split()      ; gx = input().split()
Ux = [int(i) for i in Ux] ; gx = [int(j) for j in gx]

Kx = []

for w in range( len(Ux) ) :
    Kx.append(Ux[w])


fx = []

def divpoly ( Ux, gx, fx ) :
    for w in range( len(Ux) - len(gx) + 1 ) :

        fx.append( int( Ux[w] / gx[0] ) )

        for i in range( len(gx) ) :

            Ux[i+w] = Ux[i+w] - ( gx[i] * int( fx[w] ) )

divpoly( Ux, gx, fx )

fx = [int(k) for k in fx]


# jUx에서 joylist를 뺀 값을 rx로 한다.
joylist = []


k = len(fx); l = len(gx); m = k+l-1

def poly (k, l, Ans, F, G) :

    for w in range(k+l-1) :
        Ans.append(int(0))


    for a in range(0,l) :
        for b in range(0,k) :

            Ans[k+l-int(a)-int(b)-2] += int(G[l-int(a)-1]) * int(F[k-int(b)-1])

poly(k, l, joylist, fx, gx)

rx = []

for w in range( len(Ux) ) :
    rx.append(0)
    rx[w] = Kx[w] - joylist[w]


Ans_fx = map(str, fx)

print(' '.join(Ans_fx))


a = 0

while ( True ) :

    if rx[a] != 0 : break

    rx.pop(a)

    if len(rx) == 0 :
        rx.append(0)
        break


Ans_rx = map(str, rx)

print(' '.join(Ans_rx))