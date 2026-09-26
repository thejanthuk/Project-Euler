N = 1000
M = 10 ** 10

ans = 0
for i in range(1, N + 1):
    ans = (ans + i ** i) % M

print(ans)
