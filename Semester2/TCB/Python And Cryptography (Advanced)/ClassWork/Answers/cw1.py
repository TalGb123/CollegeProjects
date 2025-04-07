def Q1(a):
    even=[]
    odd=[]
    for i in range(0,len(a)):
        if len(str(a[i]))%2==1:
            odd.append(a[i])
        else:
            even.append(a[i])
    if len(even)!=len(odd):
        return []
    result=[]
    for i in range(0,len(even)):
        result.append(odd[i])
        result.append(even[i])
    return result

# Test cases
print(Q1([18, 93, 2, 45, 100, 1021, 147, 5])) # [2, 18, 100, 93, 147, 45, 5, 1021]
print(Q1([18, 93, 2, 45, 100, 1021, 14, 5])) # []

def Q2(str):
    newstr = str.split(' ')
    newarr = []
    for i in newstr:
        flag = 1
        wordlen_count = 0
        if not ((i.endswith('.gov.il') or i.endswith('.ac.il')) and (i[0] != '.')):
            continue
        last_part = ''
        for j in i:
            if j == '.':
                if wordlen_count < 3 and last_part != 'ac':
                    flag = 0
                    break
                last_part = ''
                wordlen_count = 0
            else:
                last_part += j
                wordlen_count += 1
        if flag == 1:
            newarr.append(i)
    return ' '.join(newarr)

# print(Q2('www.sce.ac.il gov.il il tfl.gov.uk .ac.il www.cam.ac.uk bg.ac.il bus.gov.il'))

def Q3(str):
    newstr = str.split(' ')
    mid = (len(newstr)+1) // 2
    for i in range(mid):
        for j in range(mid):
            if newstr[i] == newstr[mid+j]:
                return True
    return False

# print(Q3('London is the capital of Great is Britain'))

def Q4(str1, str2):
    arr1 = str1.split(' ')
    arr2 = str2.split(' ')
    merged = ''
    max_len = max(max(len(word) for word in arr1), max(len(word) for word in arr2))
    for length in range(1, max_len + 1):
        for word in arr1:
            if len(word) == length:
                merged += ' ' + word
        for word in arr2:
            if len(word) == length:
                merged += ' ' + word
    return merged

# print(Q4('aaa bcd abcd aaa', 'aa abcd bb ab 123 qwerty'))

def Q5(str):
    arr = str.split(' ')
    merged = ''
    for i in arr:
        flag = True
        for j in range(len(i)):
            if not flag:
                break
            for k in range(j + 1, len(i)):
                if i[j] == i[k]:
                    flag = False
                    break
        if flag:
            merged += ' ' + i
    return merged.strip()  

# print(Q5('LondOn is the capital of Great Britain'))

def Q6(numbers):
    def is_symmetric(n):
        s = str(n)
        return s == s[::-1]
    def has_unique_digits(n):
        s = str(n)
        count = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
        for digit in s:
            count[int(digit)] += 1
            if count[int(digit)] > 2:
                return False
        return True
    for num in numbers:
        if is_symmetric(num) and has_unique_digits(num):
            return num
    return 0

# print(Q6([121, 46, 39908, 1001, 144]))      
# print(Q6([12121, 46, 98389, 1001, 144]))    
# print(Q6([12121, 46, 98889, 11111, 144]))   

def Q7(numbers):
    def find_max(nested_tuple):
        max_value = 0
        for item in nested_tuple:
            if type(item) == tuple:
                max_value = max(max_value, find_max(item))
            else:
                max_value = max(max_value, item)
        return max_value
    
    return find_max(numbers)

# print(Q7(((),200,(4,23,(345,(81,700),())))))

def Q8(str):
    def add(num1, num2):
        return num1+num2
    def sub(num1, num2):
        return num1-num2
    def mul(num1, num2):
        return num1*num2
    def div(num1, num2):
        return num1//num2
    op = str[:3] 
    numbers = str[4:-1].split(',')
    num1 = int(numbers[0])
    num2 = int(numbers[1])
    if op == 'add':
        return add(num1, num2)
    elif op == 'sub':
        return sub(num1, num2)
    elif op == 'mul':
        return mul(num1, num2)
    elif op == 'div':
        return div(num1, num2)
    return 0
    
# print(Q8 ('add(23,450)') )
# print(Q8 ('mul(15,-5)') )
