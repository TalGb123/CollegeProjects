# ------------------------------------------------
# Name: Tal Gubenko
# ID: 215681107
# ------------------------------------------------
#                   Q1
# ------------------------------------------------
def Q1( num ):
    odd_sum = 0
    if num//10000 % 2 == 0:
        print(num//10000, end=", ")
    else:
        odd_sum += num//10000
    if num//1000%10 % 2 == 0:
        print(num//1000%10, end=", ")
    else:
        odd_sum += num//1000%10    
    if num//100%10 % 2 == 0:
        print(num//100%10, end=", ")
    else:
        odd_sum += num//100%10
    if num//10%10 % 2 == 0:
        print(num//10%10, end=", ")
    else:
        odd_sum += num//10%10
    if num % 2 == 0:
        print(num)
    else:
        odd_sum += num%10
    print("\nSum odd digits:", odd_sum)
    
# ------------------------------------------------

Q1(12345)
# Even digits: 2, 4, 
# Sum odd digits: 9
# Q1(24680)
# Even digits: 2, 4, 6, 8, 0, 
# Sum odd digits: 0
# Q1(13579)
# Even digits: 
# Sum odd digits: 25


# ------------------------------------------------
#                   Q2
# ------------------------------------------------
def Q2( n1, n2, n3, n4 ):
    if n1>n2 and n1>n3 and n1>n4:
        return n1
    elif n2>n1 and n2>n3 and n2>n4:
        return n2
    elif n3>n1 and n3>n2 and n3>n4:
        return n3
    else:
        return n4
    
# ------------------------------------------------

# print(Q2(-18.5,56,17.7,-6))
# 56
# print(Q2(-18.5,56,17.7,56))
# 56

# ------------------------------------------------
#                   Q3
# ------------------------------------------------
def Q3( num ):
    flag1 = 0
    flag2 = 0
    flag3 = 0
    flag4 = 0
    if num//1000 != num//100%10 and num//1000 != num//10%10 and num//1000 != num%10:
        if num//100%10 != num//10%10 and num//100%10 != num%10:
            if num//10%10 != num%10:
                flag1 = 1
    if num//1000%2 == 0 or num//100%10%2 == 0 or num//10%10%2 == 0 or num%10%2 == 0:
        if num//1000%2 != 0 or num//100%10%2 != 0 or num//10%10%2 != 0 or num%10%2 != 0:
            flag2 = 1
    if num//1000 + num//100%10 + num//10%10 + num%10 >= 10:
        flag3 = 1
    if num//1000 + num//100%10 + num//10%10 + num%10 <= 30:
        flag4 = 1
    if flag1 == 1 and flag2 == 1 and flag3 == 1:
        return True
    print("This number cannot be used as a password:")
    if flag1 == 0:
        print("consists of the same digits")
    if flag2 == 0:
        print("consists of both odd and even digits")
    if flag3 == 0:
        print("sum of digits less than 10")
    if flag4 == 0:
        print("sum of digits greater than 30")
    return False
# ------------------------------------------------

# print(Q3(2154))
# True
# print(Q3(1021))
# This number cannot be used as a password:
# consists of the same digits
# sum of digits less than 10
# False
# print(Q3(75957))
# This number cannot be used as a password:
# consists of the same digits
# consists of odd digits
# sum of digits greater than 30
# False

# ------------------------------------------------
#                   Q4
# ------------------------------------------------
def Q4( mark ):
    if mark < 0:
        print("This number can not be Mark")
        return False
    print(f"Mark:        {mark}")
    if mark >= 95:
        print(f"Factor:       {100-mark}")
        print("Final Mark: 100")
    elif 95 > mark >= 86:
        print("Factor:       4")
        print(f"Final Mark: {mark+4}")
    elif 86 > mark >= 56:
        print("Factor:       6")
        print(f"Final Mark: {mark+6}")
    else:
        print("Factor:          0")
        print(f"Final Mark: {mark} - Failed")
# ------------------------------------------------

# Q4(-5)
# This number can not be Mark
# Q4(97)
# Mark:        97
# Factor:       3
# Final Mark: 100
# Q4(73)
# Mark:        73
# Factor:       6
# Final Mark:  79

# ------------------------------------------------
#                   Q5
# ------------------------------------------------
def Q5( height, weight ):
    bmi = weight / height**2
    if bmi < 17:
        print("Under weight")
    elif 17 <= bmi < 25:
        print("Healthy Weight")
    elif 25 <= bmi < 30:
        print("Over Weight")
    elif 30 <= bmi < 35:
        print("Obese")
    elif 35 <= bmi < 40:
        print("Severely Obese")
    else:
        print("Morbidly Obese")
# ------------------------------------------------

# Q5(1.65,70)
# Over-weight
# Q5(1.65,60)
# Healthy Weight
# Q5(1.65,45)
# Underweight

