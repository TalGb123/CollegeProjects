def Q1(num1, num2):
    if (num1+num2) % 2 == 0:
        return num1
    else:
        return num2
    
# problematic
def Q2(num):
    if num%10 == num//10000 and (num%100)//10 == (num//1000)%10:
        return True
    return False

def Q3(num1, num2, num3):
    if num3 > num2 and num3 > num1:
        if num2 > num1:
            return "ascending"
    else:
        return "not sorted"
    
def Q4(num1, num2, num3):
    if num1 > 0 and num2 > 0 and num3 > 0:
        if num1+num2 > num3 and num2+num3 > num1 and num1+num3 > num2:
            return True
    return False

def Q5(num):
    if num >= 10 and num <= 99:
        return num//10 - num%10
    elif num >= 100 and num <= 999:
        return num//100 - num%10
    elif num >= 1000 and num <= 9999:
        return num//1000 - num%10
    elif num >= 10000 and num <= 99999:
        return num//10000 - num%10
    return "input error"
    
def Q6(num1, num2):
    if num1//100 == num2//100 or num1//100 == num2//10%10 or num1//100 == num2%10:
        if num1//10%10 == num2//100 or num1//10%10 == num2//10%10 or num1//10%10 == num2%10:
            if num1%10 == num2//100 or num1%10 == num2//10%10 or num1%10 == num2%10:
                return True
    return False
    
def Q7(num):
    count = 0
    if num >= 10000 and num <= 99999:
        if num//10000 % 2 == 0:
            count+=1
        if num//1000 % 2 == 0:
            count+=1
        if num//100 % 2 == 0:
            count+=1
        if num//10 % 2 == 0:
            count+=1
        if num % 2 == 0:
            count+=1
                            
        if count == 0:
            return "no even digits"
        if count == 5:
            return "only even digits"
        else:
            return f"{count},{5-count}"

print(Q7(24342))