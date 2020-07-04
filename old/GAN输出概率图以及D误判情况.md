

`0.04379_1.5e-10 interpolate+loss2`

### 反卷积换成插值+卷积
1. `0.06572_2e-10_interpolate_multimap_loss2`
**进步的一点**
> 19 epoch以后 实现了误判(即生成的stego都被判为cover) 此时概率图还看起来很好 没黑
但是：
> 40多epoch时候概率图黑掉了
> D和G的loss曲线都太平了
2. `0.06572_2e-10_interpolate_loss2`(**值得继续**)  10 30 60 **70** 80
> 1-150 epoch 概率图一直没有坏
> 曲线互动还可以
但是：
> 没有达到误判 30 epoch时就全部判为stego(毕竟不是实际STC隐写样本 故这个结果只是一个参考)

-------------------------------------------------------------------------

> python3 test_model.py  
  -ckp logging/0.06572_2e-10_clip/checkpoints/checkpoint_of_epoch_150.pyt 
  -tf load_model/4000_cover 
  -rf load_model
>load_model下的文件                                                     
    4000_cover  pro  proimages  stegoimages



>命名：multimap和loss缺省情况下，是原始Unet结构、新的loss2
### logging的4+3个结果
    3. 0.06572_2e-10_multimap_clip(比2多一个multimap)
    23epoch左右概率图坏掉 最后变黑(自然达到误判目标)

    2. 0.06572_2e-10_clip(比1多一个clip控制) `选择这个ckpt`
    概率图很黑(150 epoch以后)
    判别整体偏向stego

    1. 0.06572_2e-10
    概率图40epoch之前看起来正常 100之后不正常
    最后都被判断为stego  (93 epoch 16:0)
    ---
    0.06572_2e-10_multimap(延长了误判的时间)(可以继续改)
    概率图40epoch之前看起来正常 79坏掉了
    有一段时期cover/stego对半 多数判断为stego(150 epoch 15:1)
    ---
    0.06572_2e-10_multimap_loss1
    概率图 整体很黑
    最后都被判断为cover
    ---
    0.06572_2e-10_loss1
    概率图 整体很黑
    最后都被判断为cover

    >结论：multimap延长了误判的时间，loss1让总体很黑。
    >clip使得D和G有互动



3. 生成器更新规则慢，判别器更新规则`快`。
2. 使用新的loss
1. 使用原始paper里的capacity-loss
>0.35 对应权重10-8(具体忘了)
判别器0.5 0.5了 loss不怎么下降了 但是概率图看上去改动太小。
qiu 0.2 10-9



### 知识积累
CNN建模的有效上下文是有限的--> RNN
与HMM区别：可表示状态的数量呈指数增长，而训练或推理时间最多只以二次增长。
LSTM：解决RNN中梯度消失/爆炸问题,减轻短期记忆(见动图)的影响.
![RNN短期记忆](D:/9-课程/高级人工智能/作业/RNN动图.webp)

phase建模：分析过程可能需要，合成过程必须需要。
可以使用Griffin-Lim算法从幅度谱中估计phase。但是估计的不够精确，不足以合成高质量音频。

批标准化（Batch Normalization、BN）-->使得数据变成标准正态分布(均值为0方差为1)
这种表示会对模型的收敛有帮助，但是也可能破坏已经学习到的特征。所以改进后的BN如下：(torch.nn已经解决了这个问题)
$y = \frac{x - \mathrm{E}[x]}{ \sqrt{\mathrm{Var}[x] + \epsilon}} * \gamma + \beta$

