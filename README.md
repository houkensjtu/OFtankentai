OFtankentai
===========

## :herb:Openfoam探险队教程中文翻译

>OpenFOAM 探险队(原名 OpenFOAM たんけんたい)是由一名日本OpenFOAM资深用户在其博客发表的OpenFOAM源代码探索系列教程。
>
>原作可以在[这里](http://www.geocities.jp/penguinitis2002/study/OpenFOAM/tankentai/)找到。
>
>原作:Yuu Kasuga (penguinitis2002@yahoo.co.jp)
>
>翻译:houkensjtu (houkensjtu@gmail.com)

作者序:

为了潜入 OpenFOAM 源代码茂密的丛林深处,我们组织了这支探险队。以下是活动报告。

[第一期 最小OpenFOAM程序](./articles/第1期最小OpenFOAM程序.md)  
[第二期 参数列表](./articles/第2期参数列表.md)  
[第三期 时间类](./articles/第3期时间类.md)  

## :palm_tree:番外篇：ハードボイルドの森

(以下内容为翻译者原创)


村上ハルヒ「ただのノーベル文学賞には興味ありません！」  
ながもん「情報四面体によって造られた対有機化合物コンパクト用ヒューマンインターネットフェイス、それが、私」  
正直言おう・・・、俺はこいつらが何を言ってるのかさっぱりわからなかった。  

[Case1 : Laminar flow in a 2D axis-symmetric channel](./validations/Axis_Hagen/readme.md)   
[Case2 : Intro to Turbulent flow](./validations/Axis_Turb/readme.md)


## :seedling:裏番組：Evan P. Sheehan的PhD论文

### 1. Introduction
- 对流式换热器在低温系统中被广泛应用（Recuperative heat exchangers，不同于回热式换热器regenerative heat exchangers）。提高换热器性能可以降低低温端
温度，或者减少系统所需要的制冷量。
### 2. Specification
- 换热器设计的要求如下，最重要的是效率超过99%（可是效率的定义是？）
<img src="./images/Evan/spec.png" width = 450px>

### 3. Literature review

#### 3.1. The Importance of High Cryogenic Heat Exchanger Effectiveness
- 由于低温制冷机的制冷量往往非常有限，而热交换器承受的热交换量则相对庞大，交换器效率的损失对冷端的负荷的影响往往非常巨大。
- 在下图的模型中，如果热交换器效率为100%，则正好从换热器流出和流入的enthalpy一致，**系统所需制冷量=磁体的漏热。**
<img src="./images/Evan/htsmodel.png" width = 650px>

- 如果热交换器效率小于1，**非效率分就会成为制冷系统的负荷**
- 例子的系统中，热交换器效率约为90%，剩下的部分就成为额外负荷（约67W），加上磁体本身的发热和漏热90W，共需要制冷量157W。可以看到非效率
  增加了很大一部分制冷负荷。

#### 3.2. Typical Compact Heat Exchanger Designs
##### 3.2.1. Parallel Plates: Inline Strip-Fins
- 理论上这种形式的换热器单位体积的换热面积最大，但是实际由于流量存在分布不均，所以效率往往停止在99%以下。
- Marquardt and Radebaugh的研究论文表示，要实现99%以上的效率，流量分布不均必须在2%以下。
<img src="./images/Evan/pphx.png" width = 450px>


##### 3.2.2. Parallel Plates: Offset Strip-Fins
- 与上面的形式基本相同，只是翅片不再是一长条到底，而是相互错开的形状，可以解决部分流量不均匀问题（因为流路之间都是互相通的），也可以破坏边界层促进热交换。
- 与上面的形式相同的是，轴向热传导都会造成一定的损失。

<img src="./images/Evan/ospphx.png" width = 450px>


##### 3.2.3. Stacked Staggered Perforated Plates
