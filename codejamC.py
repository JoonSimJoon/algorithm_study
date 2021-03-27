def create(N):
    l = []
    for i in range(1,N+1):
        l.append(i)
    return l

def Query(N,P):
    l = []
    if P<N-1 :
        return []
    T = 0
    C = 1
    for i in range (N-1, 0,-1):
        C+=1
        if T+C+i-1>=P :
            R= P - T - i + 1
            l.append(R)
            for k  in range(i-1):
                l.append(1)
            T=P 
            break
        T+=C
        l.append(C)
    if T<P : 
        return []
    return l

def f(l,opt):   
    optl = len(opt)
    for i in range(optl):
        T = len(l) - (i+2)
        fp = T+opt[i]
        l=l[:T]+list(reversed(l[T:fp]))+l[fp:]
    return l

def main():
    ip = input().split()
    x = int(ip[0])
    y = int(ip[1])
    l = create(x)
    Q = Query(x,y)
    l = f(l,Q)
    ans = " "
    if Q: 
        for it in l:    
            ans+=str(it)+" "
    else:
        ans = " IMPOSSIBLE"
    print("Case #"+str(i+1)+":"+str(ans))

for i in range(int(input())):
    main()