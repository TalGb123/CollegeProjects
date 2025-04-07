def Q1(n):
    first = 0
    second = 1
    print(first, second, end = ", ")
    for i in range(n-2):
        print(first+second, end = ", ")
        first, second = second, first+second

# Q1(10) # Output: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34,
# Q1(15) # Output: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377,
# Q1(2)  # Output: 0, 1,

def Q2():
    for i in range(1000, 10000):
        if (i//1000+i//100%10) == (i//10%10+i%10):
            print(i)
            
# Q2() # output: many numbers

def Q3(n):
    total_sum = 0
    for i in range(1, n + 1):
        power = 1
        for _ in range(i):
            temp = 0
            for _ in range(i):
                temp += power
            power = temp
        total_sum += power 
    return total_sum

# print(Q3(6))  # Output: 50069
# print(Q3(2))  # Output: 5


def Q4_FIRST():
    count = 0
    for i in range(10000, 100000):
        n = i
        flag = 0
        for j in range(5):
            temp = n%10
            n//=10
            if temp > n%10:
                flag += 1
        if flag == 5:
            count += 1
            print(count, i) 
            
            
def Q4_SECOND():
    count = 0 
    for i in range(10000, 100000):
        if i%10 > i//10%10 > i//100%10 > i//1000%10 > i//10000:
            count += 1
            print(count, i)
           
# Q4_FIRST() 
# Q4_SECOND()

def Q5(n):
    flag = 0
    for i in range(1, n+1):
        if flag == 0:
            for j in range(1, i+1):
                print(j, end = "")
            print()
            flag = 1
        else:
            for j in range(i, 0, -1):
                print(j, end = "")
            print()
            flag = 0

# Q5(5) 

def spacer(n):
    for i in range(n):
        print(" ", end = "")
        
def star(n):
    for i in range(n):
        print("*", end = "")
        
def Q6(n):
    for i in range(n):
        spacer(n-i-1)
        star(2*i+1)
        print()
        
# Q6(5)

def hash(n):
    for i in range(n):
        print("#", end = "")
        
def Q7(n):
    for i in range(n):
        star(i)
        hash(n-i)
        print()
        
# Q7(6)

def num_printer(n):
    for i in range(1, n+1):
        print(i, end = "")
    for i in range(n-1, 0, -1):
        print(i, end = "")
        
def Q8(n):
    for i in range(n):
        spacer(n-i-1)
        num_printer(i+1)
        print()
    
# Q8(5)