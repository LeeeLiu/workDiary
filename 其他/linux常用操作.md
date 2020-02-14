
## Linux

### vim
[一般使用方法](http://hpc.whu.edu.cn/info/1035/1027.htm)
1. 按i
2. ESC
3. `:wq`

### 一般
1. DOS--> Linux格式
`dos2unix`
2. 查看当前目录下，每个文件夹的大小
` du -sh * `
3. 查看某个目录下，所有文件个数。
find images0/* -type f | wc -l
4. 查看某个目录下，所有子目录个数。
find images0/* -type d | wc -l

移动
`mv 源文件夹 目标文件夹`

查看当前登录用户
`users`
`who`
`top`

查看隐藏文件夹
`ll -a`