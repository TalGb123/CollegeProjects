def Q1(num):
    count = 0
    while num != 0:
        if num % 2 == 0:
            count += 1
        num = num // 10
    return count

# print(Q1(234165))
# output: 3

def Q2(num):
    while num >= 10:
        temp = num
        num = 0
        while temp > 0:
            num += temp % 10
            temp = temp // 10
    return num

# print(Q2(999999999999993))
# output: 3
# print(Q2(197))
# output: 8

def palindrome(num):
    original_num = num
    reversed_num = 0
    while num > 0:
        digit = num % 10
        reversed_num = reversed_num * 10 + digit
        num = num // 10
    if original_num == reversed_num:
        return True
    else:
        return False
    
def Q3():
    num = int(input("Enter a number: "))
    max = 0
    while num != 0:
        if palindrome(num) and num > max:
            max = num
        num = int(input("Enter a number: "))
    return max

# print(Q3())
# input: 123, 989, 7300, 13231, 744, 6, 95340, 0
# output: 13231

def Q4(num1, num2):
    if num1 < 0:
        num1 = num1 * (-1)
    if num2 < 0:
        num2 = num2 * (-1)
    i = 0
    while True:
        if i > 9:
            break
        temp1 = num1
        temp2 = num2
        count1 = 0
        count2 = 0
        while temp1 != 0 and temp2 != 0:
            if temp1%10 == i:
                count1 += 1
            temp1 = temp1//10
            if temp2%10 == i:
                count2 += 1
            temp2 = temp2//10
        i += 1
        if count1 != count2:
            return False
    return True

# print(Q4(342126, -622314))
# output: True
# print(Q4(106, 611))
# output: False

def Q5():
    num1 = int(input("Enter first number: "))
    num2 = int(input("Enter a number: "))
    exit = num1
    # 1 for ascending, 2 for descending and -1 for no order
    if num2 > num1:
        dir = 1
    elif num2 < num1:
        dir = 2
    else:
        dir = -1
    num1 = num2
    while True:
        num2 = int(input("Enter a number: "))
        if num2 == exit:
            break
        if dir == 1 and num2 < num1:
            print("No order")
            dir = -1
            break
        elif dir == 2 and num2 > num1:
            print("No order")
            dir = -1
            break
        num1 = num2
    if dir == 1:
        print("Ascending")
    elif dir == 2:
        print("Descending")

# Q5()
# input: 1.5 56.3, 34, 1.5
# output: Ascending

def Q6():
    num = int(input("Enter a number: "))
    if num <= 1:
        return False
    if num == 2:
        return True
    if num % 2 == 0:
        return False
    i = 3
    while i * i <= num:
        if num % i == 0:
            return False
        i += 2
    return True

# print(Q6())
# input: 113
# output: True
# input: 134
# output: False