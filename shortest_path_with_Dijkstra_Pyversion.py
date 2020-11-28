import heapq
import sys
MAX = 300001

if __name__ == "__main__":
    #input
    V, E = map(int, sys.stdin.readline().split())
    startvertex = int(sys.stdin.readline())
    heap = []
    d = [MAX for i in range(V+1)] #currently found min cost from startvertex to destination(using relaxation)
    adj = [[] for i in range(V+1)]
    for i in range(E):
        u, v, w = map(int, sys.stdin.readline().split())
        #u: source, v: destination, w: weight
        adj[u].append([w,v]) #adj[i][j][0]: cost, adj[i][j][1]: dest


    #start Dijkstra
    d[startvertex] = 0
    heapq.heappush(heap, [d[startvertex], startvertex])

    while(heap):
        current_d, vertex = heapq.heappop(heap)

        for x in adj[vertex]:
            if x[0] + current_d < d[x[1]]:
                d[x[1]] = x[0] + current_d
                heapq.heappush(heap, [d[x[1]], x[1]])

    for i in range(1, V+1):
        if d[i] != MAX:
            print(d[i])
        else:
            print("INF")
