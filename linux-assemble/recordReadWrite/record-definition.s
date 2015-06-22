#固定长度的简单记录读写，结构如下：
#姓   -- 40 bytes
#名   -- 40 bytes
#地址 -- 240 bytes
#年龄 -- 4 bytes
.equ RECORD_FIRSTNAME, 0
.equ RECORD_LASTNAME, 40
.equ RECORD_ADDRESS, 80
.equ RECORD_AGE, 320

.equ RECORD_SIZE, 324
