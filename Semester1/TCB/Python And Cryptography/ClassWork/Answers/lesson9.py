def Count(tup, val):
    return tup.count(val)
    
# print(Count((1,2,1,3,2,1),1))

def Q2(tup):
    half = len(tup) // 2
    if len(tup) % 2 == 0:
        return tup[:half] == tup[half:]
    else:
        return False

# print(Q2((2,5,1,7,2,5,1,7)))

def Q3(f, s):
    max = ()
    for i in range(len(f)):
        if f[i] >= s[i]:
            max += (f[i],)
        else:
            max += (s[i],)
    return max

# print(Q3((25,67,100,74),(80,56,85,74)))

def Q4(tup, val):
    new = ()
    count = 0
    for i in range(len(tup)):
        if tup[i] > val and count == 0:
            new += (val,)
            count = 1
        new += (tup[i],)
    return new

# print(Q4((1,3,5,7,9),6))

def Q5(tup):
    new = ()
    for i in range(len(tup)):
        if tup[i]%2 == 0:
            new += (tup[i],)
    for i in range(len(tup)):
        if tup[i]%2 != 0:
            new += (tup[i],)
    return new

# print(Q5((1,2,3,4,5,6,7,8)))