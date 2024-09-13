def binaryAdd(bin1, bin2):
    carry = False
    sum = ""
    maxBin = max(len(bin1), len(bin2))
    bin1 = bin1.zfill(maxBin)
    bin2 = bin2.zfill(maxBin)
    for i in range(maxBin):
        a = int(bin1[-i-1])
        b = int(bin2[-i-1])
        xor1 = bool((a and not b) or (not a and b))
        cout1= bool(a and b)
        xor2 = bool((xor1 and not carry) or (not xor1 and carry))
        cout2 = bool(xor1 and carry)
        or1 = bool(cout1 or cout2)
        sum = str(int(xor2)) + sum
        carry = or1
    return str(int(carry)) + sum

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

print("Binary Addition: ", binaryAdd("111100", "1001"))
print("Binary Subtraction: ", binarySubtraction("111001011", "1100001"))
print("Binary Multiplication: ", binaryMultiplication("1110", "1001"))