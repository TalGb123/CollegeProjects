import random

def Q1(filename):
      def atbash_cipher(text):
            result = ''
            for char in text:
                  if char.isalpha():
                        if char.islower():
                              result += chr(ord('z') - (ord(char) - ord('a')))
                        else:
                              result += chr(ord('Z') - (ord(char) - ord('A')))
                  else:
                        result += char
            return result
      
      with open(filename, 'r', encoding='utf-8') as file:
            lines = file.readlines()
      result_lines = [atbash_cipher(line.strip()) for line in lines]
      parts = filename.split('.')
      new_filename = f"{'.'.join(parts[:-1])}_result.{parts[-1]}"
      with open(new_filename, 'w', encoding='utf-8') as file:
            for line in result_lines:
                  file.write(line + '\n')

      print(f"File saved as: {new_filename}")

# Q1('cw10.txt')

def Q2():
      letters = [chr(i) for i in range(ord('a'), ord('z') + 1)]
      shuffled = random.sample(letters, len(letters))
      d = {}
      for i in range(len(letters)):
            d[letters[i]] = shuffled[i]
      return d
      
# print(Q2())

def Q3(dict):
      newdict = {}
      for key, value in dict.items():
            newdict[value] = key
      return newdict

# print(Q3())

def Q4(filename, enc = Q2()):
      parts = filename.split('.')
      new_filename = f"{'.'.join(parts[:-1])}_result.{parts[-1]}"
      with open(filename , 'r', encoding='utf-8') as file:
            lines = file.readlines()
            with open(new_filename, 'w', encoding='utf-8') as file:
                  for line in lines:
                        newline = ''
                        for char in line:
                              if char == ' ':
                                    newline += ' '
                              else:
                                    newline += enc[char]
                        file.write(newline + '\n')
                        
# Q4('cw10.txt')

def Q5(text, num):
      table = [[] for _ in range(num)]
      for i in range(num):
            table[i] = text[i::num]
      newtext = ''
      for i in table:
            newtext += ''.join(i)
      return newtext
            
# print(Q5('hello world', 3))

def Q6(text, num):
      if num == 1 or num >= len(text):
            return text
      row_lengths = [len(text[i::num]) for i in range(num)]
      rows = []
      index = 0
      for length in row_lengths:
            rows.append(list(text[index:index+length]))
            index += length
      result = []
      i = 0
      while True:
            added = False
            for r in range(num):
                  if i < len(rows[r]):
                        result.append(rows[r][i])
                        added = True
            if not added:
                  break
            i += 1
      return ''.join(result)

# print(Q6(Q5('hello world', 3), 3))
            
      
