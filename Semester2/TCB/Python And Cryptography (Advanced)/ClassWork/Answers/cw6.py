def Q1(*args):
    try:
            if len(args) == 0:
                  raise TypeError("No argument")
            if len(args) > 1:
                  raise TypeError("Above 1 argument")
            num = args[0]
            if not isinstance(num, (int, float)):
                  raise TypeError("Parameter type mismatch")
            if num < 0:
                  raise ValueError("Negative number")
            return num**0.5
    except TypeError as e:
            print(f"<class 'TypeError'> : {str(e)}")
            return 'Unable to perform sqrt operation'
    except ValueError as e:
            print(f"<class 'ValueError'> : {str(e)}")
            return 'Unable to perform sqrt operation'
      
# print(Q1())
# print(Q1(1,2,3,4))
# print(Q1(23))
# print(Q1(-34))
# print(Q1(25))

def Q2(date_str):
      try:
            if not isinstance(date_str, str):
                  raise TypeError("Parameter type mismatch")
            parts = date_str.split('/')
            if len(parts) != 3:
                  raise TypeError("Format date mismatch")
            day_str, month_str, year_str = parts
            day = int(day_str)+1
            month = int(month_str)
            year = int(year_str)
            if day > 30:
                  day = 1
                  month += 1
            if month > 12:
                  month = 1
                  year += 1
            error_found = False
            if not (1 <= day <= 31):
                  print("<class 'ValueError'> : Day Value Error")
                  error_found = True
            if not (1 <= month <= 12):
                  print("<class 'ValueError'> : Month Value Error")
                  error_found = True
            if not (1900 <= year <= 2025):
                  print("<class 'ValueError'> : Year Value Error")
                  error_found = True
            if error_found:
                  print("<class 'ValueError'> : Date Value Error")
                  raise ValueError

            date_str = f"{str(day)}/{str(month)}/{str(year)}"
            return date_str
      except TypeError as te:
                  print(f"<class 'TypeError'> : {te}")
                  print("Unable perform operation")
      except ValueError:
                  print("Unable perform operation")
            
# print( Q2((1,2,3)))
# print( Q2('16.11.2023'))
# print(Q2('106/110/2025'))
# print(Q2('02/05/2024'))

def Q3(time, station):
    stations = ['registration', 'doctor checkup', 'procedure', 'radiography', 'blood test', 'hospital discharge']
    try:
            # Check input types
            if type(time) != str or type(station) != str:
                  raise TypeError("type problem")
                  
            # Check time format
            timelst = time.split(':')
            if len(timelst) != 2:
                  raise TypeError("format is bad")
                  
            # Convert time components to integers
            hours = int(timelst[0])
            minutes = int(timelst[1])
                  
            # Validate time values
            if not (0 <= hours <= 23) or not (0 <= minutes <= 59):
                  raise ValueError("time value error")
                  
            # Check if station is valid
            if station not in stations:
                  raise ValueError("station not valid")
                  
            return (hours, minutes), station      
    except TypeError as te:
      print(f"<class 'TypeError'> : {te}")
      print("Unable perform operation")
    except ValueError as ve:
      print(f"<class 'ValueError'> : {ve}")
      print("Unable perform operation")
            
# print(Q3('12:15', 'radiography'))


def Q4():
      lst = [-1 for _ in range(10)]
      cond = True
      while cond:
            try:
                  num = int(input("number: "))
                  index = int(input("index: "))
                  if index < 0 or index >= len(lst):
                        raise IndexError("Index out of range")
                  if num < 100 or num > 999:
                        raise ValueError("Not in range")
                  lst[index] = num
                  full = True
                  for i in range(len(lst)):
                        if lst[i] == -1:
                              full = False
                              break
                  if full:
                        print("List is full")
                        cond = False
                        return lst
            except TypeError:
                  print("<class 'TypeError'> : Type Error")
                  print("Unable to perform operation")
                  cond = False
            except ValueError:
                  print("<class 'ValueError'> : Value Error")
                  print("Unable to perform operation")
                  cond = False
            except IndexError:
                  print("<class 'IndexError'> : Index Error")
                  print("Unable to perform operation")
                  cond = False
                  
# print(Q4())        


def doSet(sequence):
    try:
        if not isinstance(sequence, (list, tuple)):
            raise TypeError("Input must be a list or tuple")
        unique_numbers = []
        for num in sequence:
            if not isinstance(num, (int, float)):
                raise TypeError("All elements must be numbers")
            if 1 <= num <= 20 and num not in unique_numbers:
                unique_numbers.append(num)
        return unique_numbers
    except TypeError as te:
        print(f"<class 'TypeError'> : {str(te)}")
        return []

def inSet(group, value):
    try:
        if not isinstance(group, list):
            raise TypeError("Group must be a list")
        if not isinstance(value, (int, float)):
            raise TypeError("Value must be a number")
        return value in group
    except TypeError as te:
        print(f"<class 'TypeError'> : {str(te)}")
        return False

def notInSet(group, value):
    try:
        if not isinstance(group, list):
            raise TypeError("Group must be a list")
        if not isinstance(value, (int, float)):
            raise TypeError("Value must be a number")
        return value not in group
    except TypeError as te:
        print(f"<class 'TypeError'> : {str(te)}")
        return False

def view(group):
    try:
        if not isinstance(group, list):
            raise TypeError("Group must be a list")
        return "{" + ",".join(map(str, sorted(group))) + "}"
    except TypeError as te:
        print(f"<class 'TypeError'> : {str(te)}")
        return "{}"

def notSet(group):
    try:
        if not isinstance(group, list):
            raise TypeError("Group must be a list")
        return [num for num in range(1, 21) if num not in group]
    except TypeError as te:
        print(f"<class 'TypeError'> : {str(te)}")
        return []

def union(group1, group2):
    try:
        if not (isinstance(group1, list) and isinstance(group2, list)):
            raise TypeError("Both groups must be lists")
        return list(sorted(set(group1 + group2)))
    except TypeError as te:
        print(f"<class 'TypeError'> : {str(te)}")
        return []

def xor(group1, group2):
    try:
        if not (isinstance(group1, list) and isinstance(group2, list)):
            raise TypeError("Both groups must be lists")
        return list(sorted(set(group1) ^ set(group2)))
    except TypeError as te:
        print(f"<class 'TypeError'> : {str(te)}")
        return []
  
# print(doSet("not a sequence"))
# print(doSet([1, "2", 3]))
# print(inSet("not a list", 5))
# print(view("not a list"))
# print(union([1,2], "not a list"))
# print(xor([1,2], [3, "4"]))