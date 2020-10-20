def solution(progresses, speeds):
    # my answer
    answer = []

    while progresses:
        new_n = len(progresses)
        for i in range(new_n):
            progresses[i] += speeds[i]
        if progresses[0] < 100:
            continue
        else:
            count = 0
            while progresses and progresses[0] >= 100:
                progresses.pop(0)
                speeds.pop(0)
                count+=1
            answer.append(count)
        
    return answer

#if I used time, there would be only one while loop
"""
def solution(progresses, speeds):
    answer = []
    time = 0
    count = 0
    
    while len(progresses)> 0:
        if (progresses[0] + time*speeds[0]) >= 100:
            progresses.pop(0)
            speeds.pop(0)
            count += 1
        else:
            if count > 0:
                answer.append(count)
                count = 0
            time += 1
            
    answer.append(count)
    return answer
"""


#advanced answer
"""
def solution(progresses, speeds):
    Q=[]
    for p, s in zip(progresses, speeds):
        if len(Q)==0 or Q[-1][0]<-((p-100)//s):
            Q.append([-((p-100)//s),1])
        else:
            Q[-1][1]+=1
    return [q[1] for q in Q]
"""

result = solution([93, 30, 55], [1, 30, 5])

for i in result:
    print(i)
