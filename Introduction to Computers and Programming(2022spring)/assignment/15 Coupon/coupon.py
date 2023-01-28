import sys
input = sys.stdin.readline

# stdin 값 받기
count, money = map(int, input().split())

menu = [0] * count
for w in range(count):
    menu[w] = int(input())

# 쿠폰 함수
result = []
mylist = []


def coupon(money, mylist):

    flag = 0

    for w in range(count):
        if w in mylist:
            continue
        if menu[w] > money:
            continue

        flag = 1
        mylist.append(w)

        coupon(money - menu[w], mylist)
        del mylist[-1]

    if flag == 0:
        tmp = sorted(mylist[:])
        if tmp in result:
            pass
        else:
            result.append(tmp)


coupon(money, mylist)

for i in result:
    for j in i:
        print(j+1, end=" ")
    print("")

sys.exit()
