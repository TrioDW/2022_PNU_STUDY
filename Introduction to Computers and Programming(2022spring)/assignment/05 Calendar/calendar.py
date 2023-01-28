
import sys

data = [sys.stdin.readline().strip() for i in range(0,6)]

days = list(map(int, data[1].split())) # data[1]은 각 달의 날짜 수


Day = ['Mon', 'Tue', 'Wed', 'Thu', 'Fri', 'Sat', 'Sun']

First_Day = data[2]



M1, D1 = map(int,data[3].split())
M2, D2 = map(int,data[4].split())
M3, D3 = map(int,data[5].split())

total1 = 0
total2 = 0
total3 = 0

tmp = Day.index(First_Day)





# '월' 과 '일'이 over 했을 때, '땡'을 출력하는 것

if M1 > int(data[0]) :
    print("None")

elif D1 > days[M1-1] :
    print("None")

else :
    for i in range(M1-1) :
        total1 += days[i]

    all_day1 = total1 + D1

    remain1 = (all_day1 + tmp) % 7

    print(Day[remain1 - 1])




if M2 > int(data[0]) :
    print("None")

elif D2 > days[M2-1] :
    print("None")

else :
    for i in range(M2-1) :
        total2 += days[i]

    all_day2 = total2 + D2

    remain2 = (all_day2 + tmp) % 7

    print(Day[remain2 - 1])




if M3 > int(data[0]) :
    print("None")

elif D3 > days[M3-1] :
    print("None")

else :
    for i in range(M3-1) :
        total3 += days[i]

    all_day3 = total3 + D3

    remain3 = (all_day3 + tmp) % 7

    print(Day[remain3 - 1])



sys.exit()








