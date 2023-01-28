# [5] 이중 리스트의 내부 Rotate
# 어떤 리스트는 그 원소가 정수 리스트로 구성되어 있다. 단 이 원소에 빈 리스트(empty list)는
# 존재하지 않는다. 이 상황에서 각 원소 리스트의 원소를 하나씩 왼쪽으로 rotate하는 함수 
# Deep_Rotate( L )을 작성하시오. 즉 원소 리스트의 개수는 그대로 유지한 채 원소만 한 칸씩 회전한다.
# La=[ [3,4], [6], [11, 12, 13], [99 ], [55, 54, 53] ] 이라고 하자. 이것을 Deep_Rotate( La ) 처리를 
# 하면 La는 다음과 같이 변해야 한다. 
# La= [ [4, 6], [11], [12, 13, 99 ], [55], [54, 53, 3 ] ] 
# 이 상황에서 한번 더 Deep_Rotate( )를 하면 다음과 같이 변해야 한다. 
# La= [ [6,11], [12], [13, 99, 55 ], [54], [53, 3, 4 ] ]




La = [[3, 4], [6], [11, 12, 13], [99], [55, 54, 53]]


def Deep_Rotate(La):

    La_len = []
    result = []

    for i in range(len(La)):
        La_len.append(len(La[i]))
    La = sum(La, [])

    temp = []
    temp.append(La[1:])
    temp.append([La[0]])
    temp = sum(temp, [])

    for w in range(len(La_len)):
        result.append([])

    k = 0
    for w in La_len:
        abc = temp[0:w]

        result[k].append(abc)
        for i in range(w):
            temp.pop(0)
        k += 1

    result = sum(result, [])

    return result


print(Deep_Rotate(La))
