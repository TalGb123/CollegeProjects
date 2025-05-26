def Q1(key):
    decLst = [0] * len(key)
    for i, k in enumerate(key):
        decLst[k] = i
    return decLst

# print(Q1((3,2,1,0,4,13,12,11,5,14,15,10,6,7,8,9)))

def Q2(text):
    key = (12, 13, 14, 15, 11, 2, 3, 4, 10, 1, 0, 5, 9, 8, 7, 6)
    encLst = ['?'] * len(text)
    for i, k in enumerate(key):
        encLst[i] = text[k]
    return ''.join(encLst)

# print(Q2("londonisthecapit"))

def Q3(text):
    key = Q1((12, 13, 14, 15, 11, 2, 3, 4, 10, 1, 0, 5, 9, 8, 7, 6))
    decLst = ['?'] * len(text)
    for i, k in enumerate(key):
        decLst[i] = text[k]
    return ''.join(decLst)

# print(Q3("londonisthecapit"))

def Q4(text):
    key = (3, 4, 11, 12, 2, 5, 10, 13, 1, 6, 9, 14, 0, 7, 8, 15)
    encLst = ['?'] * len(text)
    for i, k in enumerate(key):
        encLst[i] = text[k]
    return ''.join(encLst)

# print(Q4("londonisthecapit"))

def Q5(text):
    key = (3, 4, 11, 12, 2, 5, 10, 13, 1, 6, 9, 14, 0, 7, 8, 15)
    decLst = ['?'] * len(text)
    for i, k in enumerate(key):
        decLst[k] = text[i]
    return ''.join(decLst)

# print(Q5("londonisthecapit"))

def Q6(filename):
    with open(filename, 'r') as infile:
        with open('.'.join(filename.split('.')[:-1]) + '-result.' + filename.split('.')[-1], 'w') as outfile:
            for line in infile:
                text = line.strip()
                if text:
                    outfile.write(Q2(text) + '\n')
                else:
                    outfile.write('\n')

# Q6('input.txt')

def Q7(filename):
    Q6(filename)
    result_filename = '.'.join(filename.split('.')[:-1]) + '-result.' + filename.split('.')[-1]
    with open(result_filename, 'r') as infile:
        with open('.'.join(filename.split('.')[:-1]) + '-result2.' + filename.split('.')[-1], 'w') as outfile:
            for line in infile:
                text = line.strip()
                if text:
                    outfile.write(Q3(text) + '\n')
                else:
                    outfile.write('\n')

# Q7('input.txt')