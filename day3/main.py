#!/usr/bin/python3
# https://adventofcode.com/2022/day/3
p = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
def rd():
    fn = 'day3/data.txt'
    with open(fn, 'r') as f:
        data = [s.replace("\n", "") for s in f.readlines()]
    return data

def pr(a):
    return p.index(a) + 1

def c(a, b):
    return p.index(list(set(a).intersection(b))[0]) + 1

def c2(r1, r2, r3):
    s = list(set(r1).intersection(r2, r3))[0]
    return p.index(s) + 1

d = rd()
ss = sum([c(r[:len(r)//2], r[len(r)//2:]) for r in d])
print(f'Answer 1: {ss}')

d2 = [*(d[i:i+3] for i in range(0, len(d), 3))]
ss = sum([c2(*a) for a in d2])
print(f'Answer 2: {ss}')