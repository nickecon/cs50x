from cs50 import get_int

# ask for change owed
while True:
    change = get_int("Change owed: ")
    if change > 0:
        break

