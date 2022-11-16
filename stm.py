#! /usr/bin/python3

# stm.py - seconds till midnight
#
# flags: -n   = noon, not midnight
#        -o # = offset by # seconds


import getopt, sys
from datetime import datetime

try:
    opts, args = getopt.getopt(sys.argv[1:], "no:", ['noon', 'offset='])
except getopt.GetoptError as err:
    print(str(err))
    sys.exit(2)

offset = 0
noon   = False

for option, argument in opts:
    if option == '-n':
        noon = True
    elif option == '-o':
        offset = int(argument)
    else:
        assert False, "unknown option"


now = datetime.now()

# seconds since midnight
ssm = (now - now.replace(hour=0, minute=0, second=0, microsecond=0)).total_seconds()

if noon:
    target = (12 * 3600) - ssm
else:
    target = (24 * 3600) - ssm


print(int(target) + offset)

