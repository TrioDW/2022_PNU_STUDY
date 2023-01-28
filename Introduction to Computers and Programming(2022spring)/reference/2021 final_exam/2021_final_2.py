# [2] 요일 계산
# 2021년의 특정 월 일의 요일을 계산하는 프로그램을 구성한다. 입력으로는 2개의 정수 M과 D를 받는다.
# M은 월이고 D는 일이다. 출력은 해당 날짜의 요일을 출력한다.

# 1) 만일 올바르지 못한 M과 D가 입력되면 적절한 오류 메시지를 출력한다. 예를 들어 13월, 2월 24일, 
#    8월 0일, 4월 31일 등이다.
# 2) M에 음수가 입력될 때까지 이 작업을 계속한다. 만일 M < 0 이면 프로그램을 종료한다.
# 3) 단 시스템에서 제공하는 시간 관련 함수 time 모듈을 사용해서는 안된다.
# 4) 2021년 1월 1일은 금요일이며, 2월은 28일 까지 있다.

def DAY(a, b):

    day_list = ['SAT', 'SUN', 'MON', 'TUE', 'WED', 'THU', 'FRI']
    month_list = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

    if (0 < a <= 12) and (0 < b <= month_list[a-1]):

        answer = ''
        total_day = 0

        for i in range(a-1):
            total_day += month_list[i]

        total_day += b-1

        answer = day_list[total_day % 7]

        return answer

    else:
        return "잘못된 값입니다."


while (True):
    M, D = map(int, input().split())

    if M < 0:
        break

    else:
        print(DAY(M, D))
