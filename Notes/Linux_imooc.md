ls 
    -a          all
    -l          use a long listing format          ==ll
    -h           human-readable
    -i
mkdir
cd
    cd ~
    cd 
    cd -
    cd ..
    cd .
rm
    -r
cp
    -a
    -r
mv
ln
    -s
locate
whereis
which
find [搜索范围] [搜索条件]
    find / -nouser
              -name
              -iname
              -mtime
              -size
              -inum
                   -a
                   -o
                   -exec ... {} \;
grep [选项] 字符串 文件名
    -i
    -v
man
    -f     ==whatis
    -k     ==apropos
--help
help
zip
tar
    -zcvf
    -zxvf
mount
    -a
    -o noexec
w
last
lastlog
echo
    -e
alias
cat

命令  >>  文件  2>>文件
命令  &>>  文件
命令  >>  文件  2&>1

ctrl
    +l
    +c
    +a
    +e
    +u
    +z
    +r
tab

; && || |
netstat | grep ESTABLISHED | wc -l

通配符
? * []

‘’ “” `` &() # $ \


vim

vim abc
vim + abc
vim +3 abc
vim +/xxx abc       n

模式切换: i 

底行模式
:!
:q
:w
:wq
:q!
:n
:N
:ls
:<num>
/xxx
?xxx

命令模式
h j k l 
ctrl+f (font)
ctrl+b (back)
ctrl+d (down)
ctrl+u (up)
dd
o
yy
p
P


磁盘管理
df
    -a
    -h
    -T
du
    
