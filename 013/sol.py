a = 0
with open("numbers.txt") as ss:
    for s in ss:
        a += int(s)

ss = str(a)

print(ss[:10])
