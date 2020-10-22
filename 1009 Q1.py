"""
게임 화면은 1 x 1 크기의 칸들로 이루어진 N x N 크기의 정사각 격자이며 위쪽에는
크레인이 있고 오른쪽에는 바구니가 있습니다. (위 그림은 5 x 5 크기의 예시입니다).
각 격자 칸에는 다양한 인형이 들어 있으며 인형이 없는 칸은 빈칸입니다.
모든 인형은 1 x 1 크기의 격자 한 칸을 차지하며 격자의 가장 아래 칸부터 차곡차곡 쌓여 있습니다.
게임 사용자는 크레인을 좌우로 움직여서 멈춘 위치에서 가장 위에 있는 인형을 집어 올릴 수 있습니다.
집어 올린 인형은 바구니에 쌓이게 되는 데, 이때 바구니의 가장 아래 칸부터 인형이 순서대로 쌓이게 됩니다.
다음 그림은 [1번, 5번, 3번] 위치에서 순서대로 인형을 집어 올려 바구니에 담은 모습입니다.
크레인 작동 시 인형이 집어지지 않는 경우는 없으나 만약 인형이 없는 곳에서 크레인을
작동시키는 경우에는 아무런 일도 일어나지 않습니다.
또한 바구니는 모든 인형이 들어갈 수 있을 만큼 충분히 크다고 가정합니다.

게임 화면의 격자의 상태가 담긴 2차원 배열 board와 인형을 집기 위해 크레인을
작동시킨 위치가 담긴 배열 moves가 매개변수로 주어질 때, 크레인을 모두 작동시킨 후
터트려져 사라진 인형의 개수를 return 하도록 solution 함수를 완성해주세요.

[제한사항]
board 배열은 2차원 배열로 크기는 5 x 5 이상 30 x 30 이하입니다.
board의 각 칸에는 0 이상 100 이하인 정수가 담겨있습니다.
0은 빈 칸을 나타냅니다.
1 ~ 100의 각 숫자는 각기 다른 인형의 모양을 의미하며 같은 숫자는 같은 모양의
인형을 나타냅니다.
moves 배열의 크기는 1 이상 1,000 이하입니다.
moves 배열 각 원소들의 값은 1 이상이며 board 배열의 가로 크기 이하인 자연수입니다.
"""

def solution(board, moves):
    #initialize
    answer = 0
    result_stack=[]
    n = len(board)
    n_minus_height_of_column = [-1]*n  #counts the number of zero for each column
    
    #i traces row, j traces column
    #board[i][j]
    for i in range(n):
        for j in range(n):
            if board[i][j] != 0 and n_minus_height_of_column[j] == -1:
                n_minus_height_of_column[j] = i
    
    """for i in n_minus_height_of_column:
        print(i)"""

    for j in moves:
        if n_minus_height_of_column[j-1] != n: # if they are same, that column is empty
            result_stack.append(board[n_minus_height_of_column[j-1]][j-1])
            #board[n_minus_height_of_column[j-1]][j-1] = 0 #no need
            n_minus_height_of_column[j-1] += 1
        if len(result_stack) >= 2:
            if result_stack[-2] == result_stack[-1]:
                result_stack.pop()
                result_stack.pop()
                answer+=2
        
    return answer

#advanced
"""
def solution(board, moves):
    stacklist = []
    answer = 0

    for i in moves:
        for j in range(len(board)):
            if board[j][i-1] != 0:
                stacklist.append(board[j][i-1])
                board[j][i-1] = 0

                if len(stacklist) > 1:
                    if stacklist[-1] == stacklist[-2]:
                        stacklist.pop(-1)
                        stacklist.pop(-1)
                        answer += 2     
                break

    return answer
"""

input1=[[0,0,0,0,2],[0,0,1,0,3],[0,2,5,0,1],[4,2,4,4,2],[3,5,1,3,1]] #square input
input2=[1,5,3,5,1,2,1,4]


print(solution(input1,input2))
