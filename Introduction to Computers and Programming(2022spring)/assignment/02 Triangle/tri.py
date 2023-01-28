
Beun = input()

LB = Beun.split()

NL = list(map(int, LB))
NL.sort()

print("정렬된 세 변의 크기 = ", NL)

print("세 변의 크기의 합 = ", sum(NL))



