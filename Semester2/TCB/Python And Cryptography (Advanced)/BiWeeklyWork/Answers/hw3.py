import os
import shutil
path = './q1.txt'

def Q1(path):
    # Validate file format and grades
    try:
        with open(path, 'r') as file:
            lines = file.readlines()
            for line in lines:
                temp = line.split()
                if len(temp) == 0:
                    continue
                if len(temp) != 2:
                    return False
                if not (temp[0].isalpha() and temp[0][0].isupper()):
                    return False
                grades = temp[1].split(',')
                for grade in grades:
                    if not grade.isdigit():
                        return False
                    if int(grade) < 0 or int(grade) > 100:
                        return False
        return True
    except (FileNotFoundError, IOError, OSError):
        print("Error: File could not be opened.")
        return False
    except Exception as e:
        print(f"Unexpected error: {e}")
        return False

# print(Q1(path))

def Q2(path, s1, s2):
    # Replace s1 with s2 in file and write to output file
    try:
        base, ext = os.path.splitext(path)
        output_path = base + "-output" + ext
        with open(path, 'r') as infile:
            with open(output_path, 'w') as outfile:
                lines = infile.readlines()
                for line in lines:
                    newline = ""
                    temp = line.split()
                    for word in temp:
                        if word == s1 or word[:-1] == s1:
                            if word[-1] == '.':
                                word = s2 + "."
                            else:
                                word = s2
                        newline += word + " "
                    newline += '\n'
                    outfile.write(newline)
        outfile.close()
        infile.close()
    except (FileNotFoundError, IOError, OSError):
        print("Error: File could not be opened.")
        return False
    except Exception as e:
        print(f"Unexpected error: {e}")
        return False

# print(Q2(path, "cat", "dog"))

def Q3(path):
    # Generate temperature report (avg, min, max) from file
    try:
        base, ext = os.path.splitext(path)
        output_path = base + "-report" + ext
        with open(path, 'r') as infile:
            with open(output_path, 'w') as outfile:
                lines = infile.readlines()
                for line in lines:
                    line = line.strip()
                    if ":" in line:
                        temp = line.split(':')
                        if len(temp) != 2:
                            if temp.isalpha():
                                outfile.write(line + " no temperature\n")
                                continue
                            elif temp.isdigit():
                                outfile.write(line + " no location\n")
                            else:
                                outfile.write(line + " unknown error\n")
                        else:
                            temperatures = temp[1].split(',')
                            try:
                                temperatures = list(map(float, temperatures))
                                mintemp = min(temperatures)
                                maxtemp = max(temperatures)
                                avgtemp = 0
                                for i in temperatures:
                                    avgtemp += i
                                avgtemp /= len(temperatures)
                                outfile.write(f"{temp[0]}: avg({avgtemp}),min({mintemp}),max({maxtemp})\n")
                            except (TypeError, ValueError):
                                outfile.write(line + " temperature error\n")
                    else:
                        outfile.write(line + " line error\n")
        infile.close()
        outfile.close()
    except (FileNotFoundError, IOError, OSError):
        print("Error: File could not be opened or written.")
        return False
    except Exception as e:
        print(f"Unexpected error: {e}")
        return False
        
# Q3(path)

def Q4(path, blackDoms, blackWords):
    # Split messages, filter by blacklist, write to send/log if emails valid or not
    try:
        base, ext = os.path.splitext(path)
        send_path = base + "-send" + ext
        log_path = base + "-log" + ext
        with open(path, 'r') as infile:
            with open(send_path, 'w') as sendfile:
                with open(log_path, 'w') as logfile:
                    lines = infile.readlines()
                    msgs = []
                    current = []
                    for line in lines:
                        if line.strip() == '#':
                            msgs.append('\n'.join(current).strip())
                            current = []
                        else:
                            current.append(line.rstrip('\n'))
                    if current:
                        msgs.append('\n'.join(current).strip())
                    msgs = [msg.split('\n') for msg in msgs]
                    for msg in msgs:
                        if any(dom in msg[0] for dom in blackDoms) or any(word in msg[1:] for word in blackWords):
                            for line in msg:
                                logfile.write(line + "\n")
                            logfile.write("#\n")
                        else:
                            for line in msg:
                                sendfile.write(line + "\n")
                            sendfile.write("#\n")
        infile.close()
        sendfile.close()
        logfile.close()
    except (FileNotFoundError, IOError, OSError):
        print("Error: File could not be opened or written.")
        return False
    except Exception as e:
        print(f"Unexpected error: {e}")
        return False

# Q4(path, {"abc.com", "next"}, {"xyz", "big"})
                    
def Q5(path):
    # Organize files in folder into subfolders by extension
    try:
        types = []
        for filename in os.listdir(path):
            filepath = os.path.join(path, filename)
            if os.path.isfile(filepath):
                base, ext = os.path.splitext(filepath)
                if ext not in types:
                    types.append(ext)
        for type in types:
            os.makedirs(f'./{type}', exist_ok=True)
        for filename in os.listdir(path):
            filepath = os.path.join(path, filename)
            if os.path.isfile(filepath):
                _, ext = os.path.splitext(filepath)
                shutil.move(filepath, os.path.join(f'./{ext}', filename))
    except (FileNotFoundError, IOError, OSError):
        print("Error: Problem accessing or moving files.")
        return False
    except Exception as e:
        print(f"Unexpected error: {e}")
        return False
    
folder = './'
# Q5(folder)