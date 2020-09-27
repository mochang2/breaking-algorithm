"""
H-Index는 과학자의 생산성과 영향력을 나타내는 지표입니다. 어느 과학자의 H-Index를 나타내는 값인 h를 구하려고 합니다. 위키백과1에 따르면, H-Index는 다음과 같이 구합니다.

어떤 과학자가 발표한 논문 n편 중, h번 이상 인용된 논문이 h편 이상이고 나머지 논문이 h번 이하 인용되었다면 h의 최댓값이 이 과학자의 H-Index입니다.

어떤 과학자가 발표한 논문의 인용 횟수를 담은 배열 citations가 매개변수로 주어질 때, 이 과학자의 H-Index를 return 하도록 solution 함수를 작성해주세요.

제한사항
과학자가 발표한 논문의 수는 1편 이상 1,000편 이하입니다.  #1<=len(citations)<=1000  
논문별 인용 횟수는 0회 이상 10,000회 이하입니다.           #0<=citations[i]<=10000
"""

import math

def solution(citations):
    answer = 0

    if max(citations) == 0:    #in case of 0 array
        return 0
    if min(citations) == max(citations):
        return min(len(citations), citations[0])
    
    citations.sort()
    left = 0
    right = len(citations) - 1

    while left <= right:
        mid = math.ceil((left+right)/2)

        if len(citations[mid:]) == citations[mid]:
            answer = citations[mid]
            break
        elif len(citations[mid:]) > citations[mid]:
            left = mid + 1
        else:
            right = mid - 1

    if right < 0:
        return min(len(citations), citations[0])
    
    if answer == 0:
        answer = citations[left]
        while len(citations[right:]) <= answer and citations[right] != citations[left]:
            answer -= 1

    return answer



input_li = [10, 10, 10, 10, 11, 11]
result = solution(input_li)

print(result)
