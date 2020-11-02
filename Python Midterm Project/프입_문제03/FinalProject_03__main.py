# FinalProject_03__main.py
# 메인코드!


from PostCalculator import *
from Infix_To_Postfix import *



# 사용자로부터 수식 문자열 입력받는다.
Infix_Exp = input("수식(문자열)을 입력하세요.:")



# 입력된 중위표기법 수식을  후위표기법 수식으로 변환하여, 연산자와 피연산자를 분리하도록 한다.
Postfix_Exp = ConvToRPNExp(Infix_Exp)

# 후위표기법으로 잘 변환 됐는지 확인
print("후위표기법으로 전환된 수식 확인: ", Postfix_Exp)

# 후위표기법으로 된 수식을 계산한다. 계산된 결과를 변수result에 넣는다.
result = EvalRPNExp(Postfix_Exp)



# 최종 연산결과를 출력한다.
print("최종 연산결과는 ", result, "입니다.")




