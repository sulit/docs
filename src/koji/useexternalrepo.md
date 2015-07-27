> ============================================
>   Copyright (C) 2015 All rights reserved.
>
>   filename : useexternalrepo.md
>
>   author : sulit - sulitsrc@163.com
>
>   last modified : 2015-07-21 18:32
>
>   description :
>
> ============================================

koji使用外部仓库构建rpm包
===

相对于，使用本地仓库，就是添加了一个外部仓库到tag，整个测试命令如下：

```
kojiadmin$ koji add-tag dist-centos6

kojiadmin$ koji add-tag --parent dist-centos6 --arches "x86_64" dist-centos6-build

kojiadmin$ koji add-external-repo -t dist-centos6-build \
dist-centos6-repo \
http://mirrors.ustc.edu.cn/centos/6/os/$arch/

kojiadmin$ koji add-external-repo -t dist-centos6-build \
dist-epel6-repo \
http://mirrors.sohu.com/fedora-epel/6/$arch/
kojiadmin$ koji add-target dist-centos6 dist-centos6-build

kojiadmin$ koji add-group dist-centos6-build build

kojiadmin$ koji add-group dist-centos6-build srpm-build

kojiadmin$ koji add-group-pkg dist-centos6-build build bash bzip2 coreutils cpio \
diffutils findutils gawk gcc grep sed gcc-c++ gzip info patch \
redhat-rpm-config rpm-build shadow-utils tar unzip util-linux-ng which make

kojiadmin$ koji add-group-pkg dist-centos6-build srpm-build bash cvs gnupg make \
redhat-rpm-config rpm-build shadow-utils wget rpmdevtools

kojiadmin$ koji regen-repo dist-centos6-build

kojiadmin$ koji build --scratch dist-centos6 nginx-1.0.15-5.el6.src.rpm
```

> nginx-1.0.15-5.el6.src.rpm为从上面的那个外部仓库下载的srpm包

下面是把包加入tag，真正构建rpm包

```
kojiadmin$ koji add-pkg --owner kojiadmin dist-centos6 nginx

kojiadmin$ koji build dist-centos6 nginx-1.0.15-5.el6.src.rpm
```

#### 参考

1.
[https://fedoraproject.org/wiki/Koji/ExternalRepoServerBootstrap](https://fedoraproject.org/wiki/Koji/ExternalRepoServerBootstrap)

2.
[http://www.devops-blog.net/koji/koji-rpm-build-system-configuration-and-usage](http://www.devops-blog.net/koji/koji-rpm-build-system-configuration-and-usage)
