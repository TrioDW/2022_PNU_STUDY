
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

    s = 0
    for i in La_len:
        result.append(temp[s:s+i])
        s += i
    return result


print(Deep_Rotate(La))
