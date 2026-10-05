n = 1
c = 0
while True:
    a = 1

    while len(str(a ** n)) < n:
        a += 1

    while len(str(a ** n)) == n:
        c += 1
        print(a, n, c)
        a += 1

    n += 1
