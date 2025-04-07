def Q1a(num):
    result = 0
    count = 1
    while num != 0:
        if num%10%2 == 0:
            result = num%10 * count + result
            count *= 10
        num = num // 10
    return result

# print(Q1a(123456))

def f11(num):
    return num%2 == 0

def f12(num):
    return num%10

def f13(num):
    return num//10

def f14(num):
    return num*10

def f15(num, digit):
    return num*10 + digit

def f16(num):
    new = num%10
    num //= 10
    while num != 0:
        new = new*10 + num%10
        num //= 10
    return new

def Q1b(num):
    print("number is even" if f11(num) else "number is odd")
    print("last digit is", f12(num))
    print("number without last digit is", f13(num))
    print("number with last digit moved to the front is", f14(num))
    print("number with 7 added to the end is", f15(num, 7))
    print("number with digits reversed is", f16(num))

# Q1b(123456)   

def Q1c(num):
    # a = lambda num: num%2 == 0
    # b = lambda num: num%10
    # c = lambda num: num//10
    # d = lambda num: num*10
    # e = lambda num, digit: num*10 + digit
    # f = lambda num: (lambda n, r: (lambda f: f(f, n, r))(lambda self, n, r: r if n == 0 else self(self, n // 10, r * 10 + n % 10)))(num, 0)
    def f11(num):
        return num%2 == 0

    def f12(num):
        return num%10

    def f13(num):
        return num//10

    def f14(num):
        return num*10

    def f15(num, digit):
        return num*10 + digit

    def f16(num):
        new = num%10
        num //= 10
        while num != 0:
            new = new*10 + num%10
            num //= 10
        return new
    
    print("number is even" if f11(num) else "number is odd")
    print("last digit is", f12(num))
    print("number without last digit is", f13(num))
    print("number with last digit moved to the front is", f14(num))
    print("number with 7 added to the end is", f15(num, 7))
    print("number with digits reversed is", f16(num))

# Q1c(123456)

def Q2(num):
    temp = num
    odd_sum = 0
    even_sum = 0
    while temp != 0:
        if temp%10%2 == 0:
            even_sum += temp%10
        else:
            odd_sum += temp%10
        temp //= 10
    
    if (odd_sum+even_sum)%2 == 0:
        return even_sum
    return odd_sum

# print(Q2(12345))
# print(Q2(12346))

def length(num):
    count = 0
    while num != 0:
        count += 1
        num //= 10
    return count

def multf(num1, num2):
    return num1*num2

def sumf(num1, num2):
    return num1+num2

def subf(num1, num2):
    return num1-num2

def reverse_digits(num):
    reversed_num = 0
    while num > 0:
        reversed_num = reversed_num * 10 + num % 10
        num //= 10
    return reversed_num

def Q3(num1, num2):
    mult = multf(num1, num2)
    sum = sumf(num1, num2)
    sub = subf(num1, num2)
    total = mult
    if sub < 0:
        return -1
    sum = reverse_digits(sum)
    sub = reverse_digits(sub)
    while sum > 0:
        total = total * 10 + sum % 10
        sum //= 10
    while sub > 0:
        total = total * 10 + sub % 10
        sub //= 10
    return total

# print(Q3(5, 4))
# print(Q3(7, 5))
# print(Q3(20, 3))
# print(Q3(9, 6))
# print(Q3(2, 3))

def Q4(num1, num2, num3):
    a = lambda num: num-1
    b = lambda num: num//100 + num//10%10 + num%10
    c = lambda num: num >= 0
    d = lambda num: (num//10 + num%10)%2 == 0
    e = lambda num: num//1000 == num%10 and num//100%10 == num//10%10
    f = lambda num: num%10*10 + num//10
    g = lambda num1, num2: num1-num2
    h = lambda num1, num2: num1**num2
    i = lambda num1, num2, num3: (num1+num2+num3)>=100 and (num1+num2+num3)<=999

    print("a:", a(num1))
    print("b:", b(num2))
    print("c:", c(num3))
    print("d:", d(num1))
    print("e:", e(num2))
    print("f:", f(num3))
    print("g:", g(num1, num2))
    print("h:", h(num1, num2))
    print("i:", i(num1, num2, num3))

# Q4(5, 2, 100)





        