All the files of my cluster finding project are in this repository. The programs are written in c++.

Program description -
-----------------------

Project Name : Finding clusters.

Problem : Given a set of data, find the clusters. The data can be positions of particles, some statistical properties, or anything else.or some properties of the objects.

The approach : Here I have implemented the friends of friends of algorithm. In this, if two particles are within a predefined distance, called Linking Length, they belong in the same cluster. I carry the calculations for all the particle pairs and sort them in clusters. The choice of linking length can be arbitrary. Generally, it could be typical size of the cluster found in nature.

Methods : I have implemented two methods; basic for loop search and a union find method.

Basic method - The program reads the data and then finds all the pairs which have distances less than the linking length. Then it takes a pair (i,j), searches in the list of already clustered particle if they are present. If i is present in a cluster and j is not, then j is put in the same cluster. Same goes if j is found and i is not. If none of them are in any previous clusters then a new cluster is started with them as members. This is done for all the eligible pairs and finally we will have the clusters with particle ids belonging to each of them.
It gives the correct result in serial. In parallel, it needs to synchronize at each step, so it becomes expensive. I parallelized the check if i or j is in any previous clusters but it did not speed it up very much, which is expected as there is not much to do inside the parallel and large overhead is associated with it.

Union find method - Here too, the reading and finding vcalid pairs are same as the other method. But when sorting them in clusters the union find algorithm is used. Here the clusters are found vis interconnected array element serach, the eligible particles being the array elements. This algorithm is much faster (O(N)) than the previous one (o(N^3)). The parallelization faces the same issue of synchronization though, so I parallelized the calculate distances of pairs part. It didn't gain significant performance improvement.

The output figures are included in the pdf copy of presentation.


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
