#! /usr/bin/env python
# -*- coding: utf-8 -*-
import xlrd
import xlwt

def openExcelSheet(fileName, sheetIndex = 0):
    try:
        data = xlrd.open_workbook(fileName)
        table = data.sheet_by_index(sheetIndex)
        return table;
    except Exception, e:
        print str(e)

def calculateScore(fileName, answerFile):
    print "答案文件：", answerFile
    print "待处理文件：", fileName

    sheet = openExcelSheet(answerFile+'.xls')
    answer = sheet.row_values(1)

    sheet = openExcelSheet(fileName+'.xls')
    nrows = sheet.nrows
    ncols = sheet.ncols
    
    wb = xlwt.Workbook()
    ws = wb.add_sheet('score')
    # copy the 1st line
    row = 0
    row_values = sheet.row_values(row)
    for col in range(0, ncols):
        ws.write(row, col, row_values[col])
    ws.write(row, ncols, 'Score')

    print "score: "
    for row in range(1, nrows):
        row_values = []
        row_values = sheet.row_values(row)
        score = 0
        # 7+2=9 空白
        # a 8; b 24; c 14; d 4
        # 总共59列
        # 其中c[1,14]和d[3]为2分多选题，其余为1分单选
        for col in range(9, 41):
            if(answer[col] == row_values[col]):
                score = score+1;
        for col in range(41,55):
            if(answer[col] == row_values[col]):
                score = score+2;
        for col in (55, 56, 58):
            if(answer[col] == row_values[col]):
                score = score+1;
        col = 57
        if(answer[col] == row_values[col]):
            score = score+2;
        print score,
    
        # write the score to a new sheet
        for col in range(0, ncols):
            ws.write(row, col, row_values[col])
        ws.write(row, ncols, score)

    wb.save(fileName+'_score'+'.xls')
    print

def main():
    fileNames = ['beilin', 'gaoling', 'huxian', 'lianhu', 'lintong', 'weiyang', 'xincheng', 'yanliang', 'zhouzhi', 'fengdongxincheng', 'lantian', 'yanta']
    answerFile = 'answer1'
    for fileName in fileNames:
        calculateScore(fileName+'_merge', answerFile)

if __name__ == '__main__':
    main()
