import fnmatch
import os


def find_files(pattern, root):
    result = []
    for root, dir, files in os.walk(root):
        for filename in fnmatch.filter(files, pattern):
            result.append(filename)
    return result
