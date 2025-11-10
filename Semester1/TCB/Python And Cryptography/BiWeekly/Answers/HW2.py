def Q1(sh, sm, ss, ft):
    """
    Calculates the future time given the start time in hours, 
    minutes, and seconds, and the future time in seconds.
    Prints the result in a human-readable format.
    """
    if sh < 0 or sm < 0 or sm > 59 or ss < 0 or ss > 59 or ft <= 0:
        print("Invalid input")
        return
    now = sh*3600 + sm*60 + ss
    res = now + ft
    res_hour = res//3600
    res_min = res//60%60
    res_sec = res%60
    if res_hour > 24:
        res_day = res_hour//24
        res_hour = res_hour%24
        if res_hour != 0 and res_min == 0 and res_sec != 0:
            print(res_hour, "hours", res_sec, "seconds")
        elif res_hour != 0 and res_min == 0 and res_sec == 0:
            print(res_hour, "hours exactly")
        elif res_hour != 0 and res_min != 0 and res_sec == 0:
            print(res_hour, "hours", res_min, "minutes")
        elif res_hour == 1 or res_min == 1 or res_sec == 1:
            if res_hour == 1:
                print(res_hour, "hour", end=" ")
            else:
                print(res_hour, "hours", end=" ")
            if res_min == 1:
                print(res_min, "minute", end=" ")
            else:
                print(res_min, "minutes", end=" ")
            if res_sec == 1:
                print(res_sec, "second", end=" ")
            else:
                print(res_sec, "seconds", end=" ")
        
        else:
            print(f"{res_hour} hours {res_min} minutes {res_sec} seconds", end=" ")
        print(f"+{res_day} days", end=" ")
        
    else:
        if res_hour != 0 and res_min == 0 and res_sec != 0:
            print(res_hour, "hours", res_sec, "seconds")

        elif res_hour != 0 and res_min == 0 and res_sec == 0:
            print(res_hour, "hours exactly")
            
        elif res_hour == 1 or res_min == 1 or res_sec == 1:
            if res_hour == 1:
                print(res_hour, "hour", end=" ")
            else:
                print(res_hour, "hours", end=" ")
            if res_min == 1:
                print(res_min, "minute", end=" ")
            else:
                print(res_min, "minutes", end=" ")
            if res_sec == 1:
                print(res_sec, "second", end=" ")
            else:
                print(res_sec, "seconds", end=" ")
                
        elif res_hour != 0 and res_min != 0 and res_sec == 0:
            print(res_hour, "hours", res_min, "minutes")
            
        else:
            print(f"{res_hour} hours {res_min} minutes {res_sec} seconds", end=" ")
        
# Q1(3, 9, 59, 1)


def Q2(num):
    '''
    Separates odd and even digits, appends reversed even digits
    to odd digits, and handles negative numbers.
    '''
    odd = 0
    even = 0
    len_odd = 1
    flag = False
    if num < 0:
        num *= -1
        flag = True
    while num != 0:
        if (num%10)%2 != 0:
            odd = odd + num%10*len_odd
            len_odd *= 10
        else:
            even = even*10 + num%10
        num = num//10
    while even != 0:
        odd = odd*10 + even%10
        even//=10
    if flag:
        odd *= -1
    print(odd)

# Q2(12345678)
# Q2(-623)


def is_palindrome(num):
    # Checking if palindrome and returns true or false
    temp = num
    rev = 0
    while num != 0:
        rev = rev*10 + num%10
        num = num//10
    if temp == rev:
        return True
    return False


def Q3():
    '''
    Takes input in a loop of numbers and counts 
    the number of palindromes.
    '''
    count = 0
    num = int(input("Enter a number [end input with 0]: "))
    while num != 0:
        if is_palindrome(num):
            count+=1
        num = int(input("Enter a number [end input with 0]: "))
    return count
    
# print(Q3())

def Q4():
    '''
    Continuously takes input until a two-digit number is entered.
    Returns the number with the maximum sum of its even digits. 
    '''
    max_num = 0
    max_sum = 0
    num = int(input("Enter a number [end input with 2 digit num]: "))
    while num <= 9 or num >= 99:
        temp = 0
        temp_num = num
        while num != 0:
            if num%10%2 == 0:
                temp += num%10
            num = num//10
        if temp > max_sum:
            max_num = temp_num 
        num = int(input("Enter a number [end input with 2 digit num]: "))
    return max_num

# print(Q4())
 
def Q5(height):
    '''
    Generates a diamond pattern of numbers modulo 10, skipping 0. 
    Each row is centered with spaces to form the diamond shape.
    '''
    mid = (height + 1) // 2
    current_num = 1
    for i in range(1, mid + 1):
        spaces = ' ' * (mid - i)
        print(spaces, end="")
        for _ in range(1, 2 * i):
            if current_num % 10 == 0:
                print((current_num+1) % 10, end="")
                current_num += 1
            else:
                print(current_num % 10, end="")
            current_num += 1
        print()
    for i in range(mid - 1, 0, -1):
        spaces = ' ' * (mid - i)
        print(spaces, end="") 
        for _ in range(1, 2 * i):
            if current_num % 10 == 0:
                print((current_num+1) % 10, end="")
                current_num += 1
            else:
                print(current_num % 10, end="")
            current_num += 1
        print()

# Q5(11)



        
        
        

    