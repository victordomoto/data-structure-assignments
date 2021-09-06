# Data structure assignments

Some applications of data structures used in the disciplines of algorithm and data structure I/II

### Brief description of each structure:

* **Stacks:** all the inserts, remotions and generally all accesses are carried out in a single far end, named top;


* **Queue:**  all removals and, in general, the accesses are performed in a end (front), and all inserts are made in another end (back); 


* **List:** a linear list is a data structure in which elements of a same type of data are logically organized in a way sequential:
  * **Linked list:** lists are unidirectional, that is, list follow starts from a point, the beginning, and goes to the end;
  
  * **Doubly circular linked list:** list has properties of both doubly linked list and circular linked list in which two consecutive elements are linked or connected by previous and next pointer and the last node points to first node by next pointer and also the first node points to last node by the previous pointer;


* **Graph:** a collection of nodes that have data and are connected to other nodes:
  * **Adjacency matrix :** a 2D array of size V x V where V is the number of vertices in a graph;
  * **Linear list  :** creates a simple topic map where each topic is associated to two other topics. First and last topics have exceptionally only one neighbor topic and one association;
  
  
* **Tree:**  A tree is a collection of nodes connected by directed (or undirected) edges. A tree is a nonlinear data structure, compared to arrays, linked lists, stacks and queues which are linear data structures. A tree can be empty with no nodes or a tree is a structure consisting of one node called the root and zero or one or more subtrees;

### Sorting algorithms:
Basically, a sorting algorithm puts an array in order, that is, it sorts a vector

* **Bubble sort:** this algorithm performs pairwise comparisons, that is, it repeats this process until the entire vector is ordered. So, it works well for small arrays, but it has a very high complexity, that is, a lot of computational cost;
  * **Complexity:** O(n²);

* **Insertion sort:** the array elements are compared with each other sequentially and then arranged simultaneously in some particular order;
  * **Complexity:** O(n²);

* **Mergesort:** a sort algorithm that splits the items to be sorted into two groups, recursively sorts each group, and merges them into a final, sorted sequence;
  * **Complexity:** O(n log n);

* **Quicksort:** like merge sort, quick sort is a divide and conquer algorithm. It picks an element as pivot and partitions the given array around the picked pivot;
  * **Complexity:** O(n²);

* **Heapsort:** heap sort is a comparison-based sorting technique based on Binary Heap data structure. It is similar to selection sort where we first find the minimum element and place the minimum element at the beginning. We repeat the same process for the remaining elements;
  * **Complexity:** O(n log n);

* **Binary search tree:** can be defined as a class of binary trees, in which the nodes are arranged in a specific order;
  * **Complexity:** O(n);

* **AVL tree:**  a self-balancing Binary Search Tree where the difference between heights of left and right subtrees cannot be more than one for all nodes;
  * **Complexity:** O(n);

* **Red-black tree:** a kind of self-balancing binary search tree where each node has an extra bit, and that bit is often interpreted as the colour (red or black). These colours are used to ensure that the tree remains balanced during insertions and deletions;
  * **Complexity:** O(log n);

* **Hash table:** hashing is a technique or process of mapping keys, values into the hash table by using a hash function. It is done for faster access to elements. The efficiency of mapping depends on the efficiency of the hash function used;
  * **Complexity:** O(n);


