
# 图灵班提交作业说明

<不要重复生成公钥，切忌修改公钥，请勿丢失公钥>

<不要重复生成公钥，切忌修改公钥，请勿丢失公钥>

<不要重复生成公钥，切忌修改公钥，请勿丢失公钥>

**重要的事情说3遍**。

----
### 1. 先-配置git信息（自报家门）
任何同学第一次使用git前，先给自己的机器配置好名字,这样你提交作业时，才知道作业的实际贡献者是谁

`$ git config --global user.name "Qingke Zhang"`

`$ git config --global user.email "tsingke@hotmail.com"`

注：只配置一次即可，后续提交作业时无须再配置

-----

### 2.后-提交作业（学会即可）
`说明1： 没有提交过作业，也就是第一次提交作业的同学，请依次执行下面的命令：`
```
1. 克隆远程作业: $ git clone git@github.com:tsingke/Homework_Turing.git 

2. 在作业文件夹里添加个人文件夹，然后在里面添加已写好的作业(程序代码+程序结果截图)

3. 切换到集体作业目录，在该目录下右键打开git bash here，接着做个远程作业同步：
   $ git pull   <同步远程作业> ，一般会很快！
 
4. $ git add .  

5. $ git commit -m "第一次提交作业"

6. $ git push origin master

```
-----

`说明2： 已完成作业提交同学，如果想修改代码请务必先执行$git pull 命令 以保持和远端仓库作业内容同步 ，具体操作过程如下`：

```
1. $ git pull

   > git pull 结束后 在本地作业目录下修改本人作业，添加源码，添加执行结果截图文件

2. $ git add .

3. $ git commit -m "modify my homework"

4. $ git push origin master

```
