# Import
from cs50 import get_string

# Get text from input
text = get_string("Text: ")

# Count number of letters in text
num_letters = 0
for c in text:
    if c.isalpha():
        num_letters += 1

# Count the number of words in text
num_words = len(text.split())

# Count number of sentences in text
num_sentences = text.count(".") + text.count("!") + text.count("?")

# Calculate average number of letters per 100 words
L = num_letters / num_words * 100

# Calculate average number of sentences per 100 words
S = num_sentences / num_words * 100

# Calculate grade level using formula
grade_level = 0.0588 * L - 0.296 * S - 15.8

# Print grade level
if grade_level < 1:
    print("Before Grade 1")
elif grade_level >= 16:
    print("Grade 16+")
else:
    print(f"Grade {round(grade_level)}")
