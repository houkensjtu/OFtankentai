>OpenFOAM 探险队(原名 OpenFOAM たんけんたい)是由一名日本OpenFOAM资深用户在其博客发表的OpenFOAM源代码探索系列教程。
>
>原作可以在[这里](http://www.geocities.jp/penguinitis2002/study/OpenFOAM/tankentai/)找到。
>
>原作:Yuu Kasuga (penguinitis2002@yahoo.co.jp)
>
>翻译:houkensjtu (houkensjtu@gmail.com)

作者序:

为了潜入 OpenFOAM 源代码茂密的丛林深处,我们组织了这支探险队。以下是活动报告。

第一期 最小 OpenFOAM 程序
-----------------
##目的:

作为学习 OpenFOAM 编程的第一步,让我们学习一下如何制作一个最小的 OpenFOAM 程序吧。

##使用版本:

OpenFOAM 1.6(译者注:译者用 2.1.x 版也大都能够编译通过并成功运行)

##程序说明:

参照 OpenFOAM 原有 solver 的目录安排方式,需要首先制作一个容纳自己程序源代码的目录。下载并解压 01-mini.tar.gz即可。(译者注:如何解压以及目录的基本概念需自行学习 linux基础)

解压后目录下有如下文件:
```
Make/files
Make/options
mini.C
```
Make 文件夹下的 files 和 options 是 wmake 编辑源代码所需的文件。(译者注:wmake 用

法类似于 gnu make,此处需先行学习 make 的基本概念)
```
Make/files
mini.C
EXE = mini
```
files 文件中第一行指明了需要编译的代码文件名,第二行指定了编译后产生的可执行文件名。

由于没有指定特殊的路径,此处 wmake 产生的可执行文件将位于当前目录下。
```
Make/options
EXE_INC = -I$(LIB_SRC)/finiteVolume/lnInclude
EXE_LIBS = -lfiniteVolume
```
options 文件中的"EXE_INC = -I..."指明了头文件的搜索路径,相应的,"EXE_LIBS = -l..."指

明了链接的 library 的位置。根据所编程序的需要功能,可能会需要更多的头文件和 library,

这里列出的,是 OpenFOAM 程序最低限度的需求文件。

mini.C 就是这次制作的最小程序了。严密的说,“最小”程序,应该是一个什么内容都没有的

程序,但是那样的话就没有任何学习意义了,所以我们选择在程序中输出一些语句。

```c
#include "fvCFD.H"

int main(int argc, char *argv[])
{
Info << "minimum OpenFOAM program" << endl;
return 0;
}
```
这里 fvCFD.H 貌似是一个 OpenFOAM 基础的必须的头文件。Info 则是 OpenFOAM 自有的,

类似于 c++中 cout 的标准输出流的一个语句。

##编译与执行:

在代码目录下(不要进到 Make 目录里),执行 wmake 即可编译。如果没有问题的话,当前

目录下会产生一个叫做 mini 的文件,执行试试看吧~

`$ wmake`

`$ ./mini`

执行以后,应该会在终端显示出一行"minimum OpenFOAM program"的字样。

这样我们就完成了第一个最简单的自编 OpenFOAM 程序。
