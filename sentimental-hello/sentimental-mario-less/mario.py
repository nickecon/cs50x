from cs50 import get_int

while True:
    n = get_int("Height: ")
    if n > 0 and n < 9:
        break

for i in range(n):
    for j in range(0, n,):
        print(" ", end="")
    for k in range(n):
        print("#", end="")

