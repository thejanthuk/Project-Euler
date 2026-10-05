N = 10000
T = 50

def palindrome(a):
    aa = str(a)
    n = len(aa)
    for i in range(n // 2):
        if aa[i] != aa[n - i - 1]:
            return False
    return True

ans = 0
for a in range(N):
    t = 1
    x = a
    while t < T:
        y = int(str(x)[::-1])
        z = x + y
        if palindrome(z):
            break

        x = z
        t += 1

    if t == 50:
        ans += 1

print(ans)
