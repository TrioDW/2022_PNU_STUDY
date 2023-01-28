# [1] Monte-Carlo 계산
# C1은 중심이 (1,0)이며 반지름이 1인 반원의 내부이다. C2는 중심이 (0,2)이며 반지름이 2인 원의 제 4분면
# 의 내부이다. 이 둘의 공통부분의 면적을 random number를 이용한 monte-carlo simulation으로 구하시오.

# 1) sample 점의 수는 100,000개 이상 사용해야 한다.
# 2) 면적은 소숫점 2자리까지 일치하면 올바른 것으로 처리된다.
# 3) 적절한 함수를 사용해야 한다.
# 4) random number의 seed는 정수 시험일자인 20210616을 사용해야 한다.

import random

def inout(x, y):
    if (x**2 + (y-2)**2 <= 4) and ((x-1)**2 + y**2 <= 1):
        return True
    else:
        return False

C = 0
N = 1000000
random.seed(20220620)

for i in range(N):
    x = random.uniform(0, 2)
    y = random.uniform(0, 2)

    # 내부에 해당되면 C에 1을 더한다.
    if inout(x, y):
        C += 1

# C/N은 비율이므로, 넓이인 4를 곱해주어야 한다.
print(4*C/N)
