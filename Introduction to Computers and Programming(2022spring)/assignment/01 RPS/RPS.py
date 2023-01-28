RPS = input()
List = RPS.split()
H1 = List[0]
H2 = List[1]

if H1 == H2 :
    print('D')


SL = set(List)
if SL == {"R", "P"} :
    print("P")


if SL == {"R", "S"} :
    print("R")

if SL == {"S", "P"} :
    print("S")