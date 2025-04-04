def radix_sort(A):
    u = max(A)
    for pos in range(len(str(u))):
        bucket = [[] for i in range(10)]
        for num in A:
            index = (num//(10**pos)) % 10
            bucket[index].append(num)
        A = [val for row in bucket for val in row]
    return A
 
#TestBench
A = [4,3,2,1]
print(radix_sort(A))

