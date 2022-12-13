**The output and correctness of the algorithm
Algorithms/Traversal Implemented:

Dijkstra Algorithm: We used Djikstra's algorithm to calculate the shortest path between two distances. We also added a great feature where the user is able to add a middle point from start to finish and able to experience a lot more of NYC with very minor changes in distance traveled. The algorithm uses the weight of the edges protruding the source node and approaches the middle node in a similar manner. By summing the distances from start -> mid and mid -> destination, we're able to come up with a plan for the user. We tested dijkstra by choosing three random points from our data table. The function worked as expected

Betweenness Centrality: We use the betweenness centrality theorem to find out which nodes are most connected and have the smallest distance to neighboring nodes. The function takes in a place of interest and returns an integer that represents how connected it is. By running the method on all nodes of a graph, we can find out which nodes are the most optimal starting spot for tourists. It works as operated.

BFS: We used BFS to traverse a graph to gain access to every node distance-wise. Since BFS traverses a graph by levels, we return a list of strings that contain points of interest in ascending order of distances from the source. This way, we're able to keep a running list of points of interest based on their distance. We tested this by adding custom made points of interests with latitudes and longitudes placed in an increasing fashion. When tested, BFS returned a list of strings in the format we expected.


**The answer to your leading question:
Leading Question: What is the shortest distance to get between multiple points of interest in New York City?
With the help of dijkstra's algorithm, we were able to provide the user with an experience like none other. We included a landmark function in our code base that takes in a starting point, a midpoint, and a destination point. With the help of this function, the user is able to visit multiple POIs in New York City and save a lot of time. Not only is our algorithm efficient time-wise, but it's also efficient in the sense that the user is able to get the most out of the city without spending too much of their precious time.

Originally, our leading question included restaurants but as we started working on the project, we realized that integrating these databases would result in a very complicated graph. For time's sake, we decided to implement just the POIs because although it would be great if we were able to suggest restaurants close to points of interest, it's equally as important to ensure that all the features and algorithms are completed in a timely fashion.

All the algorithms that we planned to implement worked as expected. We were able to traverse a graph using BFS and with the help of Dijkstra's algorithm and Betweenness Centrality, we were able to calculate optimal paths throughout NYC. As a team, we would definitely come up with a structured plan and account for all situations and worst case scenarios so we don't have to make minor changes in the project as we work on it. Overall, the process was incredibly smooth and working as a team was an invaluable experience.

