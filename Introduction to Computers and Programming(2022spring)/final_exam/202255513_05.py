from cmath import pi
import numpy as np
import sympy as sym
import math


def f(x):
    return (x + np.sin(x)) / (1 + np.cos(x))


x = np.linspace(0, 10)   # x의 범위
y = f(x)

a = 0
b = pi/2

Inte_x = np.linspace(a, b)  # 적분할 x 범위
Inte_y = f(Inte_x)  # 적분할 y 범위

ans = 0

for w in range(len(Inte_y)):
    ans += Inte_y[w]

print(f'1번 문제 답은 {ans} 입니다.')
