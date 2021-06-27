'''
n = int(input())
m = int(input())
e = [int(x) for x in input().split(' ')]
'''

def sol(n,m,e):
    first = 1
    second = 1
    i = 0
    if n == 2 and m == 1:
        return 0
    if n == 2:
        return 1
    
    for x in range(3,n+1):
        t = second
        second = first**2 + second
        first = t
        if(i<m and x == e[i]):
            second = second - first
            first = 0
            i+=1
        if(second == 0):
            return second
    return second

#print(sol(n,m,e))
'''
n = 23
m = 1
e = [15]

i = 0
fib = [1]

if(n == 1):
    print(1)
else:
    for x in range(2,n+1):
        if(len(fib) == 1):
            fib.append(fib[0])
        else:
            term = fib[x-3]**2 + fib[x-2]
            fib.append(term)
        if(i<m and e[i] == x):
            fib[x-1] = fib[x-1] - fib[x-2]
            fib[x-2] = 0
            i+= 1
print(fib)
'''