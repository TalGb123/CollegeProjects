# Creator: Tal Gubenko, 215681107

from functools import reduce

def Q1(nums):
    def digit_sum(n):
        """Converts to int and sums all of the digits in the number."""
        return sum(int(d) for d in str(abs(n)))
    
    """
    Returns a list with all numbers that their digit sum is the lowest at the start
    and afterwards the numbers with maximal digit sum.
    """
    temp = nums.copy()
    newlist = []
    digit_sums = [digit_sum(x) for x in temp]
    min_sum = min(digit_sums)
    max_sum = max(digit_sums)
    for i, num in enumerate(temp):
        if digit_sums[i] == min_sum:
            newlist.append(num)
    for i, num in enumerate(temp):
        if digit_sums[i] == max_sum:
            newlist.append(num)
    return newlist

# print(Q1([7,-17,23,145,809,-14,93,-6,5,-377,78])) # [23, -14, 5, 809, -377]
# print(Q1([23,-5])) # [23, -5, 23, -5]

def Q2(num, stned):
    """
    Returns a sliced number based on the numbers in the string of the second parameter.
    """
    stned = stned[1:-1]
    parts = stned.split(":")
    num_str = str(abs(num))
    negflag = num < 0
    start = int(parts[0]) if parts[0] else None
    end = int(parts[1]) if len(parts) > 1 and parts[1] else None
    step = int(parts[2]) if len(parts) > 2 and parts[2] else None
    
    result = num_str[start:end:step]
    return int(result) * (-1 if negflag else 1)

# print(Q2(-1234567,'[1:-1]')) # -23456
# print(Q2(-1234567,'[3:]')) # -4567
# print(Q2(1234567,'[::3]') ) # 147
# print(Q2(-1234567,'[1:-1:2]')) # -246

def Q3a(grades):
    """
    Counts how many grades pass after applying bonus formula (grade + 10*sqrt(grade)).
    Excludes grade 199 and only counts grades that become >= 55 after bonus.
    """
    return len([passed for passed in grades if passed+10*(passed**0.5)>=55 and passed!=199])

def Q3a1(grades):
    """
    Same functionality as Q3a but implemented using reduce/filter/map.
    Counts passing grades after applying bonus formula, excluding grade 199."
    """
    return reduce(lambda lngth, _: lngth+1,
                  filter(lambda passed: passed>=55,
                         map(lambda factor: factor+10*(factor**0.5),
                             filter(lambda score: score != 199,grades))),0)

# print(Q3a([46,199,77,100,199,14]) ) # 3
# print(Q3a1([46,199,77,100,199,14]) ) # 3


def Q3b(grades,func):
    """
    Checks if all valid grades (between 55-100, excluding 199) remain valid 
    after applying the given function."
    """
    return reduce(lambda acc, grade: acc and 100>=grade>=55,
                  map(func,
                      filter(lambda grade: 100 >= grade >= 55 and grade != 199, grades)),True)

# print(Q3b([46,199,77,100,199],lambda x:x+15)) # False
# print(Q3b([46,199,77,199],lambda x:x+15)) # True
# print(Q3b([46,199,77,100,199,20],lambda x:x+15)) # False

def Q4(funcs, data):
    """
    Filters numbers where exactly one of the given functions returns True."
    """
    return (lambda f, d: tuple(filter(lambda x: sum(func(x) for func in f) == 1, d)))(funcs, data)

# print(Q4((lambda x: x>0, lambda x: x%2==0, lambda x: 9<abs(x)<100),
#          (20,-45,133,8,400,7,-300,68))) # (-45, 133, 7, -300)

marks=[('David',80),('Tali',45),('Moshe',86),('Yanir',80)]
"""Returns if the whole list's grade is passing."""
Q5a= lambda x: all(score >= 55 for _, score in x)
# print(Q5a(marks)) #False
# print(Q5a(marks[:1]+marks[2:])) #True

"""Returns all names of those who didn't pass."""
Q5b= lambda x: [name for name, score in x if score < 55]
# print(Q5b(marks)) # ['Tali']
# print(Q5b(marks+[('Ran',50)])) # ['Tali', 'Ran']

"""Returns the list given with a max factor."""
Q5c=lambda x: [(name, score+min(100-score for name,score in x)) for name, score in x]
# print(Q5c(marks)) # [('David', 94), ('Tali', 59), ('Moshe', 100), ('Yanir', 94)]
# print(Q5c(marks+[('Ran',95)])) # [('David', 85), ('Tali', 50), ('Moshe', 91), ('Yanir', 85), ('Ran', 100)]

"""Returns if there are any grade duplicates in the list."""
Q5d = lambda x: reduce(lambda acc, curr: acc or len([score for _, score in x if score == curr[1]]) > 1, x, False)
# print(Q5d (marks)) #True
# print(Q5d (marks[:-1])) #False


