#固定长度的简单记录读写，结构如下：
#姓   -- 20 bytes
#名   -- 20 bytes
#地址 -- 40 bytes
#年龄 -- 4 bytes
.equ RECORD_FIRSTNAME, 0
.equ RECORD_LASTNAME, 20
.equ RECORD_ADDRESS, 40
.equ RECORD_AGE, 80

.equ RECORD_SIZE, 84
