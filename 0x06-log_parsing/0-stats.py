#!/usr/bin/python3
"""Practice with Parsing Log Data"""
from collections import defaultdict
import os
import re
import sys

STATUS_CODES = {200, 301, 400, 401, 403, 404, 405, 500}


def parse_line(line):
    """Parse formatted log data and return values in a tuple"""
    reg = re.compile(
        r'(^[.0-9]+)\s-\s\[([-:.\s0-9]+)\]\s("[^"]+")\s(\d{3})\s(\d+)')
    match = reg.match(line)
    components = match.groups()
    return components


def print_stats(file_size, status_code_data):
    """Print out info about log data"""
    print("File size: {}".format(file_size))
    for code in sorted(status_code_data):
        print("{}: {}".format(code, status_code_data[code]))


def parse_log():
    """Parse log data being fed to stdin"""
    log_data_labels = ('ip_addr', 'date', 'req', 'status_code', 'file_size')
    statuses_seen = defaultdict(int)
    n_lines, file_size = 0, 0

    try:
        for line in sys.stdin:
            if line:
                parsed = parse_line(line)
                data = dict(zip(log_data_labels, parsed))
                if int(data['status_code']) in STATUS_CODES:
                    statuses_seen[data['status_code']] += 1
                    file_size += int(data['file_size'])
                    n_lines += 1
                    if n_lines % 10 == 0:
                        print_stats(file_size, statuses_seen)
    except KeyboardInterrupt:
        print_stats(file_size, statuses_seen)
        raise

    if n_lines % 10 != 0:
        print_stats(file_size, statuses_seen)

    return os.EX_OK


if __name__ == "__main__":
    sys.exit(parse_log())
