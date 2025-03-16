from cs50 import get_int

while True:
    try:
        height = get_int("Height: ")
        if 1 <= height <= 8:
            break
    except ValueError:
        pass

for i in range(1, height + 1):  # Start from 1 to match Mario-style levels
    print(" " * (height - i), end="")  # Left spaces
    print("#" * i, end="  ")  # Left side of the pyramid with gap
    print("#" * i)  # Right side of the pyramid
