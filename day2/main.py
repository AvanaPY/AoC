r = {
    "A":1,  # R
    "B":2,  # P
    "C":3,  # S
    "X":1,  # R
    "Y":2,  # P
    "Z":3,  # S
    1:3,
    2:1,
    3:2,
    '1':2,
    '2':3,
    '3':1
}

def e1(a, b):
    if r[a] == r[b]:
        return r[b] + 3 # c + 3 for draw
    if r[r[b]] == r[a]:
        return r[b] + 6 # c + 6 for win
    return r[b]         # c + 0 for loss

def e2(a, b):
    if b == 'X':            # loss
        return r[r[str(a)]] 
    if b == 'Y':            # draw
        return r[a] + 3
    return r[str(r[a])] + 6 # win

fn = 'day2/data.txt'
with open(fn, 'r') as f:
    d = [tuple(s.replace("\n", "").split(" ")) for s in f.readlines()]

print(f'1: {sum([e1(*a) for a in d])}')
print(f'2: {sum([e2(*a) for a in d])}')