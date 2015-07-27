> ============================================
>   Copyright (C) 2015 All rights reserved.
>
>   filename : kojiarch.md
>
>   author : sulit - sulitsrc@163.com
>
>   last modified : 2015-07-22 11:21
>
>   description :
>
> ============================================

koji架构
===

先附上一张原理图

![koji架构
](http://git.isoft.zhcn.cc/wangguofeng/docs/blob/master/src/koji/pictures/arch.png)

1. kojihub(核心)

koji-hub 是所有 Koji 操作的核心。它是一个运行在 Apache 服务器的 mod_python 模
块下的 XML-RPC 服务器。koji-hub 采用被动方式工作，它只接收 XML-RPC 请求，然后
依靠编译守护进程以及其他组件来进行通信。Koji-hub 是唯一可以直接访问数据库的组
件，也是两个对文件系统具有写权限的组件之一。

2. kojid

kojid 是运行在每一台编译机上的编译守护进程。它的主要任务是查询发送过来的编译请
求，根据实际情况进行处理。特别地， kojid 通过查询 koji-hub 上的信息进行工作。
除了编译软件包 Koji 还支持其他的任务，例如制作系统安装文件，这些任务也由 kojid
进行处理。kojid 利用 mock 创建原始的编译环境，并且为每一次编译任务单独创建一个
编译环境。kojid 是用 Python 编写的，并且通过 XML-RPC 与 koji-hub 进行通信。

3. kojira

kojira 是保持编译环境与系统同步更新的一个守护进程。它负责删除多余的编译环境，
还负责软件包编译任务结束后的清理工作。还负责编译机的分配。

4. koji cli

koji-client 是用 Python 写成的命令行终端工具，它提供了对 Koji 系统进行操作的很
多命令。它允许用户查询系统中的很多信息，还允许用户向 Koji 提交很多操作，比如：
添加用户和初始化编译请求。

5. koji web

koji-web 是一系列运行在 mod_python 模块下，采用 Cheetah 模板引擎生成的可以对
Koji 提供一套 web 页面接口的脚本文件。它作为 koji-hub 的客户端运行，为一些系统
管理命令提供了可视化的接口。通过 koji-web，您可以查看 Koji 系统中很多信息。并
且 koji-web 提供了一种方式完成系统中的部分操作，如取消软件包编译任务。
