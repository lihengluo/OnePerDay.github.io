# Git教程

> git中存在一个文件的三个工作目录， 索引， 对象数据库
>
> 提交是对索引的快照，分支是提交的一次引用
>
> 指向父提交

[Git-CheatSheet](./doc/Git-Cheatsheet.pdf)

### 第一章

> Git中存在一个文件的三个工作目录， 索引， 对象数据库


```bash
git init
git add -a # 添加所有文件到索引
git commit -m "message"
--amend # 修改提交消息
git config 
--global # 配置git命令
```
### 第二章

> 提交是对索引的快照，分支是提交的一次引用，分支在Git中是非常廉价的，通常用来添加特性分支。
> 每一次切换分支都会重新更新工作目录。


```bash

git branch 
-a # 显示所有分支名 
-d # 删除分支
-m # 修改分支名

git status # 显示git工作的状态，建议常用，遇事不决就用status查询状态和建议

git switch # 切换分支
-c # 创建并切换分支 

git merge branch1 # 合并branch1到当前分支
# 处理分支之间的差异，在merge之后需要再次add和commit进行提交

```

### 第三章

>  多使用git log看看吧！

```bash

git log # 打印git日志 
--oneline # 简化提交信息到一行
--all # 显示所有分支
--graph # 将分支的情况用图形画出来
-v # 显示详细信息
-vv # very verbose 显示非常详细信息

git diff # 比较工作目录和索引的差异，按照行进行返回
--word # 按照word的差异进行展示
--cached or --staged # 将工作目录的文件同对象数据库比较
git diff A B # 比较分支A B之间的差别

```

### 第四章

> HEAD 指向当前提交的位置和分支
> HEAD~n  指向HEAD中第n个父提交
> HEAD^1 指向HEAD多个父提交中的第一个父提交

```bash

git restore a.md # 撤销工作目录的变更
--staged 
# 如果在修改之后已经添加到索引，使用该命令并不撤销提交，将上一次提交的内容复制到索引里，然后再使用一次git restore将索引数据库复制到工作目录，达到撤销提交的目的。

git rm # 只删除git中track的文件

git mv # 类似linux中的mv命令

git reset commit-ID/HEAD~1 # 删除提交
--soft # 将HEAD对应的提交的移到索引和工作目录，然后将对象数据库变更到上一个提交HEAD~1
--mixed(default) # 先执行--soft，然后将对象数据库的内容复制到索引 
--hard # 完全删除提交，具有破坏性

git revert HEAD# 反转提交，创建一个新提交

```

### 第五章

> 通过github personal access token可以让其他人访问你的github库

```bash

git clone URL

git push -u origin master 
# -u 代表
# orgin 指定的远端的名字，可以更改
# master 推送的分支

git remote # 设置远端的信息，不同的标签可以用于不同的远端库
-v
-vv

# Github pull request
# 在推送本地特性分支后， 可以在github上创建拉取请求，让其他库的所有者或者管理员有机会审查你的代码提交，并且决定是否合并你提交的代码。

# 远程分支origin/master
git pull # 拉取github上的最新提交，将orgin/master和master指向同一个分支的最新提交，同时跟踪远程分支和本地分支

# 推荐使用
git fetch # 只更新远程分支到最新分支，但不影响本地提交  
git pull = git pull + git merge

```

[一个标准的github 工作流程](https://www.ruanyifeng.com/blog/2015/08/git-use-process.html)

### 第六章

> 在Git中也可以搜索！

```bash

git blame a.md # 查看文件的每一行的最后一个提交 

git log # 一种更加细节的搜索
-S # 查询每个提交，只返回基本喜喜
git log -p -S tired a.md # 查询a.md所有提交中增加或删除“tired”的，返回ID和详细信息
--word-diff # 显示单词差异
-G # 特定文本在提交差异中的每一次出现
--grep #  类似于git grep

git grep # 在git中搜索字符串
-n # 显示行号
-i # 不区分大小
-l # 只显示文件名

git check out # 检出提交查看该提交的确切状态，分离状态

git bitsect start/good/bad # 用一个二分查找进行搜索提交

# 使用别名
git config --glocal alias.loga "log --all --oneline -- graph"

```

### 第七章

> 遵循规范可以让我们更有效率！

[git commit message的书写规范](https://www.freecodecamp.org/news/how-to-write-better-git-commit-messages/)

```txt

feat:新增的新特性
fix:修改的bug
docs:对文档的修改
chore:对工具的修改
test:对功能的测试
分支命名的规范:名字/工号/内容:Bytedance/0112/feat-a

```

### appendix目录
> 一切都没结束！

```bash

git tag # 为某个提交创建标签，一般为v1.0.0

git cherry-pick # 移动一个提交到当前分支

git stash # 暂存当前分支的变更，方便切换到别的分支

git reflog # 查看HEAD的移动情况

git rebase #变基，相当于一种新的合并，会在合并分支master上获得最新的提交。然后将待合并分支的所有提交全部进行变更。

```

### 引用

《Head First Git实战》

https://i-love-git.com/
