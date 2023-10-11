def get_int(prompt):
    # Keep prompting user for input until a positive integer is entered
    while True:
        try:
            # Convert the user's input to an integer
            return int(input(prompt))
        except ValueError:
            # If input cannot be converted to an integer, print an error message and continue looping
            print("Invalid input, Please input a positive integer,")


# Get the height of the pyramid
height = get_int("Height: ")

# Validate the night (must be between 1 and 8 inclusive)
while height < 1 or height > 8:
    print("Height must be between 1 and 8")
    height = get_int("Height: ")

# Generate the pyramid
for i in range(1, height + 1):
    print(" " * (height - i) + "#" * i)
