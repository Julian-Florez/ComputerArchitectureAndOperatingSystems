def seg(numlist: list, seg:int):
    a=numlist[0]
    b=numlist[1]
    c=numlist[2]
    d=numlist[3]
    if seg == 1:
        return bool(((not(b)and not(d)) or c or (b and d) or a))
    elif seg == 2:
        return bool((not(b) or (not(c)and not(d)) or (c and d)))
    elif seg == 3:
        return bool((not(c)or d or b))
    elif seg == 4:
        return bool(((not(b)and not(d)) or (not(b) and c) or (b and not(c) and d) or (c and not(d))))
    elif seg == 5:
        return bool(((not(b)and not(d)) or (c and not(d))))
    elif seg == 6:
        return bool(((not(c) and not(d)) or (b and not(c)) or (b and not(d)) or (a)))
    elif seg == 7:
        return bool(c or b or a)

    

def display(numlist: list):

    segments = [
        seg(numlist, 1),
        seg(numlist, 2),
        seg(numlist, 3),
        seg(numlist, 4),
        seg(numlist, 5),
        seg(numlist, 6),
        seg(numlist, 7)
    ]

    display_str = ""
    display_str += " _ " if segments[0] else "   "
    display_str += "\n"
    display_str += "|" if segments[5] else " "
    display_str += "_" if segments[6] else " "
    display_str += "|" if segments[1] else " "
    display_str += "\n"
    display_str += "|" if segments[4] else " "
    display_str += "_" if segments[3] else " "
    display_str += "|" if segments[2] else " "
    display_str += "\n"
    return display_str

for i in range(10):
    numlist = [int(x) for x in f"{i:04b}"]
    print(f"Number {i}:")
    print(display(numlist))
        