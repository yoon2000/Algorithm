import sys

input = sys.stdin.readline

def dfs(graph, start, visited, point):
    nxt = graph[start]
    visited.append(start)
    val = 1

    for vertex in nxt:
        if vertex == point:
            continue
        if vertex not in visited:
            val += dfs(graph, vertex, visited, point)
    
    return val

def validateArticulationPoint(graph, start, point, n):
    val = dfs(graph, start, [], point)
    return val == n-1

def getStart(n, point):
    for i in range(1, n+1):
        if(i != point):
            return i
        
def findArticulationPoints(graph, n):
    articulationPoints = []
    for point in range(1, n+1):
        start = getStart(n, point)
        if not validateArticulationPoint(graph, start, point, n):
            articulationPoints.append(point)

    return articulationPoints

def findBiConnectedComponents(graph, articulationPoints):
    components = []
    visited = []

    def dfsBCC(vertex, parent, stack, low, disc, result):
        children = 0
        disc[vertex] = low[vertex] = len(stack) + 1
        visited.append(vertex)
        stack.append(vertex)

        for neighbor in graph[vertex]:
            if neighbor not in visited:
                children += 1
                dfsBCC(neighbor, vertex, stack, low, disc, result)
                low[vertex] = min(low[vertex], low[neighbor])

                if low[neighbor] >= disc[vertex]:
                    component = set()
                    while (stack[-1] != neighbor):
                        component.add(stack.pop())
                    component.add(stack.pop())
                    components.append(component)
            elif neighbor != parent and disc[neighbor] < low[vertex]:
                low[vertex] = disc[neighbor]

        if parent is None and children > 1:
            component = set()
            while stack:
                component.add(stack.pop())
            components.append(component)

    for point in articulationPoints:
        if point not in visited:
            dfsBCC(point, None, [], {}, {}, components)

    return components

if __name__ == '__main__':
    t = int(input().strip())

    for _ in range(t):
        n = int(input().strip())
        graph = {}

        for _ in range(n):
            vertex = list(map(int, input().split()))
            node = vertex[0]
            adjacents = vertex[2:]
            graph[node] = adjacents

        articulationPoints = findArticulationPoints(graph, n)

        bcc = len(findBiConnectedComponents(graph, articulationPoints)) - 1
        if(bcc == -1):
            bcc = 1
        print(bcc)
        print(len(articulationPoints), end=' ')
        print(*sorted(articulationPoints))