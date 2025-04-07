from functools import reduce

def countPast(lst):
      return len(list(filter(lambda x: x >= 55 and x != 199, lst))) 
# print(countPast([46,199,77,100,199,20,55,54]))

def reverse2Digits(lst):
      return list(map(lambda x: int(str(abs(x))[::-1]) * (-1 if x < 0 else 1), 
            filter(lambda x: abs(x) >= 10 and abs(x) <= 99, lst)))
# print(reverse2Digits([2,-12,56,183,-23,78,-3]))

def retEvens3Times(tpl):
      return tuple(x for x in tuple(filter(lambda x: x % 2 == 0, tpl)) for _ in range(3))
# print( retEvens3Times((17,24,103,400,5,68)))

def convertStrToIntList(str):
      return list(map(int, filter(lambda x: x.isdigit(), str.replace(',', ' ').split())))
# print(convertStrToIntList('34 123, 145 12 12.4,456a, 23.5'))

def retClearText(str):
      return ' '.join([word.lower() for word in str.split() if word.isalpha()])
# print(retClearText ('LondON 3 is the 125 capitaL of - Great Britain'))

def getRound(lst):
      return [round(x, i+1) for i, x in enumerate(lst)]
# print(getRound([2.345,3.3456,1.456789,140.23476,16.489765]))

def doPower(tpl):
       return tuple(x[0]**(x[1] if x[1] >= 0 else 1/abs(x[1])) for x in tpl if not (x[0] < 0 and x[1] < 0))
# print(doPower(((2,3),(4,-2),(-5,3),(-4,-2))))

