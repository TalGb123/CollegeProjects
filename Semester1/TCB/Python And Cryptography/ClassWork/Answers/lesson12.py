def Q1(num):
    if num == 0:
        return 0
    return num + Q1(num - 1)

# print(Q1(20))

def Q2(num):
    if num == 0:
        return "0"
    elif num == 1:
        return "1"
    return Q2(num // 2) + str(num % 2)

# print(Q2(8))

def Q3(num):
    if num == 0:
        return 0
    return 1 + Q3(num // 10)

# print(Q3(123124))

def Q4(num, val):
    if num == 0:
        return 0
    if num%10 == val:
        return 1 + Q4(num // 10, val)
    return Q4(num // 10, val)

# print(Q4(123124, 1))

def Q5(num, val):
    if num == 0:
        return 0
    dig = num % 10
    if dig == val:
        return Q5(num // 10, val)
    return Q5(num // 10, val) * 10 + dig



print(Q5(123124, 1))