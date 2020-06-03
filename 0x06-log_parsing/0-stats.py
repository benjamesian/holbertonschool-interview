#!/usr/bin/python3
"""Practice with Parsing Log Data"""
import re
import sys


def parse_line(line):
    """Parse formatted log data and return values in a tuple"""
    reg = re.compile(
        r'(^[.0-9]+)\s-\s\[([-:.\s0-9]+)\]\s("[^"]+")\s(\d+)\s(\d+)')
    match = reg.match(line)
    components = match.groups()
    return components


def print_stats(file_size, stats: dict):
    """Print out info about log data"""
    print("File size: {}".format(file_size))
    print(*("{}: {}\n".format(k, v) for k, v in sorted(stats.items()) if v),
          sep='', end='')


def parse_log():
    """Parse log data being fed to stdin"""
    log_data_labels = ('ip_addr', 'date', 'req', 'status_code', 'file_size')
    valid_codes = {"200", "301", "400", "401", "403", "404", "405", "500"}
    statuses_seen = {key: 0 for key in valid_codes}
    n_lines, file_size = 0, 0

    try:
        for line in sys.stdin:
            n_lines += 1
            parsed = parse_line(line)
            data = dict(zip(log_data_labels, parsed))
            if data['status_code'] in valid_codes:
                statuses_seen[data['status_code']] += 1
                file_size += int(data['file_size'])
                if n_lines % 10 == 0:
                    print_stats(file_size, statuses_seen)
    except KeyboardInterrupt:
        print_stats(file_size, statuses_seen)
        raise

    print_stats(file_size, statuses_seen)


if __name__ == "__main__":
    parse_log()
