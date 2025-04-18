# Checks if any value in the dictionary matches any key
def Q1(dict):
      for key, _ in dict.items():
            for _, val in dict.items():
                  if key == val:
                        return True
      return False

# print("Q1")
# print("True-",Q1({1:2, 3:'abc', 5:1}))
# print("False-",Q1({1:2, 3:'abc', 5:21}))


# Groups numbers by their digit length and tracks repetitions with '#count' suffix
def Q2(nums):
      dict = {}
      for i in nums:
            numlen = len(str(abs(i)))
            if numlen not in dict:
                  dict[numlen] = set()    
            found_str = None
            count = 2
            found = False
            for j in dict[numlen]:
                  if isinstance(j, str):
                        count = int(j.split('#')[1]) + 1
                        found_str = j
                        found = True
                        break
            if found:
                  dict[numlen].remove(found_str)
                  dict[numlen].add(str(i) + '#' + str(count))
            elif i in dict[numlen]:
                  dict[numlen].remove(i)
                  dict[numlen].add(str(i) + '#2')
            else:
                  dict[numlen].add(i)
      return dict

# print("\nQ2")
# print("{3: {210, '123#4'}, 2: {'17#2', 34, -14}, 1: {'-5#3'}, 4: {-1024}}")
# print(Q2((123,34,210,123,-5,17,-5,-14,123,-1024,17,123,-5)))
# print("{1: {-5, 4, '5#2'}, 4: {-1024}}")
# print(Q2((-5,5,-1024,5,4)))


# Swaps dict keys/values if no invalid types (dict,list,set) found, otherwise returns set of valid values
def Q3(dct):
      badtypes = [dict, list, set]
      lst = []
      for key, value in dct.items():
            if type(value) in badtypes:
                  lst.append(value) 
            if type(key) in badtypes:
                  lst.append(key)
      if not lst:
            return {v: k for k, v in dct.items()}
      result = set()
      for key, value in dct.items():
            if type(key) and type(value) not in badtypes:
                  result.add(value)
      return result
                   
# print("\nQ3")
# print("{2: 1, 4: 3, 6: 5}")
# print(Q3({1:2, 3:4, 5:6}))
# print("{'abc': (1, 2, 3), 18: 'qwerty', 'xyz': '12'}")
# print(Q3({(1,2,3):'abc', 'qwerty':18, '12':'xyz'}))
# print("{18, (1, 2, 4), 'abc'}")
# print(Q3({1: [1, 2, 3], 2: 'abc', 3: (1, 2, 4), 4: {3: 4, 5: 6}, 3.5: 18}))


# Counts word occurrences in a string, ignoring stopwords and numbers
def Q4(str, st):
      strlist = str.split(' ')
      dict = {}
      for word in strlist:
            if word.lower() not in st:
                  try: 
                        word = int(word)
                  except:
                        if word.lower() not in dict:
                              dict[word.lower()] = 1
                        else:
                              dict[word.lower()] = dict[word.lower()]+1
      return dict             
      
# print("\nQ4")
# print("{'cat': 2, 'very': 1, 'fat': 1}")
# print(Q4('My cat is 10 and it is a very fat Cat', {'is', 'it', 'a', 'the', 'my', 'and'}))


# Counts valid IP addresses grouped by first 3 octets with last octet as 'x'
def Q5(str):
      def validate_ip_parts(parts):
            try:
                  return all(0 <= int(p) <= 255 for p in parts[:3])
            except:
                  return False
      
      iplist = str.split(' ')
      lst = [ip.split('.') for ip in iplist if len(ip.split('.')) == 4]
      ip_keys = list(map(lambda parts: f"{parts[0]}.{parts[1]}.{parts[2]}.x", 
                  filter(validate_ip_parts, lst)))
      return {ip: ip_keys.count(ip) for ip in set(ip_keys)} 

# print("\nQ5")
# print("{'192.168.15.x': 2, '217.145.1.x': 1}")
# print(Q5 ('192.168.15.3 192.168.15.1 19.133.256.5 217.145.x.x 192.24.5 217.145.1.8'))
# # ------------------------------------------------

# '''
# Q1
# True- True
# False- False

# Q2
# {3: {210, '123#4'}, 2: {'17#2', 34, -14}, 1: {'-5#3'}, 4: {-1024}}
# {3: {210, '123#4'}, 2: {34, -14, '17#2'}, 1: {'-5#3'}, 4: {-1024}}
# {1: {-5, 4, '5#2'}, 4: {-1024}}
# {1: {-5, 4, '5#2'}, 4: {-1024}}

# Q3
# {2: 1, 4: 3, 6: 5}
# {2: 1, 4: 3, 6: 5}
# {'abc': (1, 2, 3), 18: 'qwerty', 'xyz': '12'}
# {'abc': (1, 2, 3), 18: 'qwerty', 'xyz': '12'}
# {18, (1, 2, 4), 'abc'}
# {18, (1, 2, 4), 'abc'}

# Q4
# {'cat': 2, 'very': 1, 'fat': 1}
# {'cat': 2, 'very': 1, 'fat': 1}

# Q5
# {'192.168.15.x': 2, '217.145.1.x': 1}
# {'217.145.1.x': 1, '192.168.15.x': 2}

# '''
