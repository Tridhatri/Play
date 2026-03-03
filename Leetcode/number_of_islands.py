# Probably wrong code. Will clean up later. Just want to get the idea down.
grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
#Output: 1

# queue

from collections import deque



# It is better to use visisted as set

visited = set()

q = deque()
# Queue acts like a thing to keep track of the recursive 1s that we need to check for.


directions = [[0,1], [0,-1], [-1,0], [1,0]]
# right: j+1, left: j-1, up: i-1, down: i+1

def traversal(i, j , grid, directions, direction_to):
    if direction_to == "right":
        # traverse right
        i = i+directions[0][0]
        j = j+directions[0][1]

    elif direction_to == "left":
        # traverse left
        i = i+directions[1][0]
        j = j+directions[1][1]

    elif direction_to == "up":
        # traverse up
        i = i+directions[2][0]
        j = j+directions[2][1]

    elif direction_to == "down":
        # traverse down
        i = i+directions[3][0]
        j = j+directions[3][1]
    
    modified_i = i
    modified_j = j

    # Boundary check
    if i < 0 or i >= len(grid) or j < 0 or j >= len(grid[0]):
        return False, modified_i, modified_j

    to_check = grid[i][j]

    if (to_check == "1"):
        return True, modified_i, modified_j
    else:
        return False, modified_i, modified_j



count = 0

for i in range(len(grid)):
    for j in range(len(grid[i])):
        # Do something
        # count 1s
        # count as island
        # it needs to be surrounded by 1s
        # we will traverse by directions and see if we find 1
        # use traversal func and see if there are any 1s

        tuple = (i,j)

        if (tuple in visited):
            continue
            # So we skip the rest of the code and move on to the next i,j

        # Only process if this is land ("1")
        if grid[i][j] != "1":
            continue

        # So if it is not in visited and is land, we will check if it is an island or not. If it is an island, we will add it to the queue and then check for its neighbors. We will do that until there is nothing else in the queue. Then we will add count +=1.
        # First add it to queue
        q.append(tuple)
        visited.add(tuple)
        count += 1  # Found a new island, increment here
        
        while(q.__len__() > 0): 
            # pop left to get the first queue element and then continue the check
            (curr_i, curr_j) = q.popleft()



            status_right, modified_i, modified_j = traversal(curr_i, curr_j, grid, directions, "right")
            modified_tuple = (modified_i, modified_j)
            if status_right and (modified_tuple not in visited):
                q.append(modified_tuple)
                visited.add(modified_tuple)
                # We only add land cells to queue and visited

            # left 
            status_left, modified_i, modified_j = traversal(curr_i, curr_j, grid, directions, "left")
            modified_tuple = (modified_i, modified_j)
            if status_left and (modified_tuple not in visited):
                q.append(modified_tuple)
                visited.add(modified_tuple)

            # up  
            status_up, modified_i, modified_j = traversal(curr_i, curr_j, grid, directions, "up")
            modified_tuple = (modified_i, modified_j)
            if status_up and (modified_tuple not in visited):
                q.append(modified_tuple)
                visited.add(modified_tuple)

            # down 
            status_down, modified_i, modified_j = traversal(curr_i, curr_j, grid, directions, "down")
            modified_tuple = (modified_i, modified_j)
            if status_down and (modified_tuple not in visited):
                q.append(modified_tuple)
                visited.add(modified_tuple)

        # Basically after all the queue is exhausted, we have marked all connected land as one island.
        # The count was already incremented when we started this BFS.

print(f"Number of islands: {count}")
