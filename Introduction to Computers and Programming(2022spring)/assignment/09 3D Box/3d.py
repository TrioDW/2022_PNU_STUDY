Xgyo = []; Ygyo = []; Zgyo = []

def All (box_input, Xgyo, Ygyo, Zgyo) :
    A = box_input[0:6]  ; box_Alist = []
    B = box_input[6:12] ; box_Blist = []

    AX = []; AY = []; AZ = []
    BX = []; BY = []; BZ = []

    def X_amount1 ( A, AX ) :

        for w in range( int(A[0]) , int(A[3]) + 1 ) :
            AX.append(w)

    def X_amount2 ( B, BX ) :

        for w in range( int(B[0]) , int(B[3]) + 1 ) :
            BX.append(w)

    def Y_amount1 ( A, AY ) :

        for w in range( int(A[1]) , int(A[4]) + 1 ) :
            AY.append(w)

    def Y_amount2 ( B, BX ) :

        for w in range( int(B[1]) , int(B[4]) + 1 ) :
            BY.append(w)

    def Z_amount1 ( A, AZ ) :

        for w in range( int(A[2]) , int(A[5]) + 1 ) :
            AZ.append(w)

    def Z_amount2 ( B, BZ ) :

        for w in range( int(B[2]) , int(B[5]) + 1 ) :
            BZ.append(w)


    X_amount1( A, AX )
    X_amount2( B, BX )

    Y_amount1( A, AY )
    Y_amount2( B, BY )

    Z_amount1( A, AZ )
    Z_amount2( B, BZ )


    Xgyo = list( set(AX).intersection(BX) )
    Ygyo = list( set(AY).intersection(BY) )
    Zgyo = list( set(AZ).intersection(BZ) )

    return(Xgyo, Ygyo, Zgyo)

def answer (a, b, c) :
    if   len(a) == 0 or  len(b) == 0 or  len(c) == 0 : return(1)
    elif len(a) == 1 and len(b) == 1 and len(c) == 1 : return(2)
    elif len(a) >= 2 and len(b) >= 2 and len(c) >= 2 : return(3)
    elif len(a) >= 2 and len(b) >= 2 and len(c) == 1 : return(4)
    elif len(a) >= 2 and len(b) == 1 and len(c) >= 2 : return(4)
    elif len(a) == 1 and len(b) >= 2 and len(c) >= 2 : return(4)
    else : return(5)





box_input = input().split()
a, b, c = All(box_input, Xgyo, Ygyo, Zgyo)

k = answer(a, b, c)

if k == 1 : print('NULL')
if k == 2 : print('POINT')
if k == 3 : print('VOL')
if k == 4 : print('FACE')
if k == 5 : print('LINE')

box_input = input().split()
a, b, c = All(box_input, Xgyo, Ygyo, Zgyo)

k = answer(a, b, c)

if k == 1 : print('NULL')
if k == 2 : print('POINT')
if k == 3 : print('VOL')
if k == 4 : print('FACE')
if k == 5 : print('LINE')


box_input = input().split()
a, b, c = All(box_input, Xgyo, Ygyo, Zgyo)

k = answer(a, b, c)

if k == 1 : print('NULL')
if k == 2 : print('POINT')
if k == 3 : print('VOL')
if k == 4 : print('FACE')
if k == 5 : print('LINE')

box_input = input().split()
a, b, c = All(box_input, Xgyo, Ygyo, Zgyo)

k = answer(a, b, c)

if k == 1 : print('NULL')
if k == 2 : print('POINT')
if k == 3 : print('VOL')
if k == 4 : print('FACE')
if k == 5 : print('LINE')