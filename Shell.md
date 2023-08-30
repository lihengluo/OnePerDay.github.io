# Shell && Linux

---

#### 2023.08.15

**Shell命令**

```shell 
# echo
echo ...
# redirect < > << >> 
echo "hello,world" > file
echo < file
ls < file1 > file2
1 >> file  # 在原有文件上(追加)
# grep
grep hello file.txt
# | 左边命令的输出作为右边命令的输入
ls -lh | grep test 
# tee 从标准输入读取内容并同时写入标准输出与一个或多个文件
echo "hello" | tee file1 file2
```

#### 2023.8.16

**文件权限**

`-rwxr-----`为一般的文件权限，可以使用`ls -lh`查看，后面9个字符分别对应owner, group, others的权限，可以使用`chmod xyz file` `chown/chgrp`等命令对文件更改权限。

**shell变量**

```bash
# set/env 显示环境

# export PATH=xxxx
# read/declare
read atest
...
echo ${atest}
```

**shell命令**

```bash
# awk 按行处理
# sed 替换，感觉跟tr有部分公用的场景
```

#### 2023.8.18

**shell命令**

```shell
# ag 
```

