# [4] Excel 파일의 처리
# 주어진 excel file인 'food.xslx'에는 3개의 column이 있으며 각각은 음식(이름), 가격, 만족도를 나타내고 
# 있다. 이 파일을 읽어서 가성비, 즉 만족도/가격 비율이 높은 순서대로 음식 이름과 그 가성비를 화면으로
# 출력하는 프로그램을 작성하시오. 아래는 excel 'food.xslx'의 한 예를 보여준다.,

import pandas as pd

df = pd.read_excel('food.xlsx', engine='openpyxl')

df['가성비'] = df['만족도']/df['가격']
print(df[['이름', '가성비']].sort_values(by='가성비', ascending=False))
