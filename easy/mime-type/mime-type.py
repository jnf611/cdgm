import sys
import math

n = int(input())  # Number of elements which make up the association table.
q = int(input())  # Number Q of file names to be analyzed.

mime_type = {None : "UNKNOWN"}
for i in range(n):
    # ext: file extension
    # mt: MIME type.
    ext, mt = input().split()
    if ext.lower() not in mime_type.keys():
        mime_type[ext.lower()] = mt

for i in range(q):
    filename = input()  # One file name per line.
    print("filename:" + filename, file=sys.stderr)

    index = filename.rfind(".")
    ext = None if index == -1 else filename[index + 1:].lower()
    print(mime_type.get(ext, "UNKNOWN"))
