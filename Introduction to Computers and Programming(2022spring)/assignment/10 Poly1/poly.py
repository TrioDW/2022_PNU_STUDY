
# 함수 f(x)와 g(x)의 계수를 list로 만들기

F = input().split()
G = input().split()

Ans = []


# 모두 int 타입
k = len(F); l = len(G); m = k+l-1

def poly (k, l, Ans, F, G) :

    for w in range(k+l-1) :
        Ans.append(int(0))


    for a in range(0,l) :
        for b in range(0,k) :

            Ans[k+l-int(a)-int(b)-2] += int(G[l-int(a)-1]) * int(F[k-int(b)-1])


poly(k, l, Ans, F, G)

Ans2 = map(str, Ans)

print(' '.join(Ans2))