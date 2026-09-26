N = 100

ss = set()

for a in range(2, N + 1):
    for b in range(2, N + 1):
        ss.add(a ** b)

print(len(ss))
