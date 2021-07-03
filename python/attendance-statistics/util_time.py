#! /usr/bin/env python
# -*- coding: utf-8 -*-

from datetime import datetime


def is_weekend(day_str):
    """
    if a day is weekend
    :param day_str: string of a day
    :param separator: separator of year, month and day, default is empty
    :return: True: is weekend; False: not weekend
    """
    spec = "%Y-%m-%d %H:%M:%S"
    day = datetime.strptime(day_str, spec).date()
    # Monday == 0 ... Sunday == 6
    if day.weekday() in [5, 6]:
        return True
    else:
        return False


def calc_duration_time(start_str, end_str):
    time_format = "%H:%M"
    start = datetime.strptime(start_str, time_format)
    end = datetime.strptime(end_str, time_format)
    delta = end - start
    seconds = delta.seconds
    hours = seconds / 3600.0
    return round(hours, 2)


if __name__ == "__main__":
    print(is_weekend("2021-06-07 00:00:00"))
    print(is_weekend("2021-06-13 00:00:00"))
    print("================================")
    print(calc_duration_time("18:30", "20:46"))
    print(calc_duration_time("19:23", "20:46"))

