def merge_sort(A, a = 0, b = None): # Sort sub-array A[a:b]
    if b is None: # O(1) initialize
        b = len(A) # O(1)
    if 1 < b - a: # O(1) size k = b - a
        c = (a + b + 1) // 2 # O(1) compute center
        merge_sort(A, a, c) # T(k/2) recursively sort left
        merge_sort(A, c, b) # T(k/2) recursively sort right
        L, R = A[a:c], A[c:b] # O(k) copy
        i, j = 0, 0 # O(1) initialize pointers
        while a < b: # O(n)
            if (j >= len(R)) or (i < len(L) and L[i] < R[j]): # O(1) check side
                A[a] = L[i] # O(1) merge from left
                i = i + 1 # O(1) decrement left pointer
            else:
                A[a] = R[j] # O(1) merge from right
                j = j + 1 # O(1) decrement right pointer
            a = a + 1 # O(1) d



merge_sort([1,7,6,5,10,12,9])