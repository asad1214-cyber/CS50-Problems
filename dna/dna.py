import csv
import sys

def count_str_repeats(sequence, str_pattern):
    """Find the longest consecutive repeats of an STR in the DNA sequence"""
    max_repeats = 0
    str_len = len(str_pattern)
    seq_len = len(sequence)

    for i in range(seq_len):
        count = 0
        while sequence[i + count * str_len: i + (count + 1) * str_len] == str_pattern:
            count += 1
        max_repeats = max(max_repeats, count)

    return max_repeats

def main():
    # Ensure correct usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py database.csv sequence.txt")
        sys.exit(1)

    # Read database file
    with open(sys.argv[1], newline='') as csvfile:
        reader = csv.DictReader(csvfile)
        database = list(reader)

    # Read DNA sequence file
    with open(sys.argv[2], "r") as seq_file:
        dna_sequence = seq_file.read()

    # Get STR patterns from the database header
    str_patterns = list(database[0].keys())[1:]

    # Count STR occurrences in DNA sequence
    str_counts = {str_pattern: count_str_repeats(dna_sequence, str_pattern) for str_pattern in str_patterns}

    # Compare against each person in the database
    for person in database:
        if all(int(person[str_pattern]) == str_counts[str_pattern] for str_pattern in str_patterns):
            print(person["name"])
            return

    print("No match")

if __name__ == "__main__":
    main()
