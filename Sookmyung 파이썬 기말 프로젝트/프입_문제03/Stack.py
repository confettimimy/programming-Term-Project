# Stack.py
# 스택 코드
'''다른 py파일에서 import하여 사용할 것이다.'''

class Stack:
    
    def __init__(self):
        self.items = []

        
    def push(self, x):
        self.items.append(x)

        
    def pop(self):
        return self.items.pop()
        """items_length = len(self.items)

        if(items_length < 1):
            print("Stack is Empty")
            return False
        
        result = self.items[items_length - 1]
        del self.items[items_length - 1]
        return result"""
    
    
    def isEmpty(self):
        return not self.items


    def sPeek(self):
        '''peek -> 엿보기 : 맨 위 값 반환만 하고 삭제는 안함'''
        '''최상단 데이터 확인'''
        return self.items[-1:]



