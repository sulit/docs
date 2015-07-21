> ============================================
>   Copyright (C) 2015 All rights reserved.
>
>   filename : usegit.md
>
>   author : sulit - sulitsrc@163.com
>
>   last modified : 2015-07-21 17:34
>
>   description :
>
> ============================================

koji用git服务器上的源码
===

> 测试用的是外部仓库，所有操作命令如下：

```
kojiadmin$koji add-tag dist-f22
kojiadmin$koji add-tag --parent dist-f22 --arches "x86_64" dist-f22-build
kojiadmin$koji add-external-repo -t dist-f22-build \
dist-f22-build-external-repo \
http://mirrors.kernel.org/fedora/releases/22/Everything/\$arch/os/
kojiadmin$koji add-target dist-f22 dist-f22-build
kojiadmin$koji add-group dist-f22-build build
kojiadmin$koji add-group dist-f22-build srpm-build
kojiadmin$koji add-group-pkg dist-f22-build build bash bzip2 coreutils cpio \
diffutils findutils gawk gcc grep sed gcc-c++ gzip info patch \
redhat-rpm-config rpm-build shadow-utils tar unzip util-linux-ng which make
kojiadmin$koji add-group-pkg dist-f22-build srpm-build bash cvs gnupg make \
redhat-rpm-config rpm-build shadow-utils wget rpmdevtools
kojiadmin$koji regen-repo dist-f22-build
```

1. 有Makefile的配置

源码包中必须包含以spec为后缀的文件，剩下的不是必须的，因情况而定，有的会包含
Makefile文件，而有的不会。区别在于，kojid.conf中allow_scms选项的配置，这个选项
后面可以跟一些shell命令以逗号隔开各参数。应该注意的是这里设置值时需要做的是不
要在域名前加任何http或者ftp之类的选项，否则在build时会报错。我的kojid.conf中
allowed_scms配置如下：

```
allowed_scms=github.com:/mengyilog/*:no
```

koji支持很多scm选项，我只测试了https，用的是github上的代码，咱们公司的稍后会试
。测试命令如下：

```
kojiadmin@koji build --scratch dist-f22 \
"git+https://github.com/mengyilog/xz.git?#de0f5ecf8e8c2640a32e027dbf664afe578de2c0"
```
