hossz = int(input())
l = {}

for _ in range(hossz):
    uj = input()
    fst = uj[:2]
    snd = uj[1:]

    if fst in l:
        l[fst][1].append(snd)
    else:
        l[fst] = (0, [snd])

    if snd in l:
        l[snd] = (l[snd][0] + 1, l[snd][1])
    else:
        l[snd] = (1, [])


# https://www.geeksforgeeks.org/hierholzers-algorithm-directed-graph/
# Python3 function to print Eulerian circuit in given
# directed graph using Hierholzer algorithm

def printCircuit(adj):

        # adj represents the adjacency list of
        # the directed graph
        # edge_count represents the number of edges
        # emerging from a vertex
    edge_count = dict()

    for i in adj:

        # find the count of edges to keep track
        # of unused edges
        edge_count[i] = len(adj[i])

    if len(adj) == 0:
        return  # empty graph

    # Maintain a stack to keep vertices
    curr_path = []

    # vector to store final circuit
    circuit = []

    # start from any vertex
    curr_path.append(curr)
    curr_v = curr  # Current vertex

    while curr_path:

        # If there's remaining edge
        if edge_count[curr_v]:

            # Push the vertex
            curr_path.append(curr_v)

            # Find the next vertex using an edge
            next_v = adj[curr_v][-1]

            # and remove that edge
            edge_count[curr_v] -= 1
            adj[curr_v].pop()

            # Move to next vertex
            curr_v = next_v

        # back-track to find remaining circuit
        else:
            circuit.append(curr_v)

            # Back-tracking
            curr_v = curr_path[-1]
            curr_path.pop()

    # we've got the circuit, now print it in reverse
    ordered[:] = circuit[:0:-1]


ends = [(l[a][0] - len(l[a][1]), a) for a in l if l[a][0] != len(l[a][1])]

empty = not ends
if empty:
    curr = next(iter(l.keys()))
    ends.append((-1, curr))
    ends.append((1, l[curr][1][0]))
else:
    ends.sort()

if len(ends) != 2 or ends[0][0] != -1 or ends[1][0] != 1:
    print("NO")
    exit()

curr = ends[0][1]
l[ends[1][1]][1].append(ends[0][1])

ordered = []
printCircuit({x: l[x][1] for x in l})

if not empty:
    for i in range(len(ordered)-1):
        if ordered[i] == ends[1][1] and ordered[i+1] == ends[0][1]:
            ordered = ordered[i+1:] + ordered[:i+1]
            break

if len(ordered) != hossz+1:
    print("NO")
else:
    print("YES")
    print(''.join(ordered)[::2] + ordered[-1][-1])
