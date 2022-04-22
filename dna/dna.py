import csv
import sys import argv


def main():
    # open csv file and dna sequence, read contents into mem
    # for each STR, compute the longest run of repeats in DNA
    # Compare STR against each row in CSV file

    # first row of csv file has name as first column,
    #   then str for each of remaining column
    # each remaining row corrosponds to a person

    # csv module has reader and dictreader
    # sys module gives you access to sys.argv for command-line arguments

    # once youve opened file you can read documents with nameoffile.read()

    # TODO: Check for command-line usage
    if len(argv) != 2:
        print("Usage: STR Counts, DNA sequence")
        return 1

    # TODO: Read database file into a variable
    with open((sys.argv[1]), "r") as STR:
        reader = csv.DictReader(STR)
        for row in reader:
            name = row["name"]
            AGATC = row["AGATC"]
            TTTTTTCT = row["TTTTTTCT"]
            AATG = row["AATG"]
            TCTAG = row["TCTAG"]
            GATA = row["GATA"]
            TATC = row["TATC"]
            GAAA = row["GAAA"]
            TCTG = row["TCTG"]


    # TODO: Read DNA sequence file into a variable
    DNA = open((sys.argv[2]), "r")
    #sequence = []
     #   "AGATC": 0,
      # "AATG": 0,
     #   "TCTAG": 0,
     #   "GATA": 0,
     #   "TATC": 0,
     #   "GAAA": 0,
     #   "TCTG",
    #}
    sequence = ["AGATC", "AATG", "TCTAG", "GATA", "TATC", "GAAA", "TCTG"]



    # TODO: Find longest match of each STR in DNA sequence
    count = {}
    longest_match(sequence, DNA)

    # TODO: Check database for matching profiles
    if longest_match() = STR


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
