# data_structures_project
This GitHub Repository is for our UIUC CS225 group project. The members include Aditya Asthana, Agrim Kataria, Prem Dhoot, and Tabeeb Khandaker.

# Team Contract

## Communication
1. **Team Meetings** 

We will meet twice a week for one hour each time. We will meet in person so we don't need a software
tool. We will take turns writing notes at each meeting, and use a google doc shared with everyone to
store and share them. 

2. **Assistance** 

We are all close friends, so we will communicate via text message. People will be expected to 
respond the same day. 

3. **Respect** 

We will not talk over each other during meetings, so that everyone can get there ideas across with
ease. We will also be responsible for keeping up to date with the project group chat so that
everyone can do their end effevtively. We will promote sharing thoughts and ideas by giving each
person a turn to speak when needed.

## Collaboration

4. **Work Distribution** 

We will assign work equally for each part of the project, frontend or backend. Our team believes
that it's effective if we split up into two groups of two and tackle the project in that manner. Two
of our teammates are frontend maestros and the other two are well versed in Python, so we plan on
basing our project around those ideas. 

5. **Time Commitment** 

We expect about 2-3 hours of work from each group member. We will address new conflicts by covering
for our teammates. However, after repeated instances of a lack of contribution, we will have to
appraoch things differently. We expect everyone to participate equally because we each have prior 
committments that we have to work around in order to ensure a successful completion of this project.

6. **Conflict Resolution** 

If someone has a conflict, they should address it to the team two days prior to any deadline. That
way, we're able to effectively tackle any sort of conflict without impeding the progress of the
project. We don't foresee any major conflicts, maybe different ways of logical appraoch towards an
algorithm. We're all on the same page.

## Signatures

Tabeeb Khandaker - tabeeb, Prem Dhoot - premd2, Agrim Kataria - agrimk2, Aditya Asthana - asthana6

# Project Proposal

## Leading Question 
New York! The Big Apple! From local hole-in-the-wall diners to lavish sit-down restaurants, this
vast city has a plethora of delectable eateries. However, as a tourist, it can get overwhelming to
find a restaurant after visiting Times Square or the Statue of Liberty. Our project goal is to find
the closest restaurants from a point of interest in New York. With a dataset of restaurants and
points off interest in New York, we will be able to identify optimal proximities/routes between the
two.  This can be used as a general search tools for tourists to use when they need assistance. To
do this, we will use Dijkstra’s Algorithm and the Cycle Detection Algorithm to uncover multiple
restaurants and points of interests in New York. 


## Dataset Acquisition
We are getting both datasets from NYC Open Data. The link for the restaurants is the following:
https://data.cityofnewyork.us/Health/restaurant-data-set-2/f6tk-2b7a/data. The link for the points
of interests is the following: https://data.cityofnewyork.us/City-Government/Points-Of-Interest/rxu
-2muj.


## Data Format
The city of New York has two OpenData datasets that we will use - the restaurant data set and the points of interest dataset. The input of both these datasets with be as csv files. The restaurant dataset has 235k rows (the number of restaurants) and 9 columns. We will probably only need to use about 3 of those columns to access the information relevant to our project. We plan to use all the rows, so we have access to all the restaurants in the area. The points of interest dataset has 20k rows (points of interest) and 16 columns. We plan on using all the rows, but only 2 of the columns.


## Data Correction
We will be parsing the data using Pandas, and in order to make sure our data is consistent, we will 
make sure that certain fields exist, such as Name, Location, Coordinates, and other information
that is relevant to our project. Additionally, if any of the co-ordinates we're dealing with for a 
certain point of interest lie more than 15 miles from the point of interest, we would be discarding
them as outliers, primarily because there a lot of other factors to consider such as traffic,
weather conditions, and less than 15 miles is a reasonable driving distance, especially in New York
City.

## Data Storage
We are planning to save the user’s routes on Cloud storage with AWS Dynamo DB. We are utilizing
cloud storage so it is easily accessible from all the developers and does not use local memory.


## Algorithm 

Function Outputs:
The expected output of our program is the name of the restaurant, with co-ordinates that map to the
respective restaurant. The co-ordinates would then open up in Google Maps which will help the user
navigate to the nearest restaurant. 

Function Efficiency:
We will be utilizing Dijkstra’s Algorithm to solve the shortest path problem between two nodes on a
graph. Each vertex can be connected to to (V - 1) vertices, hence the number of adjacent edges to
each vertex is V - 1. Finding and updating each adjacent’s vertex is O(log(V)) + O(1) or O(log(V))
in a min heap. The time complexity for updating all adjacent vertices of a vertex is E * log(V). We
estimate the time complexity for all V vertices is V * (E*log(V)) or O(VElog(V)), where E represents
V - 1 edges connected to each vertex. 

The Function Inputs:
The expected inputs for our algorithm are information regarding points of interests and restaurants.
We will be receiving this input by parsing two different data sets and storing them as nodes in a
graph. We will parse relevant information from the dataset using Pandas and assign individual
weights to edges to detect relevancy and distance from respective points of interests.

## Timeline
Week 1:

This week we created our project idea and submitted our proposals. We also found the datasets we
used for the project.

Week 2:

In the first week, we will get the datasets and download them. We will also acquire the proper apis
such as the google maps api so we can map out the optimum routes between the restaurant and notable landmark. We will also get the data and put it in an easy and readable format for the code.


Week 3:

In this week we will start development of the A* algorithms and Djistrka’s algorithm  algorithms for our project.

Week 4:

In this week we will start development of the A* algorithms and Djistrka’s algorithm  algorithms for our project.


Week 5: 

In this week, we will start testing our project as we should be done with development. We will develop unit tests and test thoroughly especially with edge cases. We will also consider developing a front end to display our results. We will also use the google maps api to give the user a pre set optimized directions set.


Week 6:

In this week, we will finish our testing that we did the week before. We will also finish the front end. We will also record our project presentation and submit it.
