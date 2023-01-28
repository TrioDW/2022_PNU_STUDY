
def show_time(T, K):

    if T[2] + K < 60:
        T[2] += K

    elif T[2] + K >= 60:
        alpha = (T[2] + K) // 60
        T[1] += alpha
        T[2] = T[2] + K - 60*alpha

    if T[1] >= 60:
        beta = T[1] // 60
        T[0] += beta
        T[1] = T[1] - 60*beta

    return (T)


In = input("Type 현재 시간: h, m, s:")

h, m, s = map(int, In.split())

T = [h, m, s]
K = int(input("Type 추가시간  K: "))

result = show_time(T, K)

print("계산결과= ", result)
