from cs50 import get_float

# ask for change owed
while True:
    change = get_float("Change owed: ")
    if change > 0:
        break

# calculate change and return needed number
change = change * 100
qu = int(change / 25)
di = int((change - (qu * 25)) / 10)
ni = int((change - (qu * 25) - (di * 10)) / 5)
pe = int((change - (qu * 25) - (di * 10) - (ni * 5)))
coins = qu + di + ni + pe
print(coins)