> ============================================
>   Copyright (C) 2015 All rights reserved.
>
>   filename : kickstart.md
>
>   author : sulit - sulitsrc@163.com
>
>   last modified : 2015-07-27 13:27
>
>   description :
>
> ============================================

kickstart文件介绍
===

#### 介绍

- 重点

在熟悉流程之后，就会知道做盘最重要的是kickstart文件的编写

- kickstart选项

 1. autostep
 在安装过程中，简单的显示每一步的屏幕，多用于调试。参数--autoscreenshot用于在
 安装过程中将每一步的屏幕截图，并保存到/root/anaconda-screenshots下，这对写文
 档有帮助。

- packages的选择

 1. 用%packages开始，列出你想安装的包;

 2. 包可以通过组或者单个包名被指定

- 预安装脚本

 1. %pre开始，%end结束，并且预安装不是工作在chroot下，注意这点

- 后安装脚本

 2. %post开始，%end结束，并且后安装是工作在chroot下，注意这点与预安装的区别

- 让kickstart文件可用

#### kickstart 例子

一个kickstart可以很简单，也可以很复杂，这完全取决于制作盘的人

- 一个简单的kickstart文件

[ksexample.ks](ksexample.ks)
