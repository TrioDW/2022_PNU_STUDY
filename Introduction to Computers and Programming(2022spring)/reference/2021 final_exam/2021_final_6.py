# [6] 재귀함수 (recursive function)
#  a/b 형식의 분수가 원소로 들어있는 리스트에서 두 번째로 큰 (s econd maximum)을 구하는
# 함수 Second_max(L)를 재귀적(recursive) 함수기법으로 작성하시오. 단 이 코드 작성의 제한
# 사항은 다음과 같다. 아래 조건을 1개라도 어길 경우에는 0점 처리된다.

# 1) for, while과 같은 loop을 사용해서는 안된다.
# 2) 내장 함수 min( )이나 max( )를 사용해서는 안된다.
# 3) 내장 정렬함수 sort( ) 또는 그 변형을 사용해서는 안된다.

L = [4/34, 54/21, 65/55, 34/24, 76/45, 9/34, 34/22, 4/5, 5/6, 7/8, 9/5]


def Second_max(L):
    if len(L) <= 1:
        print("Error")
        return

    if len(L) == 2:
        if L[0] < L[1]:
            return L[0]
        else:
            return L[1]

    if L[0] < L[1] and L[0] < L[2]:
        del L[0]
    elif L[1] < L[0] and L[1] < L[2]:
        del L[1]
    else:
        del L[2]

    return Second_max(L)


print(Second_max(L))
