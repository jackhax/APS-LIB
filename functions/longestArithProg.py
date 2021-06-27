arr = [5,5,4,5,5,5,100,195]
count = 0
li = []
mi = []
for x in range(1,len(arr)-1):
    i = x-1
    j = x+1
    
    if(arr[i]+arr[j] == 2*arr[x]):
        if(i not in li):
            li.append(i)
        if(x not in li):
            li.append(x)
        if(j not in li):
            li.append(j)
    else:
        if(li != []):
            mi.append(li)
        li = []
if(li not in mi and li != []):
    mi.append(li)
    
print(mi)
print(len(max(mi)))