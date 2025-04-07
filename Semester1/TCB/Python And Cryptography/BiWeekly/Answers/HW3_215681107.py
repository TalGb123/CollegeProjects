# ------------------------------------------------
# Name: Tal Gubenko
# ID: 215681107
# ------------------------------------------------
#                   Q1
# ------------------------------------------------
def minThree(n1, n2, n3):
    # Helper function to find the minimum of two numbers
    def minTwo(a, b):
        if a < b:
            return a
        return b
    # Find the minimum of the three numbers
    return minTwo(minTwo(n1, n2), n3)
# ------------------------------------------------
# print(minThree(1,4,2))
# print(minThree(4,2,2))
# print(minThree(4,1,7))
# ------------------------------------------------
#                   Q2
# ------------------------------------------------
def arrangeDigits(num):
    def lastDigit(x):
        return x % 10  # Get the last digit
    def withOutTheLastDigit(x):
        return x // 10  # Remove the last digit
    def isEven(x):
        return x % 2 == 0  # Check if the number is even
    def addDigit(x, y):
        return x * 10 + y  # Combine digits
    def reverseNumber(x):
        reversed_num = 0
        while x > 0:
            reversed_num = reversed_num * 10 + lastDigit(x)
            x = withOutTheLastDigit(x)
        return reversed_num  # Reverse the number
    even_part = 0
    odd_part = 0
    # Separate even and odd digits
    while num > 0:
        digit = lastDigit(num)
        if isEven(digit):
            even_part = even_part * 10 + digit
        else:
            odd_part = odd_part * 10 + digit
        num = withOutTheLastDigit(num)
    # Reverse both parts to maintain original order
    even_part = reverseNumber(even_part)
    odd_part = reverseNumber(odd_part)
    # Combine odd and even parts
    combined_result = 0
    multiplier = 1
    while odd_part > 0:
        combined_result += lastDigit(odd_part) * multiplier
        odd_part = withOutTheLastDigit(odd_part)
        multiplier *= 10
    while even_part > 0:
        combined_result += lastDigit(even_part) * multiplier
        even_part = withOutTheLastDigit(even_part)
        multiplier *= 10
    return combined_result  # Return the final combined result
# ------------------------------------------------
# print(arrangeDigits(12345))
# # 24135
# print(arrangeDigits(46842))
# # 46842
# print(arrangeDigits(1375))
# # 1375
# print(arrangeDigits(13574628))
# # 46281357
# print(arrangeDigits(12547638))
# 24681573
# ------------------------------------------------
#                   Q3
# ------------------------------------------------
def printPyramid(x):
    def printChars(c, n):
        print(c, end="")  # Start with `c`
        for b in range(n, 0, -1):  # Descending numbers
            print(b, end="")
        for b in range(2, n+1):  # Ascending numbers
            print(b, end="")
        print(c)  # End with `c`
    def spacer(k):
        print(' ' * k, end="")  # Print spaces for alignment
    for i in range(1, x):
        spacer(x - i)  # Adjust alignment
        printChars('#', i)
    print('#' * (x * 2 - 1))  # Print base
# ------------------------------------------------        
# printPyramid(9)
# ------------------------------------------------
#                   Q4
# ------------------------------------------------
def sumNums(n):
    total_sum = 0  # Accumulate the sum of valid numbers
    print(f"Enter {n} triple-digit numbers:")
    for i in range(n):
        num = int(input("Number: "))  # Input a number
        mid_digit = lambda x: x // 10 % 10  # Get middle digit
        even = lambda x: x % 2 == 0  # Check if even
        if even(mid_digit(num)):  # Add if middle digit is even
            total_sum += num
    print(total_sum)  # Output the total sum
# ------------------------------------------------
# sumNums( 10 )
'''
Enter 10 Triple digits number: 
number: 123
number: 410
number: 354
number: 222
number: 978
number: 777
number: 555
number: 202
number: 111
number: 432
547
'''
# ------------------------------------------------
#                   Q5
# ------------------------------------------------
from random import randrange
import os
def doGame():
    def sumDigits(x):
        total = 0
        while x > 0:
            total += x % 10
            x //= 10
        return total
    def shiftLeft(x):
        # Find the number of digits
        num_digits = 0
        temp = x
        while temp > 0:
            num_digits += 1
            temp //= 10
        # Calculate leftmost digit and the rest
        leftmost = x // (10 ** (num_digits - 1))
        rest = x % (10 ** (num_digits - 1))
        return rest * 10 + leftmost
    def reverseNumber(x):
        reversed_num = 0
        while x > 0:
            reversed_num = reversed_num * 10 + x % 10
            x //= 10
        return reversed_num
    def sumMaxMinDigits(x):
        max_digit = 0
        min_digit = 9
        while x > 0:
            digit = x % 10
            max_digit = max(max_digit, digit)
            min_digit = min(min_digit, digit)
            x //= 10
        return max_digit + min_digit
    def clear_screen():
        os.system('cls' if os.name == 'nt' else 'clear')
    points = 0
    for i in range(5):
        print(f"Round {i + 1}")
        num = randrange(10**(2 + i), 10**(3 + i))  # Generate number with increasing digits
        print(f"The number: {num}")
        rem = input("Remember number and press Enter...")
        if rem == '' or rem:
            clear_screen()
        # Randomly choose a level
        level = randrange(1, 5)
        if level == 1:
            print("Enter the sum of all digits:")
            ans = int(input("Your answer: "))
            res = sumDigits(num)
        elif level == 2:
            print("Enter the shift left number:")
            ans = int(input("Your answer: "))
            res = shiftLeft(num)
        elif level == 3:
            print("Enter the reverse number:")
            ans = int(input("Your answer: "))
            res = reverseNumber(num)
        elif level == 4:
            print("Enter the sum of max and min digits:")
            ans = int(input("Your answer: "))
            res = sumMaxMinDigits(num)
        if ans == res:
            points += i + 1
            print("Correct!")
        else:
            points = max(0, points - (i + 1))
            print("Incorrect!")
        print(f"The correct result was: {res}")
        print(f"Your current points: {points}")
        print("-" * 20)
    print("Game over")
    print(f"You earned {points} points!")
# ------------------------------------------------
# doGame()
'''
Level 1
The number: 459
Remember number and Press enter...

The sum of all digits is: 18

Level 2
The number: 5746
Remember number and Press enter...

The shift left number is: 7465

Level 3
The number: 12156
Remember number and Press enter...

The reverse number is: 65121

Level 4
The number: 844502
Remember number and Press enter...

The reverse number is: 205448

Level 5
The number: 4068412
Remember number and Press enter...

The sum of max and min digits: 1

Game over
You win 18 points
'''
