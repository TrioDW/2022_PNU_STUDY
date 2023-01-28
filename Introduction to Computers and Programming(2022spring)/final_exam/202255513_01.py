import random

p1 = 0
p2 = 0
p3 = 0
p4 = 0
p5 = 0

random.seed(2022)


def RPS(p1, p2, p3, p4, p5):
    global C

    p1 = random.randint(1, 3)
    p2 = random.randint(1, 3)
    p3 = random.randint(1, 3)
    p4 = random.randint(1, 3)
    p5 = random.randint(1, 3)

    temp = [p1, p2, p3, p4, p5]
    set_temp = set(temp)

    alpha = len(set_temp)

    if alpha == 1 or alpha == 3:
        C += 1
        return(RPS(p1, p2, p3, p4, p5))

    else:
        C += 1
        return


C = 0
N = 100000

for i in range(N):

    RPS(p1, p2, p3, p4, p5)


print(C/100000)
