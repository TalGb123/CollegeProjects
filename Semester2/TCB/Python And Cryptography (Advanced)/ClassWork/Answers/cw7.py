def Q1(fileName):
      lineCount = 0
      sentenceCount = 0
      wordCount = 0
      characterCount = 0
      with open(fileName, 'r') as file:
            for line in file:
                  aline = line.split()
                  lineCount += 1
                  wordCount += len(aline)
                  for word in aline:
                        if word.endswith('.') or word.endswith('!') or word.endswith('?'):
                              sentenceCount += 1
                        characterCount += len(word)
      print(f"Number of lines: {lineCount}")
      print(f"Number of sentences: {sentenceCount}")
      print(f"Number of words: {wordCount}")
      print(f"Number of characters: {characterCount+wordCount-1}")
      
      file.close()
      
# Q1('q1.txt')

def Q2(fileName):
      longest_word = ""
      with open(fileName, 'r') as file:
            for line in file:
                  aline = line.split()
                  for word in aline:
                        if len(word) > len(longest_word):
                              longest_word = word
      print(f"The longest word is {longest_word}")
      
# Q2('q1.txt')

def Q3(fileName):
      with open(fileName, 'r') as file:
            for line in file:
                  aline = line.split()
                  for word in aline:   
                        if word[:2].isdigit() and (word[2] == '/' or word[2] == '-') and word[3:5].isdigit() and (word[2] == '/' or word[2] == '-') and word[6:].isdigit():
                              day = word[:2]
                              month = word[3:5]
                              year = word[6:]
                              if len(day) > 2 or len(month) > 2 or len(year) > 4:
                                    continue
                              if int(day) > 31 or int(month) > 12 or int(year) < 1900:
                                    continue
                              if int(day) == 0 or int(month) == 0 or int(year) == 0:
                                    continue
                              if word[2] == '/':
                                    print(f"Date: {day}/{month}/{year}")
                              else:
                                    print(f"Date: {day}-{month}-{year}")
                        elif word[:2].isdigit() and (word[2] == '/' or word[2] == '-') and word[3:].isdigit():
                              day = word[:2]
                              month = word[3:]
                              if len(day) > 2 or len(month) > 2:
                                    continue
                              if int(day) > 31 or int(month) < 1 or int(month) > 12:
                                    continue
                              if int(day) == 0 or int(month) == 0:
                                    continue
                              if word[2] == '/':
                                    print(f"Date: {day}/{month}")
                              else:
                                    print(f"Date: {day}-{month}")
                        elif len(word) == 4 and word.isdigit():
                              year = word
                              if int(year) < 1900:
                                    continue
                              print(f"Date: {year}")        
      file.close()
      
# Q3('q1.txt')

def Q4(fileName):
      with open(fileName, 'r') as file:
            
            firstWordCap = False
            for line in file:
                  aline = line.split()
                  sentCount = 0
                  for word in aline:
                        if word.endswith('.') or word.endswith('?'):
                              sentCount += 1
                              firstWordCap = True
                              continue
                        elif firstWordCap:
                              if word[0].isupper():
                                    firstWordCap = False
                              else:
                                    return False
                  if sentCount == 0:
                        return False
            return True
                              
      file.close()
      
# print(Q4('q1.txt'))

def Q5(fileName):
      import os
      base, _ = os.path.splitext(fileName)
      outFileName = base + ".out"
      with open(fileName, 'r') as infile, open(outFileName, 'w') as outfile:
            buffer = []
            for line in infile:
                  words = line.strip().split()
                  for word in words:
                        buffer.append(word)
                        if word.endswith('.') or word.endswith('?'):
                              punct = word[-1]
                              buffer[-1] = buffer[-1][:-1]  
                              reversed_sentence = buffer[::-1]
                              reversed_sentence[-1] += punct  
                              outfile.write(' '.join(reversed_sentence) + '\n')
                              buffer = []
      if buffer:
            outfile.write(' '.join(buffer) + '\n')
      
      infile.close()
      outfile.close()
            
# Q5('q1.txt')

def Q6(fileName):
      import os
      base, _ = os.path.splitext(fileName)
      outFileName = base + ".out"
      with open(fileName, 'r') as infile, open(outFileName, 'w') as outfile:
            for line in infile:
                  words = line.strip().split()
                  cleaned_words = []
                  for word in words:
            
                        new_word = ''.join([char for char in word if not char.isdigit()])
                        if new_word:
                              cleaned_words.append(new_word)
                  outfile.write(' '.join(cleaned_words) + '\n')
      infile.close()
      outfile.close()
            
Q6('q1.txt')
      