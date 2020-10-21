import sys


# global
average = 0

# 파일명이 입력될 경우, 입력된 파일로부터 데이터를 읽는다.
if len(sys.argv)==2: 
    f = open(argv[1], 'r')
# 파일명을 입력하지 않을 경우, default로 “students.txt”로부터 데이터를 읽는다.
else:
    f = open("students.txt", 'r+')
    

def cal_grade(average):
    if average>=90:
        grade= 'A'
    elif 80<=average<90:
        grade = 'B'
    elif 70<=average<80:
        grade = 'C'
    elif 60<=average<70:
        grade = 'D'
    else:
        grade = 'F'
    
    return grade


head=[]
def title():
    for i in range(len(head)):
        print(head[i],"     ", end='')
    print("\n--------------------------------------------------------------------")
head.append("Student")
head.append("Name")
head.append("Midterm")
head.append("Final")
head.append("Average")
head.append("Grade")

title()

line = f.readline()


arr=[] #잠시 l리스트의 요소들 저장해둘 임시 저장 리스트.
    
while line:
#     print('%s' %line)
    l = line.split()

    l[2]=int(l[2])
    l[3]=int(l[3])
    
    midterm = l[2]
    final = l[3]
    average = (midterm + final)/2.0
      
    l.append(average) # average = l[4]
    l.append(cal_grade(average))
   
    arr.append(l)
  
    line = f.readline()



# 평균 점수를 기준으로 내림차순 정렬
l = sorted(arr, key = lambda x:x[4], reverse=True)

for i in range(len(l)):
    print(l[i])
print("\n")


f.close()




student_id="" #global

def show(): #내림차순 정렬 및 출력해서 보여주기.
    
    a = sorted(l, key = lambda x:x[4], reverse=True) #a는 새 리스트(argument 다르게 해야해서)
    
    for i in range(len(a)):
        print(a[i])
    print("\n")
    
    
    
def search():
    student_id = input("Student ID: ")
    
    n = False
    for i in range(0, len(l)):
        if l[i][0] == student_id:
            n = True
            title()
            print(l[i])
         
    if n == False:
        print('NO SUCH PERSON.')

    print("\n")
       
        
        
def changescore():
    student_id = input("Student ID: ")
    
    n = False
    average = 0
    
    for i in range(0, len(l)):
        if l[i][0] == student_id:
            n = True
            
            test_type = input("Mid/Final? ")
            test_type = test_type.lower()      
            if test_type not in ['mid', 'final']:
                break #pass 및 continue 쓰면 안됨!
            
            new_score = input("Input new score: ")
            new_score = int(new_score)
            if new_score<0 or new_score>100:
                break #pass 및 continue 쓰면 안됨!


            title()
            # 바뀌기전꺼 한 번 출력해주기
            for i in range(len(l)):
                if l[i][0] == student_id: 
                    print(l[i])

            for j in range(0,5):
                if l[j][0]==student_id:
                    if test_type == "mid":
                        l[j][2] = new_score
                        l[j][4] = (new_score + l[j][3]) / 2.0 #중간 점수가 변하면 평균점수도 바뀜
                    elif test_type == "final":
                        l[j][3] = new_score
                        l[j][4] = (l[j][2] + new_score) / 2.0 #기말 점수가 변하면 평균점수도 바뀜    
                    l[j][5] = cal_grade(l[j][4])#중간 또는 기말 점수가 변하면 학점도 바뀜    

            for i in range(len(l)):
                if l[i][0] == student_id: #for문 돌리면서 성적 바뀐 학생이면
                    print("Score changed.")
                    print(l[i]) #바뀐 점수로 업데이트한 줄만 출력

    if n == False:
        print('NO SUCH PERSON.')   
    print("\n")

    
    
def add():
    student_id = input("Student ID: ")

#     먼저 입력된 학번의 학생이 있는지 확인하기.
    m = False
    for i in range(0, len(l)):
        if l[i][0] == student_id:
            m = True
             
    if m == True:
        print('ALREADY EXISTS.')
    else: #여전히 fasle라면   
            newStudent=[] #새로 입력될 학생리스트

            student_name = input("Name: ")
            student_mid_score = input("Midterm Score: ")
            student_mid_score = int(student_mid_score)
            student_final_score = input("Final Score: ")
            student_final_score = int(student_final_score)

            student_average = (student_mid_score+student_final_score)/2.0


            newStudent.append(student_id)
            newStudent.append(student_name)
            newStudent.append(student_mid_score)
            newStudent.append(student_final_score)

            newStudent.append(student_average)
            newStudent.append(cal_grade(student_average))

            l.append(newStudent) #전체 학생 명단 리스트에 새로운 학생 리스트 추가
            print("Student added.")
    print("\n")

       
   
    
def searchgrade():
    grade = input("Grade to search: ")
    grade = grade.upper()
    
    n = False
    if grade in ['A', 'B', 'C', 'D', 'F']:#A, B, C, D, F 중 하나의 값을 잘 입력했고
        for i in range(0, len(l)):
            if grade == l[i][5]: #해당 grade의 학생이 한 명 이상 있을때
                n = True
                print(l[i]) #바뀐 점수로 업데이트한 줄만 출력
        print("\n")
        if n == False: #해당 grade의 학생이 한명도 없어서 여전히 false값일때
            print('NO RESULTS.')
            print("\n")
    else: #A, B, C, D, F 외의 값 입력
        print("\n")
        pass
        
        
        
def remove():
    student_id = input("Student ID: ")
    
    
    if not l:
        print("List is empty.")
    
    n = False

    for k in range(0,len(l)):
        if student_id == l[k][0]:
            l.remove(l[k])
            print("Student removed.")
            break
    
    if n == False:
        print('NO SUCH PERSON.')     
    print("\n")

            
    
    
def quit():
    answer = input("Save data?[yes/no] ")
    answer = answer.lower()
    
    if answer == "yes":
        filename  = input("File name: ") 
        f = open(filename, 'w')
        
        for x in range(len(head)):
            f.write(head[x])
            f.write("     ")
        f.write("\n")
        for y in range(66):
            f.write("-")#구분용
        f.write("\n")
     
        # f.write()는 문자열만 들어갈 수 있으므로, 학생목록 리스트 요소들을 모두 문자열로 변환해주기.
        for i in range(len(l)):
            for j in range(len(l[i])):
                l[i][j] = str(l[i][j]) #모든 요소가 문자열이 된 상태
         
        for p in range(len(l)):
            for q in range(len(l[p])):
                f.write(l[p][q])#문자열 상태로 넣어야함
                f.write(" ")
            f.write("\n")

        f.close()
    
    sys.exit()


    
       
while True:
    operand = input("#")
    operand=operand.lower()
    
    if operand == "show":
        show()
    elif operand == "search":
        search()
    elif operand == "changescore":
        changescore()
    elif operand == "add":
        add()
    elif operand == "searchgrade":
        searchgrade()
    elif operand == "remove":
        remove()
    elif operand == "quit":
        quit()
    else:
        continue
