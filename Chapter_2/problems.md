### 2-1 Insertion sort on small arrays in merge sort
Although merge sort runs in $\Theta(n\lg n)$ worst-case time and insertion sort runs
in $\Theta(n^2)$ worst-case time, the constant factors in insertion sort can make it faster
in practice for small problem sizes on many machines. Thus, it makes sense to
coarsen the leaves of the recursion by using insertion sort within merge sort when
subproblems become sufficiently small. Consider a modification to merge sort in
which n=k sublists of length k are sorted using insertion sort and then merged
using the standard merging mechanism, where k is a value to be determined.

a. Show that insertion sort can sort the n/k sublists, each of length k, in $\Theta(nk)$
worst-case time.  
b. Show how to merge the sublists in $\Theta(n\lg (n/k))$ worst-case time.  
c. Given that the modified algorithm runs in $\Theta(nk+n\lg (n/k))$ worst-case time,
what is the largest value of k as a function of n for which the modified algorithm
has the same running time as standard merge sort, in terms of $\Theta$-notation?  
d. How should we choose k in practice?

a. The running time of each sublist is $\Theta(k^2)$, and there are n/k sublists, so the time is $\Theta(nk)$.  
b. There are n/k sublists, we take two sublists to merge, so there are $\Theta(\lg (n/k))$ steps, and running time is $\Theta(n)$ at each level. So the worst-cast time is $\Theta(n\lg (n/k))$.  
c. The running time of a standard merge sort is $\Theta(n\lg n)$.  
$$
\Theta(nk+n\lg (n/k)) = \Theta(nk + n\lg n - n\lg k)
$$
If $nk=n\lg k$, then the modified algorithm has the same running time as standard merge sort. So the largest value of k is $\lg n$.  
d. To choose a proper k, we assume that insertion sort take $c_1k^2$ time and merge sort take $c_2k\lg k$ time:  
$$
c_1k^2 <= c_2k\lg k
$$
and then we get the k.

### 2-2 Correctness of bubblesort
Bubblesort is a popular, but inefficient, sorting algorithm. It works by repeatedly
swapping adjacent elements that are out of order.

    BUBBLESORT(A)
        for i = 1 to A.length - 1
            for j = A.length down to i + 1
                if A[j] < A[j - 1]
                    exchange A[j] with A[j - 1]
a. Let $A'$ denote the output of BUBBLESORT(A). To prove that BUBBLESORT is
correct, we need to prove that it terminates and that  
$$
A'[1] \leq A'[2] \leq ... \leq A'[n] \qquad (2.3)
$$
where n = A.length. In order to show that BUBBLESORT actually sorts, what
else do we need to prove?  
b.  State precisely a loop invariant for the for loop in lines 2–4, and prove that this
loop invariant holds. Your proof should use the structure of the loop invariant
proof presented in this chapter.  
c. Using the termination condition of the loop invariant proved in part (b), state
a loop invariant for the for loop in lines 1–4 that will allow you to prove inequality (2.3). Your proof should use the structure of the loop invariant proof
presented in this chapter.  
d. What is the worst-case running time of bubblesort? How does it compare to the
running time of insertion sort?

a. We need to prove that $A'$ is a permutation of A.  
b. loop invariant: At the start of each iteration of the for loop of lines 2-4, A[j] is the smallest element of subarray A[j..n].    
Initialization: At the begin of first iteration, A[j..n] just contain one element-A[n], so this property is held.  
Maintenance: When j != n, exchange A[j] with A[j - 1] if A[j] is lower than A[j-1], then A[j-1] is the smallest element of A[j-1..n] before the next iteration. And this property is held.  
Termination: At termination, j = i, and A[j] is the smallest element of A[j..n].  
c. loop invariant: At the start of each iteration of the for loop of 1-4, A[1..i-1] contain the smallest elements of A in a nondecreasing order.  
Initialization: Before the first iteration, when i=1, and the subarry A[1..j-1] is empty, so this property is held.  
Maintenance: When i > 1, the subarray A[1..i-1] contains the smallest elements in an nondecreasing order, after lines 2-4, we get j==i and A[i] is the smallest element of A[i+1..n], so the loop invariant is held.  
Termination: At termination, we have i==A.length, A[1..i-1]'s elements is in an nondecreasing order, so the procedure of bubblesort is completed.  
d. The worst-case running time is $\Theta(n^2)$, it's same as insertion sort.

### Exercise 2-3 Correctness of Horner’s rule

The following code fragment implements Horner’s rule for evaluating a polynomial
$$
\begin{aligned}
P(x) & = \sum_{k=0}^{n}a^kx^k \\
& = a_0 + x(a_1 + x(a_2 + ... + x(a_{n-1} + a_nx)...)),
\end{aligned}
$$
given the coefficients $a_0, a_1...a_n$ and a value for x:

    y = 0
    for i = n downto 0
        y = ai + xy
a. In terms of $\Theta$-notation, what is the running time of this code fragment for
Horner’s rule?  
b. Write pseudocode to implement the naive polynomial-evaluation algorithm that
computes each term of the polynomial from scratch. What is the running time
of this algorithm? How does it compare to Horner’s rule?  
c. Consider the following loop invariant:  
At the start of each iteration of the for loop of lines 2–3,
$$y=\sum_{k=0}^{n-(i+1)}a_{k+i+1}x^k$$
Interpret a summation with no terms as equaling 0. Following the structure of
the loop invariant proof presented in this chapter, use this loop invariant to show
that, at termination, $y=\sum_{k=0}^{n}a_{k}x^k$.  
d. Conclude by arguing that the given code fragment correctly evaluates a polynomial characterized by the coefficients $a_0, a_1...a_n$.  

a. $\Theta(n)$.  
b. 

    NAIVE-POLYNOMIAL-EVAL(n)
        y = 0
        for i = 0 to n
            t = 1
            for j = 1 to i
                t = t*x
            y = y + ai * t
the running time is $\Theta(n^2)$, it's slower than Horner's rule.  
c. 