from cs50 import get_int

while True:
    n = get_int("Height: ")
    if n > 0 and n < 9:
        break

count = 1
for i in range(n):
    print(' ' * (n-1),"#"*count)
    count += 1
    n -= 1