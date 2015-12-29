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

- 遇到不熟悉的命令可以`koji -h`，`koji add-pkg -h`等，或者可以去查koji源码，搜
索你要查找的命令，里面有简单介绍，开源软件的文档缺失是通病，如果是咱们自己的项
目，建议编写一些文档，放到项目的docs中，善待别人，同时也是在善待自己，下一个软
件维护者，可能就是你。用markdown编写文档是不错的选择。

- 通常的手段是去查看错误日志，普通的编译任务日志在/mnt/koji/work/tasks/<任务号
+1>/<任务号+1>/下，一般会有四个文件，build.log，mock_output.log，root.log，
state.log。如果是用的scm类型的编译，会多出一个checkout.log。还有就是如果出错，
还有可能要到/var/lib/mock/<相关错误目录>/results中去查看，这种情况只有kojid和
kojihub在一台机器上时，或者你是kojid的管理员的情况下，可以去/var/lib/mock下去
查看。

- 不要随便升级koji及其组件，fedora有些东西是不稳定的

- 导入包的时候，注意给包打的tag。情形如下：

	* 顶级tag为dist-isoft，v4继承自dist-isoft，当导入包时，dist-isoft中有
个包foo-1，现在在koji上在v4 tag下重新build这个包，升级到foo-2。现在从外界导入
foo-3进dist-isoft，这时v4是不会继承这个foo-3的，原因是他认为自己对foo有了自己
的修改，相当于有了自己的分支，上游dist-isoft有了变化，不能一味地就接受，所以
foo-3是不会进入v4的，重建v4的仓库也就看不到这个foo-3。这种行为是很正常的行为，
所以在导入外界包时要特别注意。不推荐从外界导入大批量的已经在koji中存在的包的
新版本，个别包无法在koji上编译通过的除外，原因是这可能导致tag管理包的混乱。
如果是大量导入包，全部导入dist-isoft或者v4都会有潜在问题存在。

- 编译bug，此bug比较少见，因此略带诡异。17（48核处理器），在koji里编译gnutls
时，出现不能编过通过，当然gnutls srpm包不存在问题。后来武老师发现，有的cpu跑
的快，有的慢，而这个包中有些文件是动态生成的，如果在需要这个文件生成之前，就
去索引这个文件，而这个文件不存在，这时就会报错了。注意一下这种情况。
