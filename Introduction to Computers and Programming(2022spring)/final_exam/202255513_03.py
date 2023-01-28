
myline = input("Type L string: ")  # 45554136631411334

mylist = list(myline)

new_list = []

for w in range(len(mylist)):
    w = 0
    k = 0

    new_list.append(mylist[w])

    if new_list[k] == mylist[w]:
        new_list.pop()
        w += 1

    else:
        w += 1
        k += 1

print(*new_list)
