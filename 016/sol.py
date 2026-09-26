n = 2 ** 1000

ss = str(n)

ans = 0
for s in ss:
    ans += ord(s) - ord('0')

print(ans)
