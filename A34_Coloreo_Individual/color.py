"""
    This program solves coloring a graph with
    the least amount of colors available.

    The coloring of each node can't be the same for adjacent nodes.

    - It uses the Welsh-Powell Algorithm

    Author: Rodrigo Terán Herández
    Date: 08/11/2023
"""

from config import COLORS

def sortAdj(adjArray, keyed, reversed=False):
    adjArray.sort(key=lambda adjE: adjE.get(keyed, 0), reverse=reversed)

"""
    Time complexity: O(n^2)
    - At the most the first loop os going to run 4 times do to a theorem
    - n: Being the number of nodes
"""
def colorGraph(matrix):
    try:
        # Array of nodes representing its number of adjacent nodes
        arrayNodes = []
        arrayNodesColored = []

        for i in range(len(matrix)): # O(n)
            row = matrix[i]
            adj = sum(row)
            arrayNodes.append({
                "i": i,
                "adj": adj,
                "colored": False
            })
        
        sortAdj(arrayNodes, "adj", True)

        amountColored = 0
        refIndex = 0
        currentColor = 0

        while amountColored < len(matrix): # O(4)
            currentNode = arrayNodes[refIndex]
            if currentNode.get("colored", False):
                refIndex += 1
                continue
            
            arrayNodesColored.append({
                "i": currentNode.get("i", 0),
                "color": COLORS[currentColor]
            })
            amountColored += 1

            appendedIndexes = []

            for iNextNode in range(refIndex + 1, len(matrix)): # O(n)
                auxNode = arrayNodes[iNextNode]

                if auxNode.get("colored", False):
                    continue
                
                if matrix[auxNode.get("i", 0)][currentNode.get("i", 0)]:
                    # They are adjacent
                    continue

                hadConflict = False
                for allI in appendedIndexes: # O(n)
                    if matrix[auxNode.get("i", 0)][allI]:
                        # They are adjacent
                        hadConflict = True
                        break

                if hadConflict:
                    # There was a conflict in adjacencies
                    continue

                arrayNodesColored.append({
                    "i": auxNode.get("i", 0),
                    "color": COLORS[currentColor]
                })
                arrayNodes[iNextNode] = {
                    "i": auxNode.get("i", 0),
                    "adj": auxNode.get("adj", 0),
                    "colored": True
                }
                appendedIndexes.append(auxNode.get("i", 0))
                amountColored += 1
            
            currentColor += 1
            refIndex += 1

            if currentColor >= len(COLORS) and amountColored < len(matrix):
                print("No es posible asignar colores a los nodos")
                return None
            
        sortAdj(arrayNodesColored, "i")
        
        return arrayNodesColored
        
    except error:
        print(error)