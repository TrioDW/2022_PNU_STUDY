

# 입력받기, 입력을 받을때 부터 중복 처리하기 !!

customer = []; Data = []

while (True) :
    try :
        stdin = list( input().split() )
    except EOFError :
        break

    if stdin[0] in customer :
        for w in range( len(Data) ) :
            if Data[w][0] == stdin[0] :

                for x in stdin[1:] :
                    Data[w].append(x)

    else :
        Data.append( stdin )
        customer.append( stdin[0] )

# Data값을 set 한 후, customer 를 맨 앞으로 정렬

for w in range( len(Data) ) :
    Data[w].sort()
    Data[w].reverse()

Data = sorted(Data)

Ans1 = []; Ans2 = []

for i in range ( 0, len(Data) - 1 ) :
    for j in range ( i+1, len(Data) ) :
        Ans1.append( [ Data[i][0], Data[j][0] ] )

        set1 = set( Data[i][1:len(Data[i])] )
        set2 = set( Data[j][1:len(Data[j])] )

        uni   = set1 | set2
        inter = set1 & set2
        Ans2.append( len(inter) / ( len(uni) + 1) )


maximum = max(Ans2)

Max_count = Ans2.count(maximum)


if Max_count == 1 : print(*Ans1[Ans2.index(maximum)])

else :
    for w in range(len(Ans2)) :
        if Ans2[w] == maximum :
           print(Ans1[w][0]+ " " + Ans1[w][1])