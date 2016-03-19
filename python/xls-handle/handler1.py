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

def convert(fileName):
    print "待处理文件：", fileName

    sheet = openExcelSheet(fileName+'.xls')
    nrows = sheet.nrows
    ncols = sheet.ncols
    print "Rows:", nrows
    print "Cols:", ncols
    
    wb = xlwt.Workbook()
    ws = wb.add_sheet('Sheet1')
    # copy the 1st line
    row = 0
    row_values = sheet.row_values(row)
    for col in range(0, 42):
        ws.write(row, col, row_values[col])

    print "Merge: "
    for row in range(1, nrows):
        row_values = []
        row_values = sheet.row_values(row)
        # 9 空白
        # a 8; b 24; c 14; d 4
        # 总共59列
        # 其中c[1,14]和d[3]为2分多选题，其余为1分单选

        # copy 9+8+24 = 41 colums 
        for col in range(0, 41):
            ws.write(row, col, row_values[col])
        #merge C
        col = 40
        col_src = 40
        for i in range(0,14):
            col = col+1
            merstr = ''
            for j in range(0,5):
                col_src = col_src+1
                cell_data = 0 if row_values[col_src] == '' else int(row_values[col_src])
                merstr = merstr + str(int(cell_data))
            ws.write(row, col, merstr)

        col = col+1
        col_src = col_src+1
        ws.write(row, col, row_values[col_src])

        col = col+1
        col_src = col_src+1
        ws.write(row, col, row_values[col_src])

        col = col+1
        merstr = ''
        for j in range(0,5):
            col_src = col_src+1
            cell_data = 0 if row_values[col_src] == '' else int(row_values[col_src])
            merstr = merstr + str(int(cell_data))
        ws.write(row, col, merstr)

        col = col+1
        col_src = col_src+1
        ws.write(row, col, row_values[col_src])
        
    wb.save(fileName+'_merge'+'.xls')

def main():
    fileNames = ['beilin', 'gaoling', 'huxian', 'lianhu', 'lintong', 'weiyang', 'xincheng', 'yanliang', 'zhouzhi', 'fengdongxincheng', 'lantian', 'yanta']
    for fileName in fileNames:
        convert(fileName)
        print
        
if __name__ == '__main__':
    main()
