
v = []

fn = 'day1/data.txt'
with open(fn, 'r') as f:
    data = [s.replace("\n", "") for s in f.readlines()]
    
    i = -1
    while i < len(data):
        s = 0
        while i < len(data):
            i += 1
            if i >= len(data) - 1 or data[i] == '':
                v.append(s)
                break
            s += int(data[i])

v = sorted(v, reverse=True)
print(f'Sum of top 3: {sum(v[:3])}\nTop: {v[0]}')