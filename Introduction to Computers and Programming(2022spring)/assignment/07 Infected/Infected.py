import string

Infected_list = input().split("0")
Infected_list = list(filter(None, Infected_list))

numsym = list("0123456789")

data = []

for i in range(len(Infected_list)) :
    data.append(0)

for i in range(len(Infected_list)) :

    for w in Infected_list[i] :

        if w in numsym :

            data[i] += int(w)

        elif w not in numsym :

            data[i] += (ord(str(w)) - 87)

l1 = []

if data == l1 :
    print(0)

else :
    print(max(data))