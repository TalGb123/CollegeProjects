def Q1(input_str):
    count_list = [0, 0, 0, 0, 0]
    for i in range(len(input_str)):
        if input_str[i] == ' ':
            count_list[0] += 1
        elif input_str[i].islower():
            count_list[1] += 1
        elif input_str[i].isupper():
            count_list[2] += 1
        elif input_str[i].isdigit():
            count_list[3] += 1
        else:
            count_list[4] += 1
    return count_list  
    
# print(Q1( 'AHwer werwre 1234 sdfas #Rte$' ))

def Q2(input_str):
    new_str = ""
    first_word_index = 0
    for i in range(len(input_str) + 1):
        if i == len(input_str) or input_str[i] == ' ':
            word = input_str[first_word_index:i]
            if word.islower():
                mid_index = (len(word) + 1) // 2
                new_str += word[:mid_index] + ' '
            else:
                mid_index = (len(word) + 1) // 2
                new_str += word[mid_index:] + ' '
            first_word_index = i + 1
    return new_str.strip()

# print(Q2('LondoN IS the CAPITAL oF GreaT britain'))

def Q3(input_str1, input_str2):
    count = 0
    input_str1 = input_str1.split()
    reversed_input_str2 = []
    for s in input_str2:
        reversed_input_str2.append(s[::-1])
    for i in range(len(input_str1)):
        for j in range(len(input_str2)):
            if input_str1[i] == input_str2[j]:
                count += 1
    return count
    
# print(Q3( 'abc 1234 abcd qwerty', 'aaa cba ytrewq 1234 qaz' ))

def Q4(input_str1, input_str2):
    input_str1 = input_str1.split()
    input_str2 = input_str2.split()
    input_str1.sort()
    input_str2.sort()
    merged_list = input_str1 + input_str2
    return merged_list

# print(Q4( 'aaa bcd abcd aaa', 'aa abcd bb ab 123 qwerty' ))

def Q5(input_str):
    input_str = input_str.split()
    for i in range(len(input_str)):
        temp = ''
        flag = False
        for j in range(len(input_str[i])):
            for k in range(len(temp)):
                if input_str[i][j] == temp[k]:
                    flag = True
                    break
            if not flag:
                temp += input_str[i][j]
            else:
                flag = False
        print(temp, end=' ')
        
# Q5( 'LondoN IS the CAPITAL oF GreaT britain' )
            