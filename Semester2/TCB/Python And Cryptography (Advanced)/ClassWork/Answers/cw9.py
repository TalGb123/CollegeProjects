import os
import random

def q1(path):
    """Check if the file contains only valid characters (letters, digits, spaces, punctuation)."""
    with open(path, 'r') as file:
        lines = file.readlines()
        for line in lines:
            line = line.strip()
            if line:
                for char in line:
                    if not (char.isalpha() or char.isspace() or char.isdigit() or char in ['.', ',', '!', '?']):
                        return False
        return True

def q2(path, shift):
    """Encrypt the file using Caesar cipher with the given shift."""
    base, ext = os.path.splitext(path)
    out_path = base + "-encrypt" + ext
    with open(path, 'r') as infile, open(out_path, 'w') as outfile:
        lines = infile.readlines()
        for line in lines:
            newline = ""
            for char in line:
                if char.isalpha():
                    offset = ord('A') if char.isupper() else ord('a')
                    shifted = chr((ord(char) - offset + shift) % 26 + offset)
                    newline += shifted
                else:
                    newline += char
            outfile.write(newline)

def q3(path, shift):
    """Decrypt the file using the Caesar cipher with the given shift."""
    base, ext = os.path.splitext(path)
    q2(path, shift)
    encFile = base + "-encrypt" + ext
    decFile = base + "-decrypt" + ext
    with open(encFile, 'r') as infile, open(decFile, 'w') as outfile:
        lines = infile.readlines()
        for line in lines:
            newline = ""
            for char in line:
                if char.isalpha():
                    offset = ord('A') if char.isupper() else ord('a')
                    shifted = chr((ord(char) - offset - shift) % 26 + offset)
                    newline += shifted
                else:
                    newline += char
            outfile.write(newline)

def q4(enc_path, words):
    """Brute-force decryption of a Caesar cipher and check for known words."""
    with open(enc_path, 'r') as infile:
        ciphertext = infile.read()
    for shift in range(1, 129):
        plaintext = ""
        for char in ciphertext:
            if char.isalpha():
                offset = ord('A') if char.isupper() else ord('a')
                shifted = chr((ord(char) - offset - shift) % 26 + offset)
                plaintext += shifted
            else:
                plaintext += char
        if any(word.lower() in plaintext.lower() for word in words):
            return shift, plaintext
    return -1, None

import random

def q5(folder_path):
 
    known_words = {"the", "and", "hello", "world"}
    for filename in os.listdir(folder_path):
        full_path = os.path.join(folder_path, filename)

        if os.path.isfile(full_path) and filename.endswith(".txt"): 
            shift, decrypted_text = q4(full_path, known_words)
            
            if shift != -1:
                new_name = filename.replace("-encrypt.txt", f"-decrypted.txt")
                new_path = os.path.join(folder_path, new_name)
                with open(new_path, 'w') as f:
                    f.write(decrypted_text)
            else:
                shift = random.randint(1, 25)
                q2(full_path, shift)
                new_name = filename.replace(".txt", f"-encrypt-shift{shift}.txt")
                new_path = os.path.join(folder_path, new_name)
                with open(new_path, 'w') as f:
                    f.write(open(full_path, 'r').read())

q5("ClassWork/Answers")  


