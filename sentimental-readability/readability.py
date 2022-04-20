from cs50 import get_string

# input text
text = get_string("Text: ")

# count sentences
se = text.count(".") + text.count("!") + text.count("?")

# count words
w = text.count(" ") + 1

# count letters
i = 0
l = 0
for i in range(len(text)):
    if text[i].isalpha():
        l += 1

# index formula
L = round(l/w * 100)
S = (se/w * 100)
index = round(0.0588 * L - 0.296 * S - 15.8)

# print proper Grade
if index > 16:
    print("Grade 16+")
elif index < 1:
    print("Before Grade 1")
else:
    print(f"Grade {index}")