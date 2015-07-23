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

  * 从频道中删除主机

  `koji remove-host-to-channel <hostname> <channelname>`

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

  * 重命名频道

  `koji rename-channel <oldname> <newname>`

  * 链式构建多个包

  `koji chain-build target <URL> [URL2 [:] URL3 [:] URL4 ...]`

  * 从源码构建一个maven包

  `koji maven-build target URL`

  * (不理解)

  `koji wrapper-rpm <target> <build-id|n-v-r> <URL>`

  * 运行一系列有依赖顺序的maven构建

  `koji maven-chain <target> <config> ...`

  * 重新提交一个任务

  `koji resubmit <taskID>`

  * 执行一个任意的XML-RPC调用

  `koji call name [arg...]`

  * 生成一个mock配置

  `koji mock-config [opthions]`

  * 重启使能所有编译机

  `koji restart-hosts`

  * 从一个comps文件导入组或者包信息

  `koji import-comps <file> <tag>`

  * 导入签名进数据库

  `koji import-sig <pkg> [pkg]`

  * 写签过名的rpm到硬盘

  `koji write-signed-rpm <signature-key> n-v-r [n-v-r ...]`

  * 精简签名副本（不确定）

  `koji prune-sigs`

  * 移动一个build到不同的卷

  `koji set-build-volume n-v-r [n-v-r ...]`

  * 增加一个新的存储卷

  `koji add-volume <volume-name>`

  * 列出所有卷

  `koji list-volumes`

  * 列出用户权限

  `koji list-permissions`

  * 增加一个用户

  `koji add-user <username>`

  * 使能一个用户登录

  `koji enable-user <username>`

  * 不使能一个用户登陆

  `koji disable-user <username>`

  * 列出rpms的签名副本

  `koji list-signed`

  * 导入就绪的软件包

  `koji import-in-place <pkg> [pkg]`

  * 导入一个和build关联的存档文件

  `koji import-archive <build-id | n-v-r> /path/to/archive...`

  * 赋予一个用户某种权限

  `koji grant-permission <permission> <user> [<user> ...]`

  * 吊销一个用户某种权限

  `koji revoke-permission <permission> <user> [<user> ...]`

  * 打印一个tag的最近build

  `koji latest-build <tag> <package> [package]`

  * 列出XML-RPC API

  `koji list-api`

  * 列出在一个tag中的builds或者rpms

  `koji list-tagged <tag> [pkg]`

  * 列出一个buildroot中用到的rpms

  `koji list-buildroot buildroot-id`

  * 列出没有打标签的包

  `koji list-untagged [pkg]`

  * 从一组包列表中阻塞一个包

  `koji block-group-pkg <tag> <group> <pkg> [<pkg>...]`

  * 从一组包列表中取消阻塞一个包

  `koji unblock-group-pkg <tag> <group> <pkg> [<pkg>...]`

  * 增加一个组到目标组需求列表

  `koji add-group-req <tag> <target group> <required group>`

  * 阻塞一个组的需求列表

  `koji block-group-req [options] <tag> <group> <blocked req>`

  * 取消阻塞一个组的需求列表

  `koji block-group-req [options] <tag> <group> <blocked req>`

  * 查看一个软件包的基本信息

  `koji rpminfo <n-v-r.a> [<n-v-r.a> ...]`

  * 查看一个build的基本信息

  `koji buildinfo <n-v-r.a> [<n-v-r.a> ...]`

  * 复制一个tag

  `koji clone-tag <src-tag> <dst-tag>`

  * 编辑一个target

  `koji edit-target <targetname>`
