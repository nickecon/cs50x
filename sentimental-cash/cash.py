from cs50 import get_float

# ask for change owed
while True:
    change = get_float("Change owed: ")
    if change > 0:
        break

change = change * 100
qu = change / 25
di = (change - (qu * 25)) / 10
ni = (change - (qu * 25) - (di * 10)) / 5
pe = (change - (qu * 25) - (di * 10) - (ni * 5))
coins = qu + di + ni + pe
print(coins)