import sys

def sort_words(words):
    return sorted(words)

if __name__ == "__main__":
    words = sys.argv[1:]
    sorted_words = sort_words(words)
    print(' '.join(sorted_words))
