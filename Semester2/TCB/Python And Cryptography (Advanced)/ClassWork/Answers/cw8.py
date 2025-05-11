import os
import shutil


def Q1(path):
      if os.path.isdir(path):
            all_files = []
            for root, dirs, files in os.walk(path):
                  for file in files:
                        all_files.append(file)
            print(f"Number of files: {len(all_files)}")
            return all_files
      else:
            print("The path is not a directory.")
        
# print(Q1('C:/Users/User/Desktop/CollegeProjects/Semester2/TCB/Python And Cryptography (Advanced)/ClassWork/'))

def Q2(path):
      if os.path.isdir(path):
            files = [f for f in os.listdir(path) if os.path.isfile(os.path.join(path, f))]
            if "listdir.txt" in files:
                  fileCorrect = True
                  with open(os.path.join(path, "listdir.txt"), 'r') as file:
                        lines = file.readlines()
                        amount = 0
                        for line in lines:
                              amount = len(line.split())
                              for word in line.split():
                                    if word not in files:
                                          return False
                        if len(files) != amount:
                              return False
                  return True
            else:
                  with open(os.path.join(path, "listdir.txt"), 'w') as file:
                              for filetemp in files:
                                    file.write(filetemp + "\n")
                  return "file not found"
      else:
            print("The path is not a directory.")
            
                              
# print(Q2('C:/Users/User/Desktop/CollegeProjects/Semester2/TCB/Python And Cryptography (Advanced)/ClassWork/Answers/'))

def Q3(path):
      if os.path.isdir(path):
            all_files = []
            for root, dirs, files in os.walk(path):
                  for file in files:
                        all_files.append(file)
            for file in all_files:
                  temp = file.split('.')
                  if len(temp) > 2:
                        continue
                  if "_" in temp[0]:
                        temp2 = temp[0].split('_')
                        if len(temp2) > 2:
                              continue
                        if len(temp2) == 2:
                              os.rename(os.path.join(path, file), os.path.join(path, temp2[1] + '_' + temp2[0] + '.' + temp[1]))
      else:
            print("The path is not a directory.")
# print(Q3('C:/Users/User/Desktop/CollegeProjects/Semester2/TCB/Python And Cryptography (Advanced)/ClassWork/Answers/'))

def Q4(path):
      if os.path.isdir(path):
            subfolders = [f for f in os.listdir(path) if os.path.isdir(os.path.join(path, f))]
            if len(subfolders) != 2:
                  print("There are not exactly 2 subfolders.")
                  return
            folder1 = os.path.join(path, subfolders[0])
            folder2 = os.path.join(path, subfolders[1])
            files1 = [f for f in os.listdir(folder1) if os.path.isfile(os.path.join(folder1, f))]
            files2 = [f for f in os.listdir(folder2) if os.path.isfile(os.path.join(folder2, f))]
            for f in files1:
                  src = os.path.join(folder1, f)
                  dst = os.path.join(folder2, f)
                  if os.path.exists(dst):
                        dst = os.path.join(folder2, f + ".swaptemp")
                  shutil.move(src, dst)
            for f in files2:
                  src = os.path.join(folder2, f)
                  dst = os.path.join(folder1, f)
                  if os.path.exists(dst):
                        dst = os.path.join(folder1, f + ".swaptemp")
                  shutil.move(src, dst)
            for folder in [folder1, folder2]:
                  for f in os.listdir(folder):
                        if f.endswith(".swaptemp"):
                              orig = f[:-9]  
                              src = os.path.join(folder, f)
                              dst = os.path.join(folder, orig)
                              if os.path.exists(dst):
                                    os.remove(dst)
                              os.rename(src, dst)
            print("Files swapped between the two subfolders.")
      else:
            print("The path is not a directory.")
# Q4('C:/Users/User/Desktop/CollegeProjects/Semester2/TCB/Python And Cryptography (Advanced)/ClassWork/Answers/')

def Q5(path):
      if os.path.isdir(path):
            for root, dirs, files in os.walk(path):
                  if root == path:
                        continue  
                  for file in files:
                        src = os.path.join(root, file)
                        base, ext = os.path.splitext(file)
                        dest = os.path.join(path, file)
                        n = 1
                        while os.path.exists(dest):
                              dest = os.path.join(path, f"{base}({n}){ext}")
                              n += 1
                        shutil.move(src, dest)
            print("All files moved to main folder.")
      else:
            print("The path is not a directory.")
      
# Q5('C:/Users/User/Desktop/CollegeProjects/Semester2/TCB/Python And Cryptography (Advanced)/ClassWork/Answers/')