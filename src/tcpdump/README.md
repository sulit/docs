tcpdump简要文档
===============

- *w* [file] 参数会把抓取的包写到文件，方便稍后进行分析。

- *r* [file] 参数表示从文件进行读取

- *V* [filelist] 参数表示从文件列表读取，filelist是一个文件，文件内容是各个包文件的名字

- *c* [count] 表示收取到count个包后退出tcpdump，可以被SIGINT或者SIGTERM中断

- *A* 参数表示用ASCII码显示捕捉到的内容，一般用来操作捕捉web页面

- *b* 参数表示以ASDOT表示法打印BGP数据包中的AS号，而不是ASPLAIN符号

- *B* [buffersize] 参数设置操作系统捕捉缓存大小为buffersize，单位是KB

- *C* [file size] 参数写一个包到文件时，首先计算文件大小，如果文件大小超过file size，会关闭文件，打开新的文件（文件名是之前的文件名+1）继续写

- *d* 以人类可读的方式复制匹配的编译码到标准输出，然后退出

- *dd* 以C语言的形式复制匹配复制匹配的代码格式
