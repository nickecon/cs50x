from cs50 import get_string

text = get_string("Text: ")

i = 0
letter = 0
for i in range(len(text)):
    if (text[i].isalpha()):
        letter+=1

words = text.count(" ") + 1

sentences = text.count(".") + text.count("!") + text.count("?")

L = round(letter/words * 100)
S = (sentences/words * 100)

grade = round(0.0588 * L - 0.296 * S - 15.8)

if grade > 16:
    print("Grade 16+")
elif grade < 1:
    print("Before Grade 1")
else:
    print(f"Grade {grade}")