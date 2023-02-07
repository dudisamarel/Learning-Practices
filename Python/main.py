import argparse
from file_searcher import find_files
from fibonacci import fibonacciPrint


parser = argparse.ArgumentParser()
parser.add_argument("file_name", help="define file name")
pattern = parser.parse_args().file_name


def main():
    # print(fibonacciPrint(20))
    files = find_files(pattern, r"C:\Users\dudi samarel\Desktop\files")
    print(files)


if __name__ == "__main__":
    main()
