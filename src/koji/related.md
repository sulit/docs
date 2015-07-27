> ============================================
>   Copyright (C) 2015 All rights reserved.
>
>   filename : related.md
>
>   author : sulit - sulitsrc@163.com
>
>   last modified : 2015-07-27 12:46
>
>   description :
>
> ============================================

koji的packages、tag、target、build关系
===

packages	用于构建、发布的软件包，这里是指包名

build	一个特定rpm的构建过程，就叫build，可以同时build多个架构的rpm包

rpm	packages特定的一个rpm软件包，可以使i386、x86_64或者其他的

tag	用来组织软件包的，可以被继承，创建target也是基于tag的

target	build是基于target的，我的理解是任务目标
