# MidProject_05_source
# IT공학과 1614000 박미현


def SieveOfEratosthenes(N):  # 에라토스테네스 체 방식의 소수판별 함수 정의
                             # 결과 값이 없는 함수  


        # init
        sieve = {}  # 딕셔너리로 체 생성                    
        for i in range(2, N+1):
            sieve[i] = 1  # 모두 1로 초기화해놓기
            

        # Sieve of Eratosthenes
        for i in range(2, N+1):
            if sieve[i]==1: # 검사해보자!(초기화 모두 1로 했었음)
                n=2
                while i*n <= N: 
                        sieve[i*n]=0 # 작은 수의 배수부터 차례로..소수 아니라고 0으로 바꿔놓기
                        n+=1 


        #print results
        for i in range(2, N+1):
            if sieve[i]==1: # 1로 남아있다면
                print( i, end="  " ) # 소수가 맞음-> 출력.


 

 

# 메인코드
while True:  # -1이 입력될 때까지 계속 루프를 돌며 정수를 입력받아야 한다

    N = int( input("N값을 입력하세요 : ") )  # 사용자로부터 입력받고


    if N<=0: # 0 이하의 입력이 들어오면
            print("잘못 입력하였습니다. 1이상의 값을 입력하여 주십시오.")
    else: # 올바른 수를 입력 받으면
            SieveOfEratosthenes(N)  # 함수호출하여 원하는 처리 실행

   
    if N == -1:  # 입력받은 수가 -1이라면
        exit()  # 프로그램 종료시키기
       
    print("\n")  # 가시성을 높이기 위함(루프 한번 돌릴 때마다)                 
 


