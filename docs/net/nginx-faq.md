nginx代码阅读心得
================

- localtime和localtime_r

	man localtime获得以下信息
	Except for difftime(), mktime(), and the _r() variants of the other
     functions, these functions leave their result in an internal static
     object and return a pointer to that object.  Subsequent calls to these
     function will modify the same object.

     除了difftime、mktime、和后缀_r的函数，这些函数保存他们
     的结果在一个内部静态变量中，然后返回这个变量的指针，如
     果这些函数随后被调用，这个内部静态变量将被修改。

     通俗点讲，就是说localtime是不可重入的，localtime_r是可重入的。
