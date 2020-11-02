from graphics import *


# 윈도우 창을 생성하고 창에 대한 속성을 설정한다.
win = GraphWin("Student-Score Vertical Bar Chart", 600,600)
win.setCoords( -1, -8, 12, 50)
win.setBackground('thistle1')

# 프로그램 제목을 텍스트 라벨로 띄운다. 
title = Text( Point(5.5, 46), ' The Number of Occurrences of Each Score ')
title.setSize(18)
title.setStyle("bold")
title.setFill('gray34')
title.draw(win)

# x축 정보(x축은 성적임)를 알려주는 라벨을 띄운다.
Xaxis_LabelShowing = Text(Point(0.88, -4.16),'X-axis: Score ')
Xaxis_LabelShowing.setSize(12)
Xaxis_LabelShowing.setStyle("bold italic")
Xaxis_LabelShowing.setFill('maroon1')
Xaxis_LabelShowing.draw(win)
# y축 정보(y축은 학생 수임)를 알려주는 라벨을 띄운다.
Yaxis_LabelShowing = Text(Point(2.415, -5.65),'Y-axis: The Number of Students ')
Yaxis_LabelShowing.setSize(12)
Yaxis_LabelShowing.setStyle("bold italic")
Yaxis_LabelShowing.setFill('maroon1')
Yaxis_LabelShowing.draw(win)

# 종료 안내 메시지 텍스트 띄우기.
quitLabel = Text(Point(10, 49.02),'(종료시키려면 아무 키나 누르세요)')
quitLabel.setSize(8)
quitLabel.setFill('brown4')
quitLabel.draw(win)

# 학번 이름 텍스트 띄우기.
quitLabel = Text(Point(10.75, -6.5),'by  1614000 박미현')
quitLabel.setSize(9)
quitLabel.setFill('brown4')
quitLabel.draw(win)

# x축과 y축을 나타내는 선을 그린다.
xline = Line(Point(0,0),Point(13,0))
xline.draw(win)
'''x축 그리기''' 
yline = Line(Point(0,0),Point(0,44))
yline.draw(win)
'''y축 그리기'''



# 점수와 학생 수 정보가 기술되어 있는 텍스트 파일을 읽기 모드로 연다.
f = open('Score_StudentNum_File.txt', 'r')

def main():
    

    # 변수 초기화
    w = 0.5
    '''x축에 기준좌표(0, 1, 2, 3....)이렇게 찍어놓기 위해 쓰일 변수'''
    h = 0
    '''y축에 기준좌표(0, 10, 20, 30, 40)를 찍기위해 사용되는 변수'''
    colorIndex = 0
    '''for문을 돌리면서 barColorList리스트 요소들을 하나씩 돌기 위한 변수'''

  
    # 각각의 Vertical Bar에 색깔을 입히기 위해 색깔 리스트 객체를 만들어둔다.
    barColorList = [ 'old lace', 'antique white', 'blanched almond', 'bisque',
             'peach puff', 'navajo white', 'lemon chiffon', 'mint cream',
             'lavender', 'lavender blush', 'misty rose',  ]



    # y축 기준좌표(학생수0~40) 나타내기
    for i in range(5):
        Y_axis = Text(Point(-0.4, h), h)
        Y_axis.setSize(9)
        h = h+10
        Y_axis.draw(win)
        '''y축에는 0, 10, 20, 30, 40의 텍스트가 찍히게 된다.'''




    # for문을 돌리기 시작한다. for문 한 번 돌때마다  파일의 한 줄에 대한 처리가 진행된다.
    for line in f.readlines():

        data = line.split(':')
        '''split()을 이용하여 ':'를 기준으로 문자열line을 분리시킨다.'''
        '''즉, data는 파일의 한 줄 정보(점수, 학생수)를 가지고 있는 리스트이다. '''   
        score = int( ''.join(data[:1]) )
        studentNum = int(data[-1])
        '''리스트date(= 파일의 한 줄 정보)의 0번째 요소는 '점수'를 뜻한다.'''
        '''리스트date(= 파일의 한 줄 정보)의 맨 마지막 요소는 '학생 수'를 뜻한다.'''



        # x축 기준좌표(점수0~10) 나타내기
        X_axis = Text(Point(w, -1), score)
        X_axis.setSize(9)
        X_axis.setFill('gray17')
        X_axis.draw(win)
        '''x축에는 0, 1, 2, 3, 4, 5...이렇게 텍스트가 찍히게 된다.'''


        # 해당 점수에 상응하는 학생 수의 Vertical Bar chart를 그린다.
        rect = Rectangle(Point(score,0), Point(score+1,studentNum) )
        rect.setFill(barColorList[colorIndex])
        rect.draw(win)
        
        # 해당 점수에 상응하는 학생 수를 나타내는 라벨을 띄운다.
        studentNum_LabelShowing = Text(Point(w, studentNum/2), studentNum)
        '''학생 수를  Bar중간에 띄워 보여주도록 한다.'''
        studentNum_LabelShowing.setSize(14)
        studentNum_LabelShowing.setFill('plum4')
        studentNum_LabelShowing.draw(win)


        # for문이 한 번 돌때마다 w, colorIndex값을 하나씩 올려준다.
        w = w+1
        colorIndex = colorIndex+1


    # 아무 키나 누르면 종료시키도록 한다.
    win.getKey()
    win.close()

main()
'''메인함수 종료'''

# 열었던 파일을 닫아준다
f.close()
