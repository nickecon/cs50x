import csv
from sys import argv


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
    reader = csv.DictReader(open((argv[1]), "r"))
    STR = []
    first_row = next(reader)
    for key in first_row:
        STR.append(key)
    STR.remove("name")
    for row in reader:
        for i in range(len(STR)):
            row[STR[i]] = int(row[STR[i]])

    #for row in reader:
     #   integer = int(row['AGATC'])

    # TODO: Read DNA sequence file into a variable
    with open((argv[2]), "r") as DNA:
        sequence = DNA.readlines()

    #sequence = ["AGATC", "AATG", "TCTAG", "GATA", "TATC", "GAAA", "TCTG"]



    # TODO: Find longest match of each STR in DNA sequence
    count = {}
    for i in STR:
        count[i] = longest_match(str(sequence), i)


    #print(count)

    # TODO: Check database for matching profiles
    for row in list(reader):
        del row["name"]
        if count == row:
            print(row[1])
            exit(2)
        else:
            print("No Match")
    csv_file.close()
    # save str counts in some data structure
    # for each row in the data, check if each STR count matches, if so print name
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
