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

> 在git.isoft.zhcn.cc上的测试如下：

1. 修改编译服务器/etc/kojid/kojid.conf的allowed_scms字段内容如下：

`allowed_scms=git.isoft.zhcn.cc:*:no::`

关于最后一个`:`，其实是这里我替换了系统默认的执行命令`make sources`，因为
用scm默认会执行`make sources`，而我们的git上不需要多写这个Makefile文件，所以就
用一条空指令代替，注意重启kojid，重启指令`sudo service kojid restart`。

*注意*：在所请求的git项目上必须有能够完整构建一个srpm包的所有文件，当然fedora
官方没有这个要求，他们只有两个文件，一个是spec文件，一个是source文件，巧妙之处
在于他们在allowed_scms后面添加了一些类似于`spectool,-g,*.spec`之类的一些sh命令
，这样，所需要的软件包就是直接从网上去下载，然后用于构建。不幸的是，我们不支持
这样做，原因是，我们的srpm-build组中虽然有rpmdevtools这个包名，但是那只是个样
子，我们导入到tag的包中不包含这个rpm包，而spectool这个软件恰巧在这个包中。鉴于
这个原因，我们的git只能处理包含所有能构建src.rpm包的git项目

2. 客户端执行指令如下(#后面跟得是xz项目的head，可以使短的，也可以是长的，还需
要注意的是，项目下必须有一个能构建src.rpm包的所有文件)：

`koji build --scratch  dist-moses \
"git+http://git.isoft.zhcn.cc/wangguofeng/xz.git?#82e5cd2528f5a8fe8aef6e86f295e475aaf5dc22"`

> 下面的是之前测试git用的，可以不用看了，若是向多了解测试过程的话，可以去看，
> 但是感觉没有那么大的必要了。

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
Makefile文件，而有的不会。区别在于，kojid.conf中allowed_scms选项的配置，这个选项
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
