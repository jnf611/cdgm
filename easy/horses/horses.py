#!/usr/bin/env python3
import sys

def printd(*args):
    print(args, file=sys.stderr)

n = int(input())
# strength = [5, 15, 17, 3, 8, 11, 28, 6, 55, 7]
strength = [int(input()) for i in range(n)]
strength.sort()
diff = [strength[i + 1] - strength[i] for i in range(len(strength) - 1)]
print(min(diff))
