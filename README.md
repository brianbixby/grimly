# grimly
Grimly is 42 Starfleet second project!!!
In this project, you have to find the shortest path to solve a maze

# How to test it
1. Make (to compile it & make a executive file called grimly)
2. ./grimly ./tests/01.map ./tests/02.map ./tests/03.map ...
or ./grimly and write on the stdin
or cat name_of_map | ./grimly

# How it works
The algorithm uses an algorithm I created that's a combination of Dijkstra's
Algorithm and BFS (Breadth-First Search).

Initially the algorithm reads the input and checks for errors. 
Errors in the maze considered are: 
All lines must respect the sizes given in the first line (LINExCOL). 

  ■  There can only be one entrance. ∗ There must be at least one exit. 
  ■  There must be a solution to the labyrinth. 
  ■  The labyrinth will not be more than a billion square. 
  ■  At the end of each line, there is a new line. 
  ■  The characters present in the card must be only those shown on the first line.
 
The program creates a 2D array of minimum ditances to each cell in the maze starting from the entrance. The program does this by taking the minimum value + 1 of the 4 unvisited and "empty" neighboring cells (x +- 1, y) && (x, y +- 1). Qualifying cells are added to the queue and this process repeats. My algorithm also compares neighboring that have minimum distances that need to be recalculted. When the 2D array of shortests distances to each cell is returned I simply compare the value at the exit coordinates and the program responds acccordingly.
