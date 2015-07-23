> ============================================
>   Copyright (C) 2015 All rights reserved.
>
>   filename : rsyncrepo.md
>
>   author : sulit - sulitsrc@163.com
>
>   last modified : 2015-07-22 14:43
>
>   description :
>
> ============================================
同步中科院fedora22源码仓库
===

```
$mkdir -p myrepos/SRPMS
$rsync -avzL \
http://mirrors.ustc.edu.cn/fedora/linux/releases/22/Everything/source/SRPMS/ \
myrepos/SRPMS/
```
