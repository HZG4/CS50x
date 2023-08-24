# TODO

text = input("Text: ")

letters   = 0
words     = 1
sentences = 0

for i in text:
    if i.isalpha():
        letters = letters + 1
    elif i == " ":
        words = words + 1
    elif i == "." or i == "!" or i == "?":
        sentences = sentences + 1

L = (letters  / words) * 100
S = (sentences/ words) * 100
grade = round(0.0588 * L - 0.296 * S - 15.8)

if grade < 1:
    print("Before Grade 1")
elif grade > 16:
    print("Grade 16+")
else:
    print("Grade", grade)
