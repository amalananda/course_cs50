from cs50 import get_float

# Prompt the user for amount of change owed until non-negative value provided
while True:
    change_owed = get_float("Change Owed: ")
    if change_owed >= 0:
        break

# Convert the change owed to cents (multiply by 100 and round to the nearest integer)
change_owed_cents = round(change_owed * 100)

# Initialize number of coins to 0
num_coins = 0

# Calculate number of coins needed
while change_owed_cents > 0:
    if change_owed_cents >= 25:
        change_owed_cents -= 25
        num_coins += 1
    elif change_owed_cents >= 10:
        change_owed_cents -= 10
        num_coins += 1
    elif change_owed_cents >= 5:
        change_owed_cents -= 5
        num_coins += 1
    else:
        change_owed_cents -= 1
        num_coins += 1

# Print number of coins
print(num_coins)
