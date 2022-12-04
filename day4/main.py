#!/usr/bin/python3
# https://adventofcode.com/2022/day/4
def rd():
    fn = 'day4/data.txt'
    with open(fn, 'r') as f:
        data = [s.replace("\n", "") for s in f.readlines()]
    return data

def c(p1, p2):
    if p1[0] == p2[0]:
        return 1
    if p2[1] < p1[0]:
        return 0
    
    if p1[0] <= p2[0] and p1[1] >= p2[1]:
        return 1
    if p2[0] <= p1[0] and p2[1] >= p1[1]:
        return 1
    return 0

def c2(p1, p2):
    if p1[1] < p2[0]:
        return 0
    if p2[1] < p1[0]:
        return 0
    return 1

d = rd()
d = [r.split(',') for r in d]
dd = []
for p1, p2 in d:
    p1, p2 = p1.split('-'), p2.split('-')
    dd.append(((int(p1[0]), int(p1[1])), (int(p2[0]), int(p2[1]))))

d = dd
s = [c(*r) for r in d]
ss = sum(s)
print(f'Answer 1: {ss}')

s2 = [c2(*r) for r in d]
ss2 = sum(s2)
print(f'Answer 2: {ss2}')