def Q1(st):
      return {num for num in st if num % 2 == 0}
      
# print(Q1({2,6,5,3,7,89,34}))

def Q2(str):
      words = str.split()
      unique_words = set(word.lower() for word in words)
      return ' '.join(unique_words)

# print(Q2(' London is the capital londoN cApital of the Great capitaL the London Britain capital London '))

def is_unique(number):
    str_number = str(abs(number)) 
    return len(set(str_number)) == len(str_number)

def Q31(numbers):
    return [num for num in numbers if is_unique(num)]

def Q32(numbers):
    return list(
        filter(lambda num: len(set(str(abs(num)))) == len(str(abs(num))), numbers)
    )

def Q33(numbers):
    return [num for num in numbers if len(set(str(abs(num)))) == len(str(abs(num)))]

# print(Q3([-123, 3423, -5623416, 981, 144]))

def Q4(data):
    int_set = set()
    float_set = set()
    str_set = set()
    tuple_set = set()
    for item in data:
        if isinstance(item, int):
            int_set.add(item)
        elif isinstance(item, float):
            float_set.add(item)
        elif isinstance(item, str):
            str_set.add(item)
        elif isinstance(item, tuple):
            tuple_set.add(item)
    
    result = tuple(filter(lambda x: len(x) > 0, [int_set, float_set, str_set, tuple_set]))
    return result

# print(Q4({'12', 12, 3.5, 5.67, (1, 23), 2345, 'abc'}))
# print(Q4({12, 3.5, 5.67, (1, 23), 2345}))
# print(Q4({12, (1, 23), 2345}))
# print(Q4({'12', '(1,23)', '2345'}))

def doSet(sequence):
    unique_numbers = []
    for num in sequence:
        if 1 <= num <= 20 and num not in unique_numbers:
            unique_numbers.append(num)
    return unique_numbers

def inSet(group, value):
    return value in group

def notInSet(group, value):
    return value not in group

def view(group):
    return "{" + ",".join(map(str, sorted(group))) + "}"

def notSet(group):
    return [num for num in range(1, 21) if num not in group]

def union(group1, group2):
    return list(sorted(set(group1 + group2)))

def xor(group1, group2):
    return list(sorted(set(group1) ^ set(group2)))

s1 = doSet((9, 7, 2, 3, 12, 5, 7, 9, 12, 17, 100))
# print(view(s1))
# print(inSet(s1, 3))
# print(notInSet(s1, 3))
# print(view(notSet(s1)))

s2 = doSet((2, 4, 5, 10, 14, 16, 20))
# print(view(s2)) 
# print(view(xor(notSet(s1), s2)))  
# print(view(notSet(union(s1, s2))))  



