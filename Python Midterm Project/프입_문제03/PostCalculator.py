# PostCalculator.py
# 후위표기법으로 변환된 수식을 계산하는 코드

from Stack import *


# 숫자인지를 판별해주는 함수 정의
def isDigit(s):
    try:
        float(s)
        return True
    except ValueError:
        return False

    



# 본격적인 EvalRPNExp 함수구현
# 후위표기법 수식을 계산하는 함수 정의
def EvalRPNExp(exp):

    stack = Stack()
    expLen = len(exp)



    for i in range(expLen):
        
        tok = exp[i]
        '''한 문자씩 tok에 저장하고'''


        
        if (isDigit(tok)):
            '''문자의 내용이 정수인지 확인한다.'''
            stack.push( int(tok) )
            '''정수면 숫자로 변환 후 스택에 넣기'''
            
        else:
            '''정수가 아닌 연산자라면'''
            op2 = stack.pop()
            '''스택에서 두 번째 피연산자 꺼낸다'''
            op1 = stack.pop()
            '''스택에서 첫 번째 피연산자 꺼낸다'''


            '''연산하고 그 결과를 다시 스택에 넣기'''
            if tok == '+':
                stack.push(op1+op2)
            elif tok == '-':
                stack.push(op1-op2)
            elif tok == '*':
                stack.push(op1*op2)
            elif tok == '/':
                stack.push(op1/op2)


    return stack.pop()
    '''마지막 연산결과를 스택에서 꺼내어 반환'''

        
