A = 28433
B = 7830457
MD = 10000000000

def power(a, k):
    p = 1
    while k > 0:
        if k % 2 != 0:
            p = p * a % MD

        a = a * a % MD
        k //= 2

    return p

ans = A * power(2, B) % MD
ans = (ans + 1) % MD

print(ans)
