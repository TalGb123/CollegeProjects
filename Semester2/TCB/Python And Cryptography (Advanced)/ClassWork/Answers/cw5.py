def Q1(num):
      dict = {}
      for i in range(1, num + 1):
          dict[i] = i 
      return dict

# print(Q1(5))

def Q2(lst):
    valid_types = (int, float, str, bool, tuple, range)
    result = {}
    for item in lst:
        if type(item) not in valid_types:
            continue
        result[item] = item
    return result

# print(Q2([1, 2, 3, 4, 5, {1, 2, 3}]))  
# print(Q2([1, "hello", 3.14, True, (1,2), [1,2], {1,2}])) 

def Q3(dict1, dict2): 
    dict3 = {}
    for i in range(1, len(dict1)+1):
        dict3[i] = dict1.get(i) + dict2.get(i)
    return dict3

# print(Q3({1: 1, 2: 2, 3: 3}, {1: 4, 2: 5, 3: 6}))

def Q4(students_dict):
    lst = []
    for _, data in students_dict.items():
        name = data.get('name')
        sum = 0
        count = 0
        for key, value in data.items():
            if key != 'name':
                sum += value
                count += 1
        if count > 0:
            avg = sum // count
        else:
            avg = 0
        lst.append((name, avg))
    return lst

# print(Q4({'Student1':{'name':'David','Python':80,'Math':90,'Network':56},
# 'Student2':{'name':'Tali','Math':67,'Network':86},
# 'Student3':{'name':'Moshe'}}))

def has_digit(number, digit):
    return str(digit) in str(number)

def Q5(lst):
    dict = {}
    for i in range(10):
        temp = []
        for j in lst:
            if has_digit(j, i):
                temp.append(j)
        if len(temp) > 0:
            dict[i] = temp
    return dict

# print(Q5([1213,3421,12,34,400,1988,204]))