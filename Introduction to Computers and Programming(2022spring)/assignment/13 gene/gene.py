
Si = input().split()
Ei = input().split()

file = open("genome.txt", 'r')

All_text = ''

while (True) :
    text = file.readline()
    if not text :
        break
    text = text.strip()
    All_text += text




Si_index = []
for w in Si :

    index = -1
    while (True) :
        index = All_text.find(w, index + 1)
        if index == -1 :
            break
        Si_index.append( (index + len(w), len(w)) )




Ei_index = []
for w in Ei :

    index = -1
    while (True) :
        index = All_text.find(w, index + 1)
        if index == -1 :
            break
        Ei_index.append( (index + 1, len(w)) )





final_index = []
integer_index = []

for i in range( len(Si_index) ) :
    for j in range( len(Ei_index) ) :

        a1 = Si_index[i][0]; a2 = Si_index[i][1]
        b1 = Ei_index[j][0]; b2 = Ei_index[j][1]

        if  a1 < b1 :
            final_index.append( All_text[a1 - a2 : b1 + b2 - 1] )
            integer_index.append( b1 + b2 - 2 - a1 + a2 )

Ans_list = []

if len(integer_index) == 0 : print("None")

else:
    int_min = min(integer_index)
    samenum = integer_index.count(int_min)

    if samenum == 1 :

        k = integer_index.index(int_min)
        print(final_index[k])

    else :

        for w in range( len(integer_index) ) :
            if integer_index[w] == int_min :
                Ans_list.append(final_index[w])

        Ans_list.sort()
        print(Ans_list[0])





file.close()