

1. 源码 https://github.com/Charleswyt/tf_audio_steganalysis 但是是TF实现的

2. [数据集](https://pan.baidu.com/s/1rYCzJRksHkgbOOYI9MqQjA#list/path=%2F&parentPath=%2Fsharelink1872361657-935514907529823)


我 128×1024

目标 200 × 380
现在（200 × 576）

对于立体声音频，一帧是两个颗粒，而每个颗粒有两个声道。
所以一个音频的通道数200 = 50(帧数)*2(颗粒数)*2(声道数)
每个通道是576个样本点。所以一个音频的尺寸是（200 × 576）。
每个通道中靠近末尾位置很多值为0的qmdct系数。
而本隐写分析网络针对的是AHCM、EECS这类隐写算法，隐写样本中值为0的qmdct没有改变。所以，为了降低计算复杂度，放大cover和stego之间的区别，本隐写分析网络输入尺寸采取[200 × 380]，即仅分析每个通道的前380个非0系数（380是经验值）。

如
lame_qmdct.exe   cover_128.mp3  -framenum 50 -startind 0 -coeffnum 576 --decode
lame_qmdct.exe   ..\audio_samples\mp3\cover_128.mp3  -framenum 50 -startind 0 -coeffnum 576 --decode
