from cs50 import get_int

while True:
    n = get_int("Height: ")
    if n > 0 and n < 9:
        break

for j in range(n, n, -1):
        print(" ", end="")
for k in range(n):
        print("#" * n)

