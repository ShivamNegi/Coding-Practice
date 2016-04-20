INF = 999999999

def printSolution(distGraph):

    string = "inf"

    nodes =distGraph.keys()

    for n in nodes:

        print "\t%6s"%(n),

    print " "

    for i in nodes:

        print"%s"%(i),

        for j in nodes:

            if distGraph[i][j] == INF:

                print "%10s"%(string),

            else:

                print "%10s"%(distGraph[i][j]),

        print" "

def floydWarshall(graph):

    nodes = graph.keys()

    distance = {}

    for n in nodes:

        distance[n] = {}

        for k in nodes:

            distance[n][k] = graph[n][k]

    for k in nodes:

        for i in nodes:

            for j in nodes:

                if distance[i][k] + distance[k][j] < distance[i][j]:

                    distance[i][j] = distance[i][k]+distance[k][j]

    printSolution(distance)

if __name__ == '__main__':

    graph = {'A':{'A':0,'B':6,'C':INF,'D':6,'E':7},

             'B':{'A':INF,'B':0,'C':5,'D':INF,'E':INF},

             'C':{'A':INF,'B':INF,'C':0,'D':9,'E':3},

             'D':{'A':INF,'B':INF,'C':9,'D':0,'E':7},

             'E':{'A':INF,'B':4,'C':INF,'D':INF,'E':0}

             }

    floydWarshall(graph)