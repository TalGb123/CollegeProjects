f1 = lambda x,y: x**y if y%2==0 else x**0.5
# print(f1(4,6))

f2 = lambda x: 1 if x > 0 else 2 if x < 0 else 3
# print(f2(-2))

f3 = sum(map(lambda x: x%2!=0,(23,12,35,1,0,486,721)))
# print(f3)

f4 = tuple(map(lambda x: int(str(x)[::-1]), (123, 45, 678, 9)[::-1]))
# print(list(f4))

nums = [102, 107, 111, 116, 120, 125, 134, 143, 152, 161, 170, 201, 206, 210, 215, 224, 233, 242, 251, 260, 300,
305, 314, 323, 332, 341, 350, 404, 413, 422, 431, 440, 503, 512, 521, 530, 602, 611, 620, 701, 710, 800]
f5 = list(filter(lambda x: sum(map(int, str(x))) in (3, 8), nums))
# print(f5)

from functools import reduce
f6 = reduce(lambda a, b: a * b, filter(lambda x: x % 8 == 0, range(10, 100)))
# print(f6)

def f7(numbers):
    return reduce(lambda x, y: x and y % 2 == 0, numbers, True)
# print(f7([21, 45, 6, 17, 58])) 
# print(f7([2, 450, 634, 170, 58])) 

from operator import add
def accumulate(init, func, seq):
    res = init
    for item in seq:
        res = func(res, item)
    return res
# print(accumulate(0, add, (1, 2, 3, 4, 5)))
# print(accumulate(1, lambda x, y: x * y, (1, 2, 3, 4, 5)))
# print(accumulate(1, lambda x, y: 4 * x - y, (1, 2, 3, 4, 5)))


def mymap(func, iterable):
    return tuple(func(x) for x in iterable)
# print(tuple(map(lambda x: x*x, range(1, 5))))  
# print(mymap(lambda x: x*x, range(1, 5))) 
