> ============================================
>   Copyright (C) 2015 All rights reserved.
>
>   filename : uselocalpackage.md
>
>   author : sulit - sulitsrc@163.com
>
>   last modified : 2015-07-21 15:35
>
>   description :
>
> ============================================

koji用本地包创建的仓库
===

> 说明：这个应该是使用最多的

- 导入需要的所有源码rpm包

`$ koji import *.src.rpm`

- 导入需要的所有rpm包

`$ koji import *.rpm`

- 创建一个标签

`$ koji add-tag dist-isoft`

- 将刚才导入的所有包添加到刚创建的标签中

`$ koji list-pkgs --quiet | xargs koji add-pkg --ower kojiadmin dist-isoft`

`$ koji list-untagged | xargs -n 1 koji call tagBuildBypass dist-isfot`

- 创建一个buildtag（好处是上面的dist-isoft还可以被其他种类的任务继承）

`$ koji add-tag --parent=dist-isoft --arches=x86_64 dist-isoft-build`

- 创建一个目标任务，要执行构建，必须作为目标任务进行构建

`$ koji add-target dist-isoft dist-isoft-build`

- 为buildtab添加build组和srpm-build组，build是生成rpm时要用到一些软件包组，而
sprm-build是生成srpm时用到的一些软件包组

`$ koji add-group dist-isoft-build build`

`$ koji add-group dist-isoft-build srpm-build`

- 往组中添加软件包，尽量添加的少，因为这是每次构建过程中都会重新在chroot环境中
去安装这些包，为了避免没有必要的包的安装，所以尽量用较少的包，其他需要的包，会
作为依赖被安装，值得一提的是fedora官方的f22 build组中只有24个包，其他的全是借
助依赖安装的

```
$ koji add-group-pkg koji-isoft-build build autoconf bash bzip2 coreutils \
diffutils findutils gawk gcc glibc-common glibc-devel glibc-heanders grep \
gzip make patch rpm-build shadow-utils tar util-linux-ng which xz

$ koji add-group-pkg koji-isoft-build srpm-build bash bzip2 gzip rpm-build
rpmdevtools shadow-utils tar

```

- 生成构建用的仓库（因为生成仓库会用到tag，因此当tag中软件包有变动时，需要重新
生成仓库，这是我自己的理解）

`$ koji regen-repo dist-isoft-build`

- 尝试性构建一个目标任务

`$ koji build --scratch dist-isoft zip-3.0-8.src.rpm`

- 如果要把某个包加进tag并用于最后的发布，这时生成的包会放进
/mnt/koji/packages目录下

`$ koji add-pkg --owner kojiadmin dist-isoft nginx`

`$ koji build dist-isoft nginx*.src.rpm`
