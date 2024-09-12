def AND(x,y):
    return x and y

def OR(x,y):
    return x or y

def NOT(x):
    return not x

def XOR(x,y):
    return (x and not y) or (not x and y)

def bin2Sum(x,y):
    return int(AND(x,y)), int(XOR(x,y))

def bin4Sum(a,b,c,d):
    return int(OR(AND(OR(a,b),c),AND(d,NOT(OR(a,b)))), int(XOR(XOR(XOR(a,b),c),d)))

print(bin2Sum(0,0))
print(bin2Sum(0,1))
print(bin2Sum(1,0))
print(bin2Sum(1,1))