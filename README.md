All the files of my cluster finding project are in this repository. The programs are written in c++.

Program description -
-----------------------

Project Name : Finding clusters.

Problem : Given a set of data, find the clusters. The data can be positions of particles, some statistical properties, or anything else.or some properties of the objects.

The approach : Here I have implemented the friends of friends of algorithm. In this, if two particles are within a predefined distance, called Linking Length, they belong in the same cluster. I carry the calculations for all the particle pairs and sort them in clusters. The choice of linking length can be arbitrary. Generally, it could be typical size of the cluster found in nature.

Methods : I have implemented two methods; basic for loop search and a union find method.

Basic method - 


List of files - 
----------------------
cluster_basic_method_serial.cpp --> Basic method, serial version
cluster_basic_method_parallel.cpp --> Basic method, parallel version
ufind.cpp --> Union find method, serial version
parallel_ufind.cpp --> Union find method, parallel version
test1pos.txt --> Input data, 6 particles
test3pos.txt --> Input data, 200 particles
test4pos.txt --> Input data, 3000 particles
test5pos.txt --> Input data, 12000 particles
585 hpc presentation.pdf --> a pdf copy of class presentation

Change the input file name in the  programs for different data sets.
Standard compile and run commands.
