from cs50 import get_int

# ask for change owed
while True:
    change = get_int("Change owed: ")
    if change > 0:
        break

cents = change
cents = (cents / 25)

qu = change / 25
dimes = (change - (qu * 25)) / 10
nickels
print(coins)