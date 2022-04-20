from cs50 import get_string

text = get_string("Text: ")

# count sentences
se = 0
for i in range(len(text)):
    if (i == '.') or (i == "!") or (i == '?'):
        +se

# count words
w = 1
for i in range(len(text)):
    if (i == ' '):
        +w

# count letters
l = 0
for i in range(len(text)):
    if text.isalpha():
        +l

L = (l/w) * 100
S = (se/w) * 100
bindex = round(0.0588 * L - 0.296 * S -15.8)
index = round(bindex)

if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print("Grade" + index)