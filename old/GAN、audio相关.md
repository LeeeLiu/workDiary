

>wave-GAN文章中，specGAN通过生成STFT值，从而生成wave。
但是音质不如waveGAN，原因是：
考虑到STFT不可逆，specGAN使用了一种semi-inverted的方法，即，使用lossy Griffin-Lim inversion (Griffin & Lim, 1984) 来预测**phase**信息。即便如此，音质还是有损失。
>GANsynth中，通过生成 STFT值+phase（或者IF）两种值，从而生成wave，音质很好。
但是，局限性是，只能生成单个pitch的音频。（除非预先知道所有的frequency、phase）

结构、loss，效果。
>Dengpan Ye: Heard More Than Heard: An Audio Steganography Method Based on GAN
思路：用GAN在speech中隐藏speech。encoder和decoder的输出都是STFT值，需要ISTFT变换成stego audio和secret audio。（竟然用了ISTFT？）
秘密信息内容：secret就是和carrier一样长度的speech音频。
网络结构：encoder、decoder、steganalyzer。
损失函数：encoder的loss有3个部分：
carrier audio和stego audio的欧几里得距离，
secret audio和extract Secret Audio的欧几里得距离，
steganalyzer的交叉熵损失。
实验效果：音质、消息提取错误率（这里对应的是secret audio和extract secret audio的MSE或者SNR）、鲁棒性、安全性。
安全性很差。
>Hide and Speak: Deep Neural Networks for Speech Steganography
speech隐藏同等长度的speech（甚至多个）
网络结构：encoder、decoder。（STFT/ISTFT有点意思）
评估：
stego的音质：语谱图c和c^的MSE，人类评估（48.2%的载密speech被识别出来）。
消息提取准确度：语谱图m和m^的MSE，人类评估可懂度（单词错误率 字母错误率 语义准确度）。
>抗隐写分析性没有提。


---
[傅里叶变换](https://zhuanlan.zhihu.com/p/19763358)
[STFT与声谱图](https://blog.csdn.net/qq_28006327/article/details/59129110)

[matlab ISTFT](https://ww2.mathworks.cn/matlabcentral/fileexchange/45577-inverse-short-time-fourier-transform-istft-with-matlab)