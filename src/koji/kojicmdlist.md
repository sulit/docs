> ============================================
>   Copyright (C) 2015 All rights reserved.
>
>   filename : kojicmdlist.md
>
>   author : sulit - sulitsrc@163.com
>
>   last modified : 2015-07-22 10:20
>
>   description :
>
> ============================================

koji命令总结
===

> 欢迎追加

1. 较长用的命令

  * 测试你的koji是否能正常使用

  `koji moshimoshi`

  * 导入软件包

  `koji import <pkg> [<pkg>]`

  * 添加tag

  `koji add-tag <tagname>`

  * 添加target

  `koji add-target <name> <build-tag>`

  * 添加group

  `koji add-group <tag> <groupname>`

  * 往group中添加build所需的一些软件

  `koji add-group-pkg <tag> <group> <pkg> [pkg]`

  * 生成tag用的仓库

  `koji regen-repo <build-tag>`

  * 尝试构建(这个命令build成功后，包会保存到/mnt/koji/scratch下)

  `koji build --scratch <target> <srpm path or scm url>`

  * 往tag中添加包并为拥有者赋值

  `koji add-pkg --owner <name> <tag> <pkgname>`

  * 从tag中删除软件包

  `koji remove-pkg <tag> <pkgname>`

  * 进行build(这个命令build成功后，包会存放在/mnt/koji/packages/相应的包名下)

  `koji build <target> <pkgname>`

  * 添加编译主机

  `koji add-host <hostname> <arch> [<arch>]`

  * 修改编译主机

  `koji edit-host <hostname> [--arches=ARCH]`

  * 添加编译主机到某个频道(有一些默认频道，注意要是在某个频道有任务时，至少要
分配一个编译机，默认频道有default，createrepo,maven,livecd,appliance,vm，可以
新生成频道，可以通过`koji add-host-to-channel --list`列出所有频道)

  `koji add-host-to-channel <hostname> <channelname>`

  * 列出某个tag的分组及其中的软件包

  `koji list-groups <tag> [groupname]`

  * 列出所有导入的软件包

  `koji list-pkgs`

  * 增加外部仓库

  `koji add-exteranl-repo -t <tag> <name> <repo url>`

  * 列出外部仓库

  `koji list-external-repos [--tag=TAG]`

  * 删除外部仓库

  `koji remove-external-repo [--force] <external-repo-name> [tag]`

  * 停止某个编译机

  `koji disable-host <hostname>`

  * 启用某个编译机

  `koji disable-host <hostname>`
