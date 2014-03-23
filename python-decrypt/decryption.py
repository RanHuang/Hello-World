#! /usr/bin/python 
import xlrd
import xlwt
def open_excel(file ='supsch-rockford-crypted.xls'):
    try:
        data = xlrd.open_workbook(file)
        return data;
    except Exception,e:
        print str(e)
#
def main():       
    print "Hello!"
    file = open_excel('./supsch-rockford-crypted.xls')
    try:
        sheet = file.sheet_by_name("Sheet1")
    except:
        print("No sheet in the xls file")
        return

    nrows = sheet.nrows
    ncols = sheet.ncols
#print("%d rows, %d cols"%(nrows,ncols))
#read the data from the file and print them out to the stdout.
    strkey = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ123456789'
    strkeylen = len(strkey)
    print(strkeylen)
        
#for row in range(1, 5):
#       origin = str(sheet.cell(row, 0).value)
#     print(origin[0])
#   print(origin)

    origin = "S6ksgto@xuiqluxj.kjA"
    print(origin)
    decription = ''
    strlen = len(origin)
    for i in range(0,strlen):
        for j in range(0,strkeylen):
            if(origin[i] == strkey[j]):
                index = (j-6+strkeylen)%strkeylen
                decription += strkey[index]
                break;
            if(j == strkeylen-1):
                decription += origin[i]
    print(decription)
    
#Write the rusult to the file decription.xls
    wb = xlwt.Workbook()
    ws = wb.add_sheet('description')
    ws.write(0,0,'Email')
    for i in range(0,ncols):
        ws.write(0,i+1,sheet.cell(0,i).value)

    print('@@@@@@@@@@@@@@@@@@@@Begin the decription@@@@@@@@@@@@@@@@@@@@@')
    for row in range(1, nrows):
        origin = str(sheet.cell(row,0).value)
        decription = ''
        strlen = len(origin)
        for i in range(0,strlen):
            for j in range(0,strkeylen):
                if(origin[i] == strkey[j]):
                    index = (j-6+strkeylen)%strkeylen
                    decription += strkey[index]
                    break;
                if(j == strkeylen-1):
                    decription += origin[i]
#        print(decription)
        ws.write(row,0,decription)
        for i in range(0,ncols):
            ws.write(row,i+1,sheet.cell(row,i).value)
    print('@@@@@@@@@@@@@@@@@@@@@The end of decription@@@@@@@@@@@@@@@@@@@@')
    wb.save('decription.xls')
    
    print "The end!"

if __name__ == '__main__':
    main()
