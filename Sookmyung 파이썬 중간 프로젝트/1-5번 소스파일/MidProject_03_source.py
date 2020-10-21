# MidProject_03.py
# IT공학과 1614000 박미현





def IsLeapYear(year): # 윤년 판별 함수 정의

    if ((year%4 == 0) & (year%100 != 0)) | (year%400 == 0): 
        return True
    else: 
        return False


def GetDayOfMonth(year,month): # 해당 월의 날짜 수를 리턴하는 함수 정의


    if month==1:     # 1, 3, 5, 7, 8, 10, 12월은 31일임
        return 31
    elif month==3:
        return 31
    elif month==5:
        return 31
    elif month==7:
        return 31
    elif month==8:
        return 31
    elif month==10:
        return 31
    elif month==12:
        return 31     

    elif month==4:   # 4, 6, 9, 11월은 30일임
        return 30
    elif month==6:
        return 30
    elif month==9:
        return 30
    elif month==11:
        return 30
    
    elif month==2: # 2월의 경우, 윤년과 윤년이 아닐 때 월의 날짜 수가 달라진다       
        if( IsLeapYear(year)==True ): # 윤년이면
             return 29  # 2월의 날짜 수가 29
        else: # 윤년이 아니면
             return 28  # 2월의 날짜 수가 28

    else: # 사용자가 1~12월 외에 다른 숫자를 입력하였을 경우
        print("잘못된 월을 입력하였습니다.")




# 메인코드

# 사용자로부터 연도와 월을 입력받는다.
year = int(input("연도를 입력하시오: "))
month = int(input("월을 입력하시오: "))


# 입력받은 해당 연도의 월 날짜 수를 출력한다.
print("입력하신 해당 연도 달의 날짜 수는 " + str(GetDayOfMonth(year,month)) + "일 입니다!")

    
    
