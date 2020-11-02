# MidProject_02_source.py
# IT공학과 1614000 박미현



def IsLeapYear(year): # IsLeapYear함수정의, 인수로 연도를 넘긴다

    if ((year%4 == 0) & (year%100 != 0)) | (year%400 == 0): # 윤년이면
        return True
    else: # 윤년이 아니면
        return False
        


        

# 메인코드

while True: # -1이 입력될 때까지는 계속 루프를 돌며 정수를 입력받아야 한다.
    
    
    year = int(input("연도를 입력하시오: ")) 


    if year<=0: # 0 이하의 입력이 들어오면
       print("잘못 입력하였습니다. 1이상의 값을 입력하여 주십시오.")
    else:
          # 올바른 연도 입력을 받으면 다음 실행 
          if ( IsLeapYear(year)==True ): # 함수 호출. 함수는 True 아니면 False값을 리턴한다
              print("입력된 연도는 윤년 입니다.")
          else:
              print("입력된 연도는 윤년이 아닙니다.")
             


    if year == -1: # 입력받은 수가 -1이라면
        exit() # 프로그램 종료시키기

        

    print("\n") # 가시성을 높이기 위함(루프 한번 돌릴 때마다)








  






