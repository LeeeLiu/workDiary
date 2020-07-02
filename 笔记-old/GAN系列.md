

### GAN笔记
[李宏毅-课程笔记](http://www.gwylab.com/note-gans.html)

LSGAN：最小二乘法
>解决的问题：在之前的理论中，我们希望判别器尽可能训练到最好， 但是当𝑃𝐺与𝑃𝑑𝑎𝑡𝑎之间完全没有交集时，判别器就不能训练得太好，因为那意味着梯度消失至0，生成器无法更新。  
WGAN：Wasserstein （也称EM，EarthMover（推土距离））
>解决的问题：更好地测量𝑃𝐺与𝑃𝑑𝑎𝑡𝑎之间的 Div


auto-encoder模型具有缺点（采用模型中的解码端作为G，本质是在生成训练集已有的数据类似的数据，无法生成训练集中没有的数据），GAN就解决了这个问题。
有监督的generator：
**text c + noise**---G--->**image x**
**c and x**---D--->**scalar(0/1)**
positive example：（train，清晰火车图）
negative example：（train，模糊火车图），（cat，清晰火车图）

无监督的generator：
风格迁移（X domain -> Y domain）

generator的目标是：找一个PG，使得PG≈Pdata。
数学方法是：maximize likelihood，其实就是minimize KL divergence --> 最小化交叉熵H( p,q )
(或者其他形式的divergence)
G* = arg min_G Div(PG,Pdata)，但是PG和Pdata都是未知的。怎么办？-->
Div(PG,Pdata) -> D* = arg max_D V(D,G) -> 与JS divergence有关
V = E x~Pdata [logD(x)] + Ex~PG [log(1-D(x))] D(x)可以解出来。
这个和二分类一样。

### DCGAN
1. 生成器 分数步长卷积 上采样 升维 
2. 判别器 卷积 下采样 降维