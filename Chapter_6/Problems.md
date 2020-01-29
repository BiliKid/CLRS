### 6.1 Building a heap using insertion
We can build a heap by repeatedly calling MAX-HEAP-INSERT to insert the elements into the heap. Consider the following variation on the BUILD-MAX-HEAP procedure:

    BUILD-MAX-HEAP(A) 
        A.heap-size = 1
        for i = 2 to A.length
            MAX-HEAP-INSERT(A, A[i])

a. Do the procedures BUILD-MAX-HEAP and BUILD-MAX-HEAP' always create
the same heap when run on the same input array? Prove that they do, or provide a counterexample.  
b. Show that in the worst case, BUILD-MAX-HEAP0 requires $\Theta(n\lg n)$ time to build an n-element heap.

a. They do not. Suppose having a array {1, 2, 3, 4, 5, 6, 7}, BUILD-MAX-HEAP will give {7 5 6 4 2 1 3},
and BUILD-MAX-HEAP' will give {7 4 6 1 3 2 5}.  
b. Because each MAX_HEAP_INSERT' running time is $\Theta(\lg n)$, it takes n times, thus the total running time is $\Theta(n\lg n)$.

### 6.2 Analysis of d-ary heaps

A d-ary heap is like a binary heap, but (with one possible exception) non-leaf nodes have d children instead of 2 children.  
a. How would you represent a d-ary heap in an array?  
b. What is the height of a d-ary heap of n elements in terms of n and d?  
c. Give an efficient implementation of EXTRACT-MAX in a d-ary max-heap. Analyze its running time in terms of d and n.  
d. Give an efficient implementation of INSERT in a d-ary max-heap. Analyze its running time in terms of d and n.  
e. Give an efficient implementation of INCREASE-KEY(A, i, k), which flags an error if k < A[i], but otherwise sets A[i] = k and then updates the d-ary maxheap structure appropriately. Analyze its running time in terms of d and n.

a. We modify the PARENT(i, d)=$\lfloor (i - 2) / d + 1 \rfloor$, and CHILDREN(i, d, c) = d*(i-1) + c + 1.  
b. The height is $\lfloor \log_dn \rfloor$.  
c. Exchange the max element A[i] with A[A.heap-size], then MAX-HEAPIFY will flow down to leaves, the path is $\lfloor \log_dn \rfloor$, and each level it will compare with d children, so the running time will be $O(d\log_dn)$.

    MAX-HEAPIFY(A, i) 
        largest = i
        for j = 1 to d
            child = CHILEDREN(i, d, j)
            if A[child] > A[i]
                largest = child
        if largest != i
            exchange A[largest] with A[i]
            MAX-HAEPIFY(A, largest)
    
    EXTRACT-MAX(A)
        if A.heap-size < 1
            error "the heap is empty"
        max = A[1]
        A[1] = A[A.heap-size]
        A.heap-size = A.heap-size - 1
        MAX-HEAPIFY(A, i)
        return max

d. The running time of INSERT is as same as INCREASING-KEY.
INSERT(A, key)
    A.heap-size = A.heap-size + 1
    A[A.heap-size] = MIN_MAX
    INCREASING-KEY(A, A.heap-size, key)


e. It will move up until its parent is larger than it or reach the root of the d-ary tree, so the running time is $O(\log_d n)$

    INCREASING-KEY(A, i, key) 
        if A[i] > key
            error "the key is smaller than A[i]"
        while i > 1 and A[PARENT(i)] < key
            exchange A[PARENT(i)] with key
            i = PARENT(i)

### 6.3 Young tableaus

An $m\times n$ Young tableau is an $m\times n$ matrix such that the entries of each row are
in sorted order from left to right and the entries of each column are in sorted order
from top to bottom. Some of the entries of a Young tableau may be $\infty$, which we
treat as nonexistent elements. Thus, a Young tableau can be used to hold r <= mn finite numbers.

a. Draw a $4\times 4$ Young tableau containing the elements {9,16,3,2,4,8,5,14,12}.  
b. Argue that an $m\times n$ Young tableau Y is empty if Y [1,1] = $\infty$. Argue that Y
is full (contains mn elements) if Y [m, n] < $\infty$.  
c. Give an algorithm to implement EXTRACT-MIN on a nonempty $m\times n$ Young
tableau that runs in O(m+n) time. Your algorithm should use a recursive subroutine that solves an $m\times n$ problem by recursively solving either
an $(m-1)\times n$ or an $m\times (n-1)$ subproblem.  
d. Show how to insert a new element into a nonfull $m\times n$ Young tableau in O(m+n) time.  
e. sing no other sorting method as a subroutine, show how to use an $n\times n$ Young
tableau to sort $n^2$ numbers in $O(n^3)$ time.  
f. Give an O(m+n)/-time algorithm to determine whether a given number is
stored in a given $m\times n$ Young tableau.

a. $\infty$ is show as n

    2   3   4   5  
    8   9   12  14  
    16  n   n   n
    n   n   n   n

b. If Y is not empty, the we get Y[i,j] >= Y[1,1] where i!=1 or j!=1, it violate that Y[1,1] = $\infty$.  
c. The running time is O(m+n).

    EXTRACT-IJ(Y, i, j)
        if Y[i, j] == NIL
            error "the element is not exist"
        min = Y[i, j]
        if Y[i+1,j] == NIL and Y[i, j+1] == NIL
            Y[i,j] = NIL
            return min
        if Y[i+1,j] > Y[i, j+1]
            Y[i,j] = Y[i,j+1]
            Y[i,j+1] = min
            return EXTRACT-IJ(Y, i, j+1)
        else 
            Y[i,j] = Y[i+1,j]
            Y[i+1,j] = min
            return EXTRACT-IJ(Y, i+1, j)

    EXTRACT-MIN(Y)
        EXTRACT-IJ(Y, 1, 1)
        
d. Insert a new element, it will compare the new element with leftside element and upside element, if there is one element greater than the new one, exchange the two element, until it reach the Y(1,1), so running time wile be O(m+n).  
e. We can build a Young tableau using INSERT, and using EXTRACT-MIN to get a increasing order list. both INSRET and EXTRACT-MIN take n*n times to operation, and each operation takes at most 2n running time, so the total running time is $O(n^3)$.  
f. 

    FIND(Y, key)
        i = m
        j = 1
        while i > 0 and j <= n
            if A[i,j] == key
                return (i, j)
            if A[i, j] > key
                i = i - 1
            else 
                j = j + 1