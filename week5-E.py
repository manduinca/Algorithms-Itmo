with open('input.txt', 'r') as input:
    n = int(input.readline())
with open('output.txt', 'w') as output:
    if n % 2 == 0:
        output.write(str(n * n // 4))
    else:
        output.write(str(n // 2 * (n // 2 + 1)))
