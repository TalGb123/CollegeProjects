def Q1(key):
      decLst = [0]*len(key)
      for i, k in enumerate(key):
            decLst[k] = i
            # print(k)
      return decLst

# print(Q1([3,2,1,0,4,13,12,11,5,14,15,10,6,7,8,9]))


def Q2(text):
      # Spiral order for 4x4 clockwise spiral
      key = [0, 1, 2, 3, 11, 12, 13, 4, 10, 15, 14, 5, 9, 8, 7, 6]

      # Pad text to be multiple of 16 characters
      while len(text) % 16 != 0:
            text += ' '

      encrypted = ''
      for block_start in range(0, len(text), 16):
            block = text[block_start:block_start + 16]
            block_chars = list(block)
            encrypted_block = ''.join([block_chars[i] for i in key])
            encrypted += encrypted_block

      return encrypted

print("londonisthebestcapital")
