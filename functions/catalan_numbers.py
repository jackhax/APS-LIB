def catalan(n):   
    cat_ = 1
    print(cat_, " ", end = '')
    for i in range(1, n):        
        cat_ *= (4 * i - 2);
        cat_ //= (i + 1);
        print(cat_, " ", end = '')
n = int(input())
catalan(n)
