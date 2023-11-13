'''
Derek Poston
November 13th, 2023
Question 11
code and inspiration borrowed for Dijkstra's and other assorted issues,
as reflected in e-mail sent to Dr. J
'''


#undirected graph
undir_graph = [[0,1,0,0,0,0],
               [1,0,1,0,1,0],
               [0,1,0,1,1,0],
               [0,0,1,0,1,0],
               [0,1,1,1,0,1],
               [0,0,0,0,1,0]]

#list of connections between undirected graph
undir_graph_connect = [[1],[0, 2, 4],[1,4,3],[2,4],[3,2,1,5],[4]]


#directed graph
dir_graph = [[0,1,0,0,0,0],
             [0,0,1,0,0,0],
             [0,0,0,0,1,0],
             [0,0,1,0,0,0],
             [0,1,0,1,0,0],
             [0,0,0,0,1,0]]

#list to contain connections in directed graph
dir_graph_connect = [[1],[2],[4],[2],[3,1],[4]]


#create array to hold visited / unvisited nodes
ALLPATHS = []
#Global variable for given integer N
N = 0


#compare defined values with N
def pathCount():
    validPaths = 0
    for path in ALLPATHS:
        #if a list in ALLPATHS has N nodes minus the start node(the path length is N)
        if len(path)-1 == N:
            validPaths += 1


    print("\nAll paths:", ALLPATHS)
    #this is valid paths
    print("Valid paths:", validPaths)


#function to find paths between two nodes in a directed graph
def dirPath(currNode, endNode, currPath):
    #declare the global variable ALLPATHS
    global ALLPATHS

    #base case checks if the current node is equal to the end node
    if currNode == endNode:
        #append the current path to ALLPATHS
        ALLPATHS.append(currPath)
        return

    #iterate through the neighbouring nodes of the current node
    for neighbour in dir_graph_connect[currNode]:
        #if the neighbour is not in the current path
        if neighbour not in currPath:
            #make a recursive call and pass in the neighbour as the current node, the end node, and the current path plus the neighbour
            dirPath(neighbour, endNode, currPath+[neighbour])


#function to find paths between two nodes in a undirected graph
def undirPath(currNode, endNode, currPath):
    #declare the global variable ALLPATHS
    global ALLPATHS

    #base case checks if the current node is equal to the end node
    if currNode == endNode:
        #append the current path to ALLPATHS
        ALLPATHS.append(currPath)
        return

    #iterate through the neighbouring nodes of the current node
    for neighbour in undir_graph_connect[currNode]:
        #if the neighbour is not in the current path
        if neighbour not in currPath:
            #make a recursive call and pass in the neighbour as the current node, the end node, and the current path plus the neighbour
            undirPath(neighbour, endNode, currPath+[neighbour])
    

#define main
def main():
    global N
    
    #prompts user input
    graph = input("1. Directed\n2. Undirected\n")
    if graph != "1" and graph != "2":
        print("Invalid graph entry\n")
        main()


    print("\nThe graph includes the nodes 0 1 2 3 4 5\n")

    #prompt the user for the path length, start node, and end node
    N = int(input("Enter the path length: "))
    startNode = int(input("Enter the starting node: "))
    endNode = int(input("Enter the end node: "))

    #if the inputted start and end nodes are equal, display a message to the user
    if startNode == endNode:
        print("\nStart node is equal to end node")
        return

    #call the correct function based on the graph selected and check for valid node entry
    if graph == "1":
        if startNode > len(dir_graph)-1 or endNode > len(dir_graph)-1:
            print("Invalid node entered\n")
            main()
        dirPath(startNode, endNode, [startNode])
        
    elif graph == "2":
        if startNode > len(undir_graph)-1 or endNode > len(undir_graph)-1:
            print("Invalid node entered\n")
            main()
        undirPath(startNode, endNode, [startNode])

    pathCount()


#call the main function
if __name__ == '__main__':
    main()
