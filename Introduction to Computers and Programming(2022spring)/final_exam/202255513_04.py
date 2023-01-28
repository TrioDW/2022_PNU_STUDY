
f = open("philo.txt", 'r', encoding='cp949')


def frequent(mywords, K):
    return


mydata = f.read()

mydata = mydata.replace('?', ' ')
mydata = mydata.replace('!', ' ')
mydata = mydata.replace('"', ' ')
mydata = mydata.replace("'", ' ')
mydata = mydata.replace('.', ' ')
mydata = mydata.replace(',', ' ')
mydata = mydata.replace('(', ' ')
mydata = mydata.replace(')', ' ')
mydata = mydata.replace('<', ' ')
mydata = mydata.replace('>', ' ')
mydata = mydata.replace('/', ' ')

mywords = mydata.split()


K = int(input("제한 길이 K:"))

text = []

for w in range(len(mywords)):
    if len(mywords[w]) < K:
        continue

    else:
        text.append(mywords[w])

dictionary = dict()

for i in text:
    try:
        dictionary[i] = dictionary[i] + 1
    except:
        dictionary[i] = 1

ans = sorted(dictionary.items(), key=lambda x: x[1])

real_ans = []

if len(ans) == 0:
    print("None")

else:
    key = ans[-1][1]

    for w in range(len(ans)):
        if ans[w][1] == key:
            real_ans.append(ans[w][0])

    print(*real_ans)

f.close()
