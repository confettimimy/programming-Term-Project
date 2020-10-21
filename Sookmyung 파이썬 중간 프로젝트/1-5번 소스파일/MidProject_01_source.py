# MidProject_01_source.py
# IT공학과 1614000 박미현
import math



def IsPrime(num): # 소수이면 True, 소수가 아니면 False를 반환해주는 함수 정의

    last = int(math.sqrt(num))  # 루트num 까지만 나눠보면 된다


    if num==2: # 2와 3은 소수이므로 루프에 들어가기 전에 우선 소수라고 판별한다. 
        return True
    elif num==3: 
        return True
    else: # 사용자가 2와 3이 아닌 정수를 입력했을 때       
        if num%2 == 0: # num을 2로 나눈 나머지가 0이라면
            return False # 소수가 아님
        
        for i in range(3, last+1): # num을 3부터 나눠보기 시작한다
            if ((num%i) == 0): # num을 i로 나누었을때 나머지가 0이면
                return False #소수가 아님


    return True # 1~last(루트 자기자신)사이에 약수가 없으므로 소수이다




# 메인코드
while True: # 정수-1이 입력될 때까지 계속 루프를 돌리며 정수를 입력받도록 한다
    
    num = int(input("정수를 입력하세요. 소수인지 판별해드리겠습니다. : "))
    

    if num<=0: # 의도치 않은 정수를 입력 받았을때
        print("잘못 입력하였습니다. 2이상의 값을 입력하여 주십시오.")
        
    else: # 알맞는 정수를 입력 받았다면 이제 소수인지 판별 시작
          if ( IsPrime(num)==True ): # 소수인지를 판별해주는 함수 호출
              print("입력받은 숫자는 소수입니다.")
          else:
              print("입력받은 숫자는 소수가 아닙니다.")

    
    if num==-1: # -1이 입력되면 
        exit()  # 루프에서 빠져나와 프로그램 종료
        
    print("\n") # 루프 한 번 실행될 때마다 구분지어주기. 가독성을 높이기 위한 코드
        

        
