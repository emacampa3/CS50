from csv import reader
from sys import argv

# This program is part of Harvard/edx CS50's 2021
# exercises in problem sets 6


def countmax(STR):
    # Function to search and count max occurrences
    # of STRs in a DNA sequence string
    position = 0
    maxcount = 0
    count = 0
    while (position + scope) < len(sequence):
        target = sequence[position:position + scope]
        if target == 'name':
            continue
        if target == STR:
            count += 1
            if count > maxcount:
                maxcount += 1
            position += scope
        elif target != STR:
            position += 1
            count = 0
    return maxcount


# --------- MAIN CODE -----------
# Verify user input
if len(argv) != 3:
    print("Usage: python dna.py data.csv sequence.txt")
    exit(1)


# Open databank file and create a STRs list, then bank
with open(argv[1], "r") as dna_bank:
    dna_bank = dna_bank.readline().strip().split(',')
    # Remove name field
    dna_bank.pop(0)


# Open and read sequence into a string
with open(argv[2], "r") as sequence:
    sequence = sequence.readline()


# Create a counter and a list of STRs
x = 0
STRs = []
# Look for each of the STRs consecutive occurences in the sequence
for STR in dna_bank:
    # Define a search scope the same size of the STR
    scope = len(dna_bank[x])
    # Call the STR search and count function
    STRs.append(countmax(STR))
    x += 1


# Open and read the DNA database
with open(argv[1], "r") as database:
    listdatabase = reader(database)
    next(listdatabase)
    # Reset the counter
    x = 0
    # Compare results with persons in DNA bank
    for row in listdatabase:
        while x in range(len(row) - 1):
            v = int(row[x + 1])
            if STRs[x] == v:
                x += 1
            elif STRs[x] != v:
                x = 0
                break
            # Print the match line of DNAs owner name
            if x == len(STRs):
                print(row[0])
                exit(0)
    # Case not found a match
    print('No match')