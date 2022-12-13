# CS 225 Final Project - Navigating through New York
This GitHub Repository is for our UIUC CS225 group project. The members include Aditya Asthana, Agrim Kataria, Prem Dhoot, and Tabeeb Khandaker. Here is the link to our video presentation https://drive.google.com/file/d/19PQiv0kaAVQzGbKSYvF_OJIIOdTchyb6/view?usp=sharing.

# What is our project?
Our project's leading question was "What is the best way to get between points of interest in New York City?". We utilize Djikstra's Algorithm to find the shortest path between points of interest and Betweenness Centrality to find which points of interest would be the best starting point. We implement a Breadth-First-Search traversal to acheive this. Our dataset of points of interest come from NYC Open Data, and can be found at the following link: https://data.cityofnewyork.us/City-Government/Points-Of-Interest/rxuy-2muj.

# How to use our project
First, paste the following command in your terminal to download our program: "git clone https://github.com/Aditya-Asthana/data_structures_project.git".
Our project uses a clang++ and a Makefike to compile, so we build and run the executable with the following method.

Open the repo in VSCode using open folder in container, and select Dockerfile.

Use "cd build" in the terminal to get to our build folder.

Run "make" in your terminal. This will create the main executable.

Then run "./main" in your terminal. This will run our program.

Our outputs will print in the terminal.

# Testing

Open the repo in VSCode using open folder in container, and select Dockerfile.

To test our code, enter "cd build" in the terminal to get to our build folder.

Run "make" in your terminal.

Then run "./test" in your terminal. This will run our test cases.

Our test cases use a portion of the dataset and test if our graph builds correctly. It also makes sure our implementation Djikstra's algorithm and the betweenness centrality algorithm are functioning correctly.

# Understanding our repo

The majority of our graph implementation is in the SRC file of our project. The SRC file has POIMap and POIGraph files. POIGraph has our graph traveral and algorithms in it, and POIMap has functions to help create the graph. From main, in the POI's file you will find "Point_Of_Interest.csv" which is the raw data we got from NYC Open Data. In "POI_parsed.csv" you can see how our data was arrranged after parsing. In our repo you will also find a tests file which holds our test cases and files. Lastly, in the build file you will find our Makefile and all other relevant compiling compnents.
