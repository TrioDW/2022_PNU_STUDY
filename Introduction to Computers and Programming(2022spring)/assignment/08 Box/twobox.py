
box_input = input().split()

A = box_input[0:4]; box_Alist = []
B = box_input[4:8]; box_Blist = []


AX = []; AY = []
BX = []; BY = []

def X_amount1 ( A, AX ) :

    for w in range( int(A[0]) , int(A[2]) + 1 ) :
        AX.append(w)

def X_amount2 ( B, BX ) :

    for w in range( int(B[0]) , int(B[2]) + 1 ) :
        BX.append(w)

def Y_amount1 ( A, AY ) :

    for w in range( int(A[1]) , int(A[3]) + 1 ) :
        AY.append(w)

def Y_amount2 ( B, BX ) :

    for w in range( int(B[1]) , int(B[3]) + 1 ) :
        BY.append(w)


X_amount1( A, AX )
X_amount2( B, BX )

Y_amount1( A, AY )
Y_amount2( B, BY )


Xgyo = list( set(AX).intersection(BX) )
Ygyo = list( set(AY).intersection(BY) )


if len(Xgyo) == 0 or len(Ygyo) == 0 : print("NULL")

elif len(Xgyo) == 1 and len(Ygyo) == 1 : print("POINT")

elif len(Xgyo) >= 2 and len(Ygyo) >= 2 : print("FACE")

else : print("LINE")