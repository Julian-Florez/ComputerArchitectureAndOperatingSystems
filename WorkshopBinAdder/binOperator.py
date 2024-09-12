import time

def binaryAdd(bin1, bin2):
    carry = 0
    result = ""
    i = len(bin1) - 1
    j = len(bin2) - 1
    
    while i >= 0 or j >= 0 or carry:
        if i >= 0:
            carry += int(bin1[i])
            i -= 1
        if j >= 0:
            carry += int(bin2[j])
            j -= 1
        result = str(carry % 2) + result
        carry //= 2
    
    return result

def binarySubtraction(bin1, bin2):
    carry = 0
    result = ""
    i = len(bin1) - 1
    j = len(bin2) - 1
    
    while i >= 0 or j >= 0 or carry:
        if i >= 0:
            carry += int(bin1[i])
            i -= 1
        if j >= 0:
            carry -= int(bin2[j])
            j -= 1
        result = str(carry % 2) + result
        carry //= 2
    
    return result

def binaryMultiplication(bin1, bin2):
    result = "0"
    for i in range(len(bin2)-1, -1, -1):
        if bin2[i] == "1":
            result = binaryAdd(result, bin1 + "0"*(len(bin2)-1-i))
    
    return result

print("Binary Addition: ", binaryAdd("1110", "1001"))
print("Binary Subtraction: ", binarySubtraction("111001011", "1100001"))
print("Binary Multiplication: ", binaryMultiplication("1110", "1001"))