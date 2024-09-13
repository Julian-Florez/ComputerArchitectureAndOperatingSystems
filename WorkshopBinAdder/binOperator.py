def AND(x,y):
    return bool(x and y)

def OR(x,y):
    return bool(x or y)

def NOT(x):
    return bool(not x)

def XOR(x,y):
    return bool((x and not y) or (not x and y))

def binAdd(a,b,c):
    s = XOR(XOR(a, b), c)
    c = OR(AND(a, b), AND(XOR(a, b), c))
    return s, c

def binSub(a,b,c):
    s = XOR(XOR(a, b), c)
    c = OR(AND(NOT(a), b), AND(XOR(NOT(a), b), c))
    return s, c

def binMul(bin1, bin2):
    maxBin = max(len(bin1), len(bin2))
    bin1 = bin1.zfill(maxBin)
    bin2 = bin2.zfill(maxBin)
    result = "0"
    for i in range(maxBin):
        if bin2[-i-1] == "1":
            shifted_bin1 = bin1 + "0" * i
            result = binOperation(result, shifted_bin1, binAdd)
    return result

def binOperation(bin1, bin2, operation):
    if operation == binMul:
        return binMul(bin1, bin2)
    c = False
    result = ""
    neg = ""
    greater = bin1
    lower = bin2
    maxBin = max(len(bin1), len(bin2))
    bin1 = bin1.zfill(maxBin)
    bin2 = bin2.zfill(maxBin)
    for i in range(maxBin):
        if bin1[i] == "1" and bin2[i] == "0":
            greater = bin1
            lower = bin2
            break
        if bin1[i] == "0" and bin2[i] == "1":
            greater = bin2
            lower = bin1
            if operation == binSub:
                neg = "-"
            break
    for i in range(maxBin):
        a = int(greater[-i-1])
        b = int(lower[-i-1])
        s, c = operation(a, b, c)
        result = str(int(s)) + result
    return neg + str(int(c)) + result

print(binOperation("01010", "101000", binAdd))
print(binOperation("11011001", "101010111", binSub))
print(binOperation("1010", "1100", binMul))