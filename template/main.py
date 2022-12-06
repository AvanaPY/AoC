#!/usr/bin/python3
# https://adventofcode.com/2022/day/
def rd(day : int = 0):
    fn = f'day{day}/data.txt'
    with open(fn, 'r') as f:
        data = [s.replace("\n", "") for s in f.readlines()]
    return data

def main():
    # Fill in day in rd call
    data = rd(1)

if __name__ == '__main__':
    main()