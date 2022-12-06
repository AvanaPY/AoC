#!/usr/bin/python3
# https://adventofcode.com/2022/day/5
def rd(day : int = 0):
    fn = f'day{day}/data.txt'
    with open(fn, 'r') as f:
        data = [s.replace("\n", "") for s in f.readlines()]
    return data

def main():
    # Fill in day in rd call
    data = rd(5)
    print(data)

if __name__ == '__main__':
    main()