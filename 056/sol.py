N = 100

ans = 0
for a in range(1, N):
    for b in range(0, N):
        c = a ** b

        cc = str(c)
        n = len(cc)
        s = 0
        for i in range(n):
            d = ord(cc[i]) - ord('0')

            s += d

        if ans < s:
            ans = s

print(ans)
