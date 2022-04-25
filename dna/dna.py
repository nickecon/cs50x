import csv
from sys import argv
import sys

def main():
    """
    open csv file and dna sequence, read contents into mem
    for each STR, compute the longest run of repeats in DNA
    Compare STR against each row in CSV file

    first row of csv file has name as first column,
    then str for each of remaining column
    each remaining row corrosponds to a person

    csv module has reader and dictreader
    sys module gives you access to sys.argv for command-line arguments

    once youve opened file you can read documents with nameoffile.read()
    """

    # TODO: Check for command-line usage
    if len(argv) != 3:
        print("Usage: python dna.py, STR Counts.csv, DNA sequence.txt")
        exit(1)

    # TODO: Read database file into a variable
    csv_file = open((argv[1]), "r")
    reader = csv.DictReader(csv_file)
    STR = []
    first_row = next(reader)
    for key in first_row:
        STR.append(key)
    STR.remove("name")

    # TODO: Read DNA sequence file into a variable
    txt_file = open ((argv[2]), "r")
    sequence = txt_file.read()

    # TODO: Find longest match of each STR in DNA sequence
    matches = {}
    for i in range(len(STR)):
        longest_run = longest_match(sequence, STR[i])
        matches[STR[i]] = longest_run

    # TODO: Check database for matching profiles
    for row in reader:
        for i in range(len(STR)):
            if int(row[STR[i]]) == matches[STR[i]]:
                bool = True
            else:
                bool = False
    if bool:
        print(row["name"])
    else:
        print("No Match")
    return

def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
