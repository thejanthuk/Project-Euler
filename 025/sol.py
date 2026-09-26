a = 1
b = 1

n = 2
while True:
    c = a + b

    n += 1
    if len(str(c)) >= 1000:
        print(n)
        exit(0)

    a, b = b, c
