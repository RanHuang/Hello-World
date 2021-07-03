#! /usr/bin/env python
# -*- coding: utf-8 -*-

# 打卡数据所在目录和文件名
FILE_DIR = "data"
FILE_ORIGIN = "origin.xlsx"
FILE_PRE = "preprocess.xlsx"
FILE_CALC = "calc.xlsx"
FILE_SUMMARY = "summary.xlsx"
FILE_NAME_LIST = "name_list.xlsx"

CONTENT_WEEKDAY = "平时加班总时长"
CONTENT_WEEKEND = "周末加班总时长"

# 常量字符串
STRING_YES = 'Yes'
STRING_NO = 'No'
# 时间分割符
TIME_SEPARATOR = ";"

# 00:00以后07:00以前算凌晨
TIME_BEFORE_DOWN_START = "00:00"
TIME_BEFORE_DOWN_END = "07:00"

# 周内下班时间
TIME_WEEKDAY_OFF_TIME = "17:30"
# 周内晚上加班从18:30开始计算
TIME_WEEKDAY_OVER_TIME_START = "18:30"
# 周末上午下班时间为12:00
TIME_WEEKEND_OFF_WORK_MORNING = "12:00"
# 周末下午上班时间为14:00
TIME_WEEKEND_ON_WORK_AFTERNOON = "14:00"
# 周末晚上加班开始时间为18:00
TIME_WEEKDAY_OVER_TIME_NIGHT_START = "18:00"

# # Excel列名称
# 序号
ORIGIN_COLUMN_INDEX = 0
# 姓名
ORIGIN_COLUMN_NAME = 1
# 员工号
ORIGIN_COLUMN_ID = 2
# 打卡日期
ORIGIN_COLUMN_CHECK_IN_DATE = 3
# 打卡时间
ORIGIN_COLUMN_CHECK_IN_TIME = 4
# 凌晨打卡
ORIGIN_COLUMN_IS_BEFORE_DOWN = 5
# 是否周末
ORIGIN_COLUMN_IS_WEEKEND = 6
# 加班时间
ORIGIN_COLUMN_OVER_TIME = 7
# 加班时长
ORIGIN_COLUMN_OVER_TIME_STATISTIC = 8
# 异常说明/备注
ORIGIN_COLUMN_COMMENT = 9

# # Excel列名称
# 姓名
SUMMARY_COLUMN_NAME = 3
