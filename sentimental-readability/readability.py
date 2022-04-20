from cs50 import get_string

text = get_string("Text: ")

# count sentences
s = 0
for i in range(len(text)):
    if (i == '.') or (i == "!") or (i == '?'):
        +s

# count words
w = 1
for i in range(len(text)):
    if (i == ' '):
        +w

# count letters
l = 0
for i in range(len(text)):
    if ()
