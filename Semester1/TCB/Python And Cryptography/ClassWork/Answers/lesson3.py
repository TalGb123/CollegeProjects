def Q1(num):
    return(num//10000 + (num//1000)%10 + (num//100)%10 + (num//10)%10 + num%10)
    
def Q2(num):
    return(num//1000 + (num//100)%10*1000 + (num//10)%10*100 + num%10*10)
    
    
def Q3(num, base):
    digit1 = num//100
    digit2 = (num//10)%10
    digit3 = num%10

    new1 = ((base-1)-digit1)*100
    new2 = ((base-1)-digit2)*10
    new3 = ((base-1)-digit3)*1

    return new1 + new2 + new3

def Q4(num):
    
    digit1 = num//10000
    digit2 = (num//1000)%10
    digit3 = (num//100)%10
    digit4 = (num//10)%10
    digit5 = num%10
    
    digit1 = (digit1+1)%10
    digit2 = (digit2+1)%10
    digit3 = (digit3+1)%10
    digit4 = (digit4+1)%10
    digit5 = (digit5+1)%10
    
    return digit1*10000 + digit2*1000 + digit3*100 + digit4*10 + digit5

def Q5(num):
    digit1 = num//100
    digit2 = (num//10)%10
    digit3 = num%10
    
    print(digit1*100+digit2*10+digit3)
    print(digit2*100+digit3*10+digit1)
    print(digit3*100+digit1*10+digit2)
    print(digit3*100+digit2*10+digit1)
    print(digit2*100+digit1*10+digit3)
    print(digit1*100+digit3*10+digit2)
    
def Q6(a, b, c):
    return power(add(div(1, a), div(a, div(mul(2,b), sub(c, 5)))), 0.5)
    
def add( x, y ): return x + y
def sub( x, y ): return x - y
def mul( x, y ): return x * y
def div( x, y ): return x / y
def power( x, y ): return x ** y

