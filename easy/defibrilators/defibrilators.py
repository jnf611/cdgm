#!/usr/bin/env python3
import sys
from math import cos, sqrt, pi, inf
from collections import namedtuple
import string

def printd(*args):
    print(args, file=sys.stderr)

def to_float(string):
    return float(string.replace(",", "."))

def to_radian(degree):
    return degree * pi / 180

Point = namedtuple("Point", "longitude, latitude")

def coord_distance(a, b):
    x = (b.longitude - a.longitude) * cos((a.latitude + b.latitude) / 2)
    y = b.latitude - a.latitude
    return 6371.0 * sqrt(x * x + y * y)

user_position = Point(to_radian(to_float(input())), to_radian(to_float(input())))
printd("position:(", user_position, ")")
n = int(input())

Distance = namedtuple("Distance", "distance, name")
closest = Distance(inf, "")
for i in range(n):
    defib = input()
    printd(defib)
    index, name, address, contact, lon, lat = defib.split(";")
    defib_position = Point(to_radian(to_float(lon)), to_radian(to_float(lat)))
    distance = coord_distance(defib_position, user_position)
    if distance < closest.distance:
        closest = Distance(distance, name)

print(closest.name)
