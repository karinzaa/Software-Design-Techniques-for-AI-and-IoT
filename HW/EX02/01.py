import sys

def sort_words(words):
    return sorted(words)

if __name__ == "__main__":
    words = sys.argv[1:]  # Get words from command line arguments
    sorted_words = sort_words(words)
    print(' '.join(sorted_words))
