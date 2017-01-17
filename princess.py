from queue import PriorityQueue

directions = {'LEFT':(0,-1),'RIGHT':(0,1),'UP':(-1,0),'DOWN':(1,0)}

class MyPriorityQueue(PriorityQueue):
    def __init__(self):
        PriorityQueue.__init__(self)
        self.counter = 0

    def put(self, item, priority):
        PriorityQueue.put(self, (priority, self.counter, item))
        self.counter += 1

    def get(self, *args, **kwargs):
        _, _, item = PriorityQueue.get(self, *args, **kwargs)
        return item

def isValidPos(pos,n):
    if pos[0] < 0 or pos[0] >= n or pos[1] < 0 or pos[1] >= n :
        return False
    return True

def getSuccessors(pos,n):
    sucessors = []
    for dir in directions:
        nextPos = (pos[0]+directions[dir][0], pos[1]+directions[dir][1])
        if isValidPos(nextPos,n):
            sucessors.append([nextPos, dir])
    return sucessors

def getManhattanDist(pt1, pt2):
    return abs(pt1[0]-pt2[0]) + abs(pt1[1]-pt2[1])

def getPrincessPos(grid):
    for row in range(len(grid)):
        col = grid[row].find('p')
        if col != -1:
            return (row,col)
    return (-1,-1)

def nextMove(n,r,c,grid):
    princessPos = getPrincessPos(grid)
    fringe = MyPriorityQueue()
    fringe.put([((r,c), ""), []],0)
    visited = []
    while not fringe.empty():
        currentNode, pathSoFar = fringe.get()
        #print(currentNode, pathSoFar)
        path = pathSoFar + [currentNode[1]]
        if grid[currentNode[0][0]][currentNode[0][1]] == 'p':
            #print(grid[currentNode[0][0]][currentNode[0][1]])
            break
        visited.append(currentNode[0])
        for sucessor in getSuccessors(currentNode[0],n):
            if sucessor[0] not in visited:
                #print(princessPos, sucessor[0], sucessor[1], getManhattanDist(princessPos, sucessor[0]))
                fringe.put([sucessor,path], getManhattanDist(princessPos, sucessor[0]))
    return path[1]
    
n = int(input())
r,c = [int(i) for i in input().strip().split()]
grid = []
for i in range(0, n):
    grid.append(input())

print(nextMove(n,r,c,grid))
