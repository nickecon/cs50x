from cs50 import get_int

# ask for height and get numbers 1-8
while True:
    n = get_int("Height: ")
    if n > 0 and n < 9:
        break

# run a loop to get the needed bricks
count = 1
for i in range(n):
    print(' ' * (n-1) + "#"*count)
    count += 1
    n -= 1