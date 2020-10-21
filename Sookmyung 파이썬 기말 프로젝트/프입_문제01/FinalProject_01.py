# FinalProject_01.py
# IT공학과 1614000 박미현

from graphics import *


# 윈도우 창을 생성하고 창에 대한 속성을 설정한다.
win = GraphWin(" Final Project 01 ", 1300,600)
win.setCoords( -1.4, -6.5, 12, 50)
win.setBackground('thistle1')

# 프로그램 제목을 텍스트 라벨로 띄운다. 
title = Text( Point(6.5, 45), ' The program that counts the number of occurrences of words, within any File. ')
title.setSize(21)
title.setStyle("bold italic")
title.setFill('salmon')
title.draw(win)

# x축 정보(x축은 단어임)를 알려주는 라벨을 띄운다.
Xaxis_LabelShowing = Text(Point(11.7, -0.28),'Word')
Xaxis_LabelShowing.setSize(12)
Xaxis_LabelShowing.setStyle("bold italic")
Xaxis_LabelShowing.setFill('black')
Xaxis_LabelShowing.draw(win)
# y축 정보(y축은 단어 빈도 수임)를 알려주는 라벨을 띄운다.
Yaxis_LabelShowing = Text(Point(-0.52, 45.5),'The Number of word')
Yaxis_LabelShowing.setSize(12)
Yaxis_LabelShowing.setStyle("bold italic")
Yaxis_LabelShowing.setFill('black')
Yaxis_LabelShowing.draw(win)

# 종료 안내 메시지 텍스트 띄우기.
quitLabel = Text(Point(11, 48),'(종료시키려면 아무 키나 누르세요)')
quitLabel.setSize(8)
quitLabel.setFill('brown4')
quitLabel.draw(win)

# 학번 이름 텍스트 띄우기.
quitLabel = Text(Point(11.35, -5.55),'by  1614000 박미현')
quitLabel.setSize(9)
quitLabel.setFill('brown4')
quitLabel.draw(win)

# x축과 y축을 나타내는 선을 그린다.
xline = Line(Point(-0.5,0),Point(11.4,0))
xline.draw(win)
'''x축 그리기''' 
yline = Line(Point(-0.5,0),Point(-0.5,44))
yline.draw(win)
'''y축 그리기'''



# 각종 단어들로 구성된 텍스트 파일을 읽기 모드로 연다.
f = open('input.txt', 'r')
'''텍스트 파일 읽기모드로 열기'''




def main():


    # 변수 초기화
    w = -0.5
    '''x축에 기준좌표(단어들)를 찍어놓기 위해 쓰일 변수'''
    h = 0
    '''y축에 기준좌표(0, 10, 20, 30, 40...)를 찍기위해 사용되는 변수'''
    colorIndex = 0
    '''for문을 돌리면서 barColorList리스트 요소들을 하나씩 돌기 위한 변수'''


    # 각각의 Vertical Bar에 색깔을 입히기 위해 색깔 리스트 객체를 만들어둔다.
    barColorList = [ 'old lace', 'antique white', 'blanched almond', 'bisque',
             'peach puff', 'navajo white', 'lemon chiffon', 'mint cream',
             'lavender', 'lavender blush', 'misty rose',
                     'old lace', 'antique white', 'blanched almond', 'bisque',
             'peach puff', 'navajo white', 'lemon chiffon', 'mint cream',
             'lavender', 'lavender blush', 'misty rose',
                     'old lace']

    
    # ----------------------------------------------------------------------------------


    # for문을 돌려서 y축 기준좌표(단어빈도수: 0, 10, 20, 30, .... , 150) 찍기
    for i in range(16):
        Y_axis = Text(Point(-0.65, h/3.5), h)
        Y_axis.setSize(9)
        h = h+10
        Y_axis.draw(win)
        '''y축에는 0, 10, 20, 30, 40....이런식으로  숫자가 적혀진 텍스트가 찍히게 된다.'''
        '''h/3.5 -> 기준 좌표들의 높이 조정 '''

        # Y축 기준좌표 표시 눈금 찍기 
        marking = Line(Point(-0.46, h/3.5), Point(-0.54, h/3.5))
        marking.draw(win)


    # ----------------------------------------------------------------------------------


    # 빈 딕셔너리 선언
    frequency = {}


    # 텍스트 파일 내용의 모든 문자를 소문자로 바꾼다.
    all_string = f.read().lower()

    # 공백(스페이스, 탭, 엔터등)을 기준으로 문자열 분리
    all_string = all_string.split()






    # 딕셔너리에 '단어(key값):단어빈도수(value값)'정보를 차례차례 넣는 과정
    # 파일 내 모든 단어에 대한 처리(빈도 수 세기)를 진행한다
    for word in all_string:
     
        count = frequency.get(word, 0)
        frequency[word] = count + 1



    # frequency딕셔너리의 key값(word)들만 가져와 리스트 자료형으로 리턴한다.
    key_word_list = list( frequency.keys() )



    #--------------------------------------------------1.전체정렬  /  2.정렬되었으면 앞에서 23개까지만 출력되도록 한다.



    # 모든 단어 목록의 리스트key_word_list의 요소들을 오름차순으로 정렬
    key_word_list.sort()
   

    # 리스트(전체:샘플링 전)에 총 몇개 단어가 있는지 확인
    print( "Q: 해당 파일은 모두 몇 개의 단어로 구성이 되어있는가? :")
    print( "A:", len(key_word_list), "개 이다." )
    print( " " )


    # 전체단어가 들어있는  key_word_list에서 23개 단어만 추출하여 샘플링리스트에 넣기
    sampling_key_word_list = []

    for s in range(23):
        sampling_key_word_list.append( key_word_list[s] )


    # 23개의 단어만 sampling한 이유 안내문 출력
    print( "모든 단어들의 정보를 띄우기에는 가로 길이의 여유가 넉넉치 않다." )
    print( "그래서 23개의 단어 정보에 대해서만 막대 그래프를 그릴 것이다." )
    print( "윈도우 창에 정보를 그릴 단어들 정보는 다음과 같다." )


    
    # ----------------------------------------------------------------------------------
    


    # 이제 전체 단어들 중 추출한 23개의 단어들에 대해서!! Shell창에 따로 정보를 출력하고, for문을 돌려 그래프를 그릴 것이다.
    i = 0
    print("<Word", ":", "The Number of Word>")

    for words in sampling_key_word_list:
        
        # Shell창에도 파악하기 좋게 단어와 해당 단어의 빈도수 정보를 표시해두도록 한다.
        print(words, ":", frequency[words], "개")





        #가로 - key값 문자 상태
        vocabulary = i
        #높이 - key값에 대응되는 value값. 즉, 빈도 수는 높이이다.
        vocabulary_num = frequency[words]
        '''새로 선언된 숫자형 변수 -> for문 한 번 돌 때마다 이 변수는 바뀔 것임'''
        vocabulary_num = vocabulary_num/3.5



        # x축 기준좌표(word목록) 나타내기
        X_axis = Text(Point( w+0.25 , -1), words)
        X_axis.setSize(8)
        X_axis.setFill('gray17')
        X_axis.draw(win)
        '''X축에는 샘플링된 23개의 단어목록 텍스트가 X축 아래에 일렬로 찍히게 된다.'''

        # 해당 단어에 대한 빈도수를 나타내는 Vertical Bar chart를 그린다.
        rect = Rectangle(Point(w ,0), Point(w+0.5,vocabulary_num) )
        '''+0.5는 수직 막대 바의 width임.'''
        rect.setFill(barColorList[colorIndex])
        rect.draw(win)



        # for문이 한 번 돌때마다 w, colorIndex, i값을 하나씩 올려준다.
        w = w+0.5
        '''수직bar의 가로길이가 0.5니까'''
        colorIndex = colorIndex+1
        i = i+1
        '''키값은 단어이므로 문자열 상태. 따라서 숫자로 바꿔줘야 한다. 그에 쓰일 변수가i'''


    # ----------------------------------------------------------------------------------


    # 아무 키나 누르면 종료시키도록 한다.
    win.getKey()
    win.close()


main()
'''메인함수 종료'''


# 열었던 파일을 닫아준다
f.close()
