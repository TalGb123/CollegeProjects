'''1'''
def ex1():
    num1 = int(input("Enter the first number: "))
    sum = num1//100 + (num1//10)%10 + num1%10
    mult = (num1//100) * (num1//10)%10 * (num1%10)
    print(sum, mult)


'''2'''
def ex2():
    num = int(input("Enter the number: "))
    thousands = num//1000
    hundreds = (num//100)%10
    tens = (num//10)%10
    ones = num%10
    print(f"{ones}{tens}{hundreds}{thousands}")
    new = ones*1000+hundreds*100+tens*10+thousands
    print(new)


'''3'''
def ex3():
    num = int(input("Enter the number: "))
    thousands = num//1000
    hundreds = (num//100)%10
    tens = (num//10)%10
    ones = num%10
    new = tens*1000+ones*100+thousands*10+hundreds
    print(new)


'''4'''
def ex4():
    num = int(input("Enter the number: "))
    tensThousands = num//10000
    thousands = (num//1000)%10
    tens = (num//10)%10
    ones = num%10
    new = tensThousands*1000+thousands*100+tens*10+ones
    print(new)


'''5'''
def ex5():
    print("1$- %.1f₪" % (1*3.76))
    print("10$- %.1f₪" % (10*3.76))
    print("100$- %.1f₪" % (100*3.76))
    print("1000$- %.1f₪" % (1000*3.76))
    print("1$- {:.1f}₪".format(1*3.76))
    print("10$- {:.1f}₪".format(10*3.76))
    print("100$- {:.1f}₪".format(100*3.76))
    print("1000$- {:.1f}₪".format(1000*3.76))


'''6'''
def ex6():
    rate = float(input("Enter the USDNIS rate: "))
    print("1₪- %.1f$" % (1/rate))
    print("10₪- %.1f$" % (10/rate))
    print("100₪- %.1f$" % (100/rate))
    print("1000₪- %.1f$" % (1000/rate))
    print("1₪- {:.1f}$".format(1/rate))
    print("10₪- {:.1f}$".format(10/rate))
    print("100₪- {:.1f}$".format(100/rate))
    print("1000₪- {:.1f}$".format(1000/rate))

'''7'''
def ex7():
    rate = float(input("Enter the USDNIS rate: "))
    tax = float(input("Enter the tax: "))
    PriceAfterTax = float(input("Enter the price after tax in NIS: "))
    print("The price without VAT: %.1f$" % (PriceAfterTax*(tax*0.01)/rate))
    print("The price without VAT: {:.1f}$".format(PriceAfterTax*(tax*0.01)/rate))

def main():
    ex1()
    ex2()
    ex3()
    ex4()
    ex5()
    ex6()
    ex7()

if __name__ == "__main__":
    main()