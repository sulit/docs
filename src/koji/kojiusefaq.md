> ============================================
>   Copyright (C) 2015 All rights reserved.
>
>   filename : kojiusefaq.md
>
>   author : sulit - sulitsrc@163.com
>
>   last modified : 2015-07-22 12:14
>
>   description :
>
> ============================================

koji编译软件包过程中出现的错误及其总结
===

- 通常的手段是去查看错误日志，普通的编译任务日志在/mnt/koji/work/tasks/<任务号
+1>/<任务号+1>/下，一般会有四个文件，build.log，mock_output.log，root.log，
state.log。如果是用的scm类型的编译，会多出一个checkout.log。还有就是如果出错，
还有可能要到/var/lib/mock/<相关错误目录>/results中去查看，这种情况只有kojid和
kojihub在一台机器上时，或者你是kojid的管理员的情况下，可以去/var/lib/mock下去
查看。
