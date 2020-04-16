

### hongyilee’s course
[HMM-李宏毅](https://www.bilibili.com/video/BV1QE411p7z3?p=5)
[HMM-统计学习方法](https://www.bilibili.com/video/BV1A7411u7zh)
[self-attention](https://www.bilibili.com/video/BV14J411W7hw?p=60)
[课件](http://speech.ee.ntu.edu.tw/~tlkagk/courses/ML_2019/Lecture/Transformer%20(v5).pdf)


### now
1. cd /dat01/liuting/proj/waveglow_qiu
   sbatch -A yzren -p gpu --gres=gpu:1   txt2wav.sh
   sbatch -A yzren -p gpu --gres=gpu:1   txt2wav_gen_cover.sh   
   sbatch -A yzren -p gpu --gres=gpu:1   txt2wav__more_data.sh

2. cd /dat01/liuting/proj/C/steganalysis
    sbatch -A yzren -p gpu --gres=gpu:1   train_steganalysis.sh

3. cd /dat01/liuting/proj/IDF/integer_discrete_flows
    `sbatch --account=yzren --partition=gpu  --gres=gpu:2  --nodes=1    --time=72:00:00  ../batch_files/bf_img64_train.sh`
4. `\squeue -A yzren`


### generate
1. 下载预训练model
cd /home/liuting/project/proj/WaveGlow/pretrained_model
wget https://api.ngc.nvidia.com/v2/models/nvidia/waveglow_ljs_256channels/versions/2/files/waveglow_256channels_ljs_v2.pt
2. 梅尔谱图
mel_spectrograms 移动至/home/liuting/project/proj/WaveGlow/mel_spectrograms
3. 生成语音
cd /home/liuting/project/proj/WaveGlow/waveglow
sbatch --account=yzren --partition=gpu  --gres=gpu:1  --nodes=1  --time=72:00:00  ../batch_files/bf_inference.sh
4. 写.sh
python3 inference.py -f <(ls ../mel_spectrograms/*.pt) -w ../pretrained_model/waveglow_256channels_ljs_v2.pt    -o ../data/gen-10-wav  --is_fp16 -s 0.6

### train
1. 下载2.6 G  LJSpeech数据集  到 `data/`
cd /home/liuting/project/proj/WaveGlow/data
wget -c https://data.keithito.com/data/speech/LJSpeech-1.1.tar.bz2
>解压：tar jxvf LJSpeech-1.1.tar.bz2

2. 把数据分为训练/测试集
cd /home/liuting/project/proj/WaveGlow/waveglow
ls ../data/LJSpeech-1.1/wavs/*.wav | tail -n+10 > ../data/train_files.txt
ls ../data/LJSpeech-1.1/wavs/*.wav | head -n10 > ../data/test_files.txt
3. 训练
cd /home/liuting/project/proj/WaveGlow/waveglow
sbatch --account=yzren --partition=gpu  --gres=gpu:1 --nodes=1  --time=72:00:00  ../batch_files/bf_train.sh
写.sh文件
python ../waveglow/distributed.py -c config.json
>对于multi-GPU，把train.py换成distributed.py
For mixed precision trainingset "fp16_run": true on config.json.

4. 测试 mel-spectrograms
cd /home/liuting/project/proj/WaveGlow/waveglow
sbatch --account=yzren --partition=gpu  --gres=gpu:1  --nodes=1  --time=72:00:00  ../batch_files/bf_test.sh
>python mel2samp.py -f ../data/test_files.txt -o . -c config.json
5. 自己训练的模型，生成
>ls  ../mel_spectrograms/*.pt > ../data/mel_files.txt
```
cd /home/liuting/project/proj/WaveGlow/waveglow
sbatch --account=yzren --partition=gpu  --gres=gpu:1  --nodes=1  --time=72:00:00  ../batch_files/bf_inference_myself.sh
```
python3 inference.py -f ../data/mel_files.txt -w ../checkpoints/waveglow_10000 -o . --is_fp16 -s 0.6



### 工作日志
1. 有code
    - 离散-语言、音乐生成：LatentNormalizingFlowsforDiscreteSequences
    https://github.com/harvardnlp/TextFlow
    - Flow++: 在离散数据上加噪声
    https://github.com/aravindsrinivas/flowpp
2. 目前没找到源码
    - piecewise-双射（只是辅助）：Real and Discrete (RAD) approach to deep mixture models
    - 用于NLP：discrete-flows:invertible-generative-models-of-discrete-data（Dinh主页有code但是404）


### 视频
[深蓝学院](https://www.shenlanxueyuan.com/login)    3.27开课
[李宏毅](https://www.bilibili.com/video/av94310884?p=2)
[李-课程主页](http://speech.ee.ntu.edu.tw/~tlkagk/courses_DLHLP20.html)
[郑瞰-语音技术](https://space.bilibili.com/414359524)
[这个废话很多。。](https://www.greedyai.com/)


### 其他
1. 文献工具：
    - Mendeley：类似endnote 免费 有Win版本
    - stork、feedemon：RSS文献追踪  有Win版本
2. follow
    1. iccv  cvpr  nips  iclr  AAAI
    2. tifs
    "Generative Model" AND flow OR reversible OR invertible OR hide OR steganography OR   discrete OR integer
3. old materials   
    - [各种卷积](https://zhuanlan.zhihu.com/p/116889239)
    - [贝叶斯与共轭](https://alexanderetz.com/2015/07/25/understanding-bayes-updating-priors-via-the-likelihood/)
    - [码农-题目分类（名称可能不完全对应）](https://zhuanlan.zhihu.com/p/104983442)