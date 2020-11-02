# Infix_To_Postfix.py
# 중위표기법 -> 후위표기법으로 바꾸는 코드


from Stack import *

# ConvToRPNExp함수 구현에 앞서 이를 도울 함수1
# 연산자의 연산 우선순위 정보를 반환한다.
def GetOpPrec(op):
    
    if(op == '*'):
        '''가장 높은 연산의 우선순위'''
        return 5
    elif(op == '/'):
        '''가장 높은 연산의 우선순위'''
        return 5
    
    
    elif(op == '+'):
        '''5보다 작고 1보다 높은 연산의 우선순위'''
        return 3
    elif(op == '-'):
        '''5보다 작고 1보다 높은 연산의 우선순위'''
        return 3

       
    else:
        '''등록되지 않은 연산자'''
        return -1




# ConvToRPNExp함수 구현에 앞서 이를 도울 함수2
# 두 연산자의 우선순위를 비교하여, 그 결과를 반환하는 함수
def WhoPrecOp(op1, op2):

    op1Prec = GetOpPrec(op1)
    op2Prec = GetOpPrec(op2)

    if (op1Prec > op2Prec):
        '''op1의 우선순위가 더 높다면'''
        return 1
    elif(op1Prec < op2Prec):
        '''op2의 우선순위가 더 높다면'''
        return -1
    else:
        '''op1과 op2의 우선순위가 같다면'''
        return 0



# ConvToRPNExp함수 구현에 쓰일 함수 구현3
# 숫자인지 아닌지에 따라 참거짓을 반환하는 함수
def isDigit(s):
    
    try:
        float(s)
        return True
    except ValueError:
        return False






# 본격적인 ConvToRPNExp 함수구현
# 이 파일의 핵심인  중위표기법 수식을 후위표기법 수식으로 바꾸는 함수 정의
def ConvToRPNExp(exp):
    '''문자열 수식(아직 중위표기법으로 된)이 입력변수로 들어온다'''




    expLen = len(exp)
    stack = Stack()
    '''클래스에 대한 객체 생성'''
    convExp = []
    idx = 0
    '''리스트convExp안에서 위치를 세기위한 변수'''


    # stack object 생성 확인
    print(stack)
    # 스택 비어있나 일단 확인
    print( stack.items )





    # 입력된 문자열의 문자 하나씩을 가져와서 판단하는 코드 구현
    for i in range(expLen):
        
        tok = exp[i]

        # 해당 문자가 숫자(피연산자)라면 convExp에 넣는다.
        if (isDigit(tok)):
            convExp.append(tok)
            idx = idx+1
      
        # 해당 문자가 연산자라면 stack에 넣는다.
        elif (tok == '+','-','*','/'):
            while( not(stack.isEmpty()) & WhoPrecOp( stack.sPeek(), tok ) >= 0):
                convExp.append( stack.pop() )
                idx = idx+1
                '''while문 설명
                   스택에 데이터가 들어있고,
                   기존 스택에 들어있는 요소가 tok에 있는 연산자보다 우선순위가 높으면,
                   실행한다는 문장이다.'''
            stack.push(tok)
            

    # 스택에 연산자가 잘 들어가있나 확인
    print( stack.items )
    '''스택 위일수록 연산자의 우선순위가 높다.'''
    '''즉, 출력되는 리스트 오른쪽으로 갈수록 연산자 우선순위가 높다'''


     

    #스택에 데이터가 남아있다면 스택에 남아있는 모든 연산자를 리스트배열convExp 로 옮겨버린다.
    while( not(stack.isEmpty()) ):
        convExp.append(stack.pop())
        idx= idx+1

    exp = convExp


    


    #후위표기법으로 기술된 수식이다. 연산자의 경우, 앞일수록 우선순위가 더 높다.
    return exp


