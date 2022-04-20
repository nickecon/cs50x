from cs50 import get_string

text = get_string("Text: ")

# count sentences
se = text.count(".") + text.count("!") + text.count("?")

# count words
w = text.count(" ") + 1

# count letters
l = 0
for i in range(len(text)):
    if text[i].isalpha():
        +l

L = round(l/w * 100)
S = (se/w * 100)
index = round(0.0588 * L - 0.296 * S - 15.8)

if index < 1:
    print("Before Grade 1")
elif index > 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")