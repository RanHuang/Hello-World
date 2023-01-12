#! /usr/bin/env python
# -*- coding: utf-8 -*-

# 打卡数据所在目录和文件名
FILE_DIR = "data"
FILE_ORIGIN = "origin.xlsx"
FILE_ORIGIN_WEEKEND = "origin-weekend.xlsx"
FILE_PRE = "preprocess.xlsx"
FILE_PRE_COLOR = "preprocess_color.xlsx"
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

#### 迟到 & 早退 ###

FILE_ORIGIN_LATE = "originForLate.xlsx"
FILE_LATE_OR_EARLY = "lateOrEarly.xlsx"
# 周内上班迟到时间
TIME_WEEKDAY_BE_LATE_TIME = "08:35"
# 周内下班早退时间
TIME_WEEKDAY_LEAVE_EARLY_TIME = "17:30"

# 迟到
ORIGIN_COLUMN_IS_BE_LATE = 5
# 早退
ORIGIN_COLUMN_LEAVE_EARLY = 6

STRING_BE_LATE = "迟到"
STRING_LEAVE_EARLY = "早退"

#### 将代码统计数据合并到自统计数据中
# 自统计数据文件
FILE_HANDWORK = "handwork.xlsx"
# 有效数据起始列
HANDWORK_START_COLUMN_INDEX = 8
# 姓名列序号
HANDWORK_NAME_COLUMN_INDEX = 7

# 程序统计数据文件
FILE_PROGRAM = "summary.xlsx"
# 有效数据起始列
PROGRAM_START_COLUMN_INDEX = 4
# 姓名列序号
PROGRAM_NAME_COLUMN_INDEX = 3

# 合并后的数据文件
FILE_MERGED = "merged.xlsx"

# 统计黄色的单元格数量
COLOR_YELLOW = 'FFFFFF00'
FILE_ON_BUSINESS = 'business.xlsx'
