def Q1(nums):
    for i in range(len(nums)):
        if (i+1)%3 == 0:
            first_dig = nums[i-1]
            while first_dig > 9:
                first_dig //= 10
            nums[i] = first_dig*10 + nums[i]%10
    return nums

# print(Q1( [123, 745, 43, 786, 1900, 346, 7778, 3454, 54, 67 ] ))
        
def Q2(nums):
    i = 0
    while i < len(nums):
        temp = nums[i]
        even_num = 0
        odd_num = 0
        even_count = 0
        odd_count = 0
        even_multiplier = 1
        odd_multiplier = 1

        while temp > 0:
            digit = temp % 10
            if digit % 2 == 0:
                even_num += digit * even_multiplier
                even_multiplier *= 10
                even_count += 1
            else:
                odd_num += digit * odd_multiplier
                odd_multiplier *= 10
                odd_count += 1
            temp //= 10

        if even_count > odd_count:
            nums[i] = even_num
            i += 1
        elif odd_count > even_count:
            nums[i] = odd_num
            i += 1
        else:
            nums.pop(i)

    return nums

# print(Q2([132, 6789, 5437, 26, 765, 12586]))

def Q3(nums1, nums2):
    nums1_digits = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    nums2_digits = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    
    for i in range(len(nums1)):
        temp = nums1[i]
        if temp == 0:
            nums1_digits[0] += 1
        while temp > 0:
            digit = temp % 10
            nums1_digits[digit] += 1
            temp //= 10
    for i in range(len(nums2)):
        temp = nums2[i]
        if temp == 0:
            nums2_digits[0] += 1
        while temp > 0:
            digit = temp % 10
            nums2_digits[digit] += 1
            temp //= 10
    if nums1_digits == nums2_digits:
        return True
    return False

# print(Q3( [ 258, 10,86, 0, 755 ], [ 6550127, 5088 ] ))
# print(Q3( [ 258, 1, 86, 75, 54 ], [ 655127, 588 ] ))

def Q4(nums):
    new_list = []
    i = 0
    while len(nums) != len(new_list):
        for j in range(len(nums)):
            temp = nums[j]
            while temp > 9:
                temp //= 10
            if temp == i:
                new_list.append(nums[j])
        i += 1
    return new_list

# print(Q4( [ 854,8000,12, 1, 6, 3, 912, 345, 54, 65 ] ))

def Q5(nums):
    count_list = []
    new_list = []
    for _ in range(len(nums)):
        count_list.append(0)
    for i in range(len(nums)):
        temp = nums[i]
        while temp > 0:
            if temp%10%2 == 0:
                count_list[i] += 1
            temp //= 10
    for i in range(len(nums)):
        for j in range(len(nums)):
            if count_list[j] == i:
                new_list.append(nums[j])
    return new_list
    

# print(Q5( [ 124, 29, 331579, 41, 5, 6671, 6280, 81694 ] ))

def Q6(nums, n):
    count = 0
    new_tuple = ()
    for i in range(len(nums)):
        temp = nums[i]
        sum = 0
        while temp > 0:
            sum += temp % 10
            temp //= 10
        if sum == n:
            count += 1
            new_tuple += (nums[i],)
    if count == 0:
        return 'not found'
    if count == 1:
        return new_tuple[0]
    return new_tuple

# print( Q6( [ 64, 127, 331, 4114, 17111, 6671, 3124 ], 10 ))
# print(Q6( [ 647, 127, 331, 4164, 17111, 6671, 8124 ], 10 ))
# print(Q6( [ 647, 627, 331, 4164, 17111, 6671, 8124 ], 10 ))

