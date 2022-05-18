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

    for col in range(ncols+1, ncols+4):
        ws.write(row, col, col-ncols)
    for col in range(ncols+5, ncols+11):
        ws.write(row, col, col-ncols-1)

    print "score: "
    for row in range(1, nrows):
        #calculate the score and write it to the new sheet
        row_values = []
        row_values = sheet.row_values(row)
        #copy the raw data
        for col in range(0, ncols):
            ws.write(row, col, row_values[col])

        # 7+2=9 空白
        # a 8; b 24; c 14; d 4
        # 总共59列
        # 其中c[1,14]和d[3]为2分多选题，其余为1分单选
        col_write = ncols
        #1
        score = 0
        col_write += 1
        for col in (9,10,11,13,16,17,18,19,21,22,23,24,25,28,32,37,58): 
            if(answer[col] == row_values[col]):
                score = score+1;
        for col in (42, 43, 44, 45, 53, 57):
            if(answer[col] == row_values[col]):
                score = score+2;
        ws.write(row, col_write, score)
        print "Row: ", row, "1: ", score,
        
        #2
        score = 0
        col_write += 1
        for col in [12, 14, 15, 20, 26, 27, 29, 30, 33, 35]: 
            if(answer[col] == row_values[col]):
                score = score+1;
        for col in [41, 47, 48, 50, 51]:
            if(answer[col] == row_values[col]):
                score = score+2;
        ws.write(row, col_write, score)
        print "1: ", score,
        
        #3
        score = 0
        col_write += 1
        for col in [31, 34, 36, 38, 39, 40, 55, 56]: 
            if(answer[col] == row_values[col]):
                score = score+1;
        for col in [46, 49, 52, 54]:
            if(answer[col] == row_values[col]):
                score = score+2;
        ws.write(row, col_write, score)
        print "3: ", score,
        
        #4
        score = 0
        col_write += 2
        for col in [10, 16, 17, 25, 26]: 
            if(answer[col] == row_values[col]):
                score = score+1;
        for col in [41, 52]:
            if(answer[col] == row_values[col]):
                score = score+2;
        ws.write(row, col_write, score)
        print "4: ", score,
        
        #5
        score = 0
        col_write += 1
        for col in [9, 18, 23, 28, 35]: 
            if(answer[col] == row_values[col]):
                score = score+1;
        for col in [50]:
            if(answer[col] == row_values[col]):
                score = score+2;
        ws.write(row, col_write, score)
        print "5: ", score,
        
        #6
        score = 0
        col_write += 1
        for col in [12, 14, 19, 20, 21, 58]: 
            if(answer[col] == row_values[col]):
                score = score+1;
        for col in [43, 47, 48, 57]:
            if(answer[col] == row_values[col]):
                score = score+2;
        ws.write(row, col_write, score)
        print "6: ", score,
        
        #7
        score = 0
        col_write += 1
        for col in [11, 22, 24, 32, 39, 40]: 
            if(answer[col] == row_values[col]):
                score = score+1;
        for col in [45, 46, 53, 54]:
            if(answer[col] == row_values[col]):
                score = score+2;
        ws.write(row, col_write, score)
        print "7: ", score,
        
        #8
        score = 0
        col_write += 1
        for col in [13, 15, 27, 29, 30, 33, 34,36, 37, 38]: 
            if(answer[col] == row_values[col]):
                score = score+1;
        for col in [42, 51]:
            if(answer[col] == row_values[col]):
                score = score+2;
        ws.write(row, col_write, score)
        print "8: ", score,
        
        #9
        score = 0
        col_write += 1
        for col in [31, 55, 56]: 
            if(answer[col] == row_values[col]):
                score = score+1;
        for col in [44, 49]:
            if(answer[col] == row_values[col]):
                score = score+2;
        ws.write(row, col_write, score)
        print "9: ", score
        
    wb.save("new_"+fileName+'.xls')
    print

def main():
    fileNames = ['beilin', 'gaoling', 'huxian', 'lianhu', 'lintong', 'weiyang', 'xincheng', 'yanliang', 'zhouzhi', 'fengdongxincheng', 'lantian', 'yanta']
    answerFile = 'answer1'
    for fileName in fileNames:
        calculateScore(fileName+"_merge_score", answerFile)

if __name__ == '__main__':
    main()
