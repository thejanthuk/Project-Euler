import math

ss = str(math.factorial(100))

ans = 0
for s in ss:
    ans += ord(s) - ord('0')

print(ans)
