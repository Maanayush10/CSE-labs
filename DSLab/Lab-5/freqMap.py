from __future__ import print_function
import sys
# input comes from STDIN (standard input)
for line in sys.stdin:
# create tuples of all words in line
    L = [ (word.strip().lower(), 1 ) for word in line.strip().split() ]
# increase counters
    for word, n in L:
        print( '%s\t%d' % (word, n) )