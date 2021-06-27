from tqdm import tqdm
#n = int(input())
#S = input()
def solve(S,n):
    S = ''.join(sorted(S))
    o = ''
    m = int(n/2)
    pbar = tqdm(total=m)
    if(n%2 == 1):
        m += 1
    for i in range(m):
        pbar.update(i)
        if(i == m-1 and n%2 == 1):
            o += S[i]
        else:
            o = o + S[i] + S[n-i-1]
    #print(o)
    pbar.close()
    return o