
- 抗隐写分析性检测

### interpolate+loss2
>使用 logging/0.06572_2e-10_interpolate/61_150epoch/checkpoints/checkpoint_of_epoch_70.pyt 
1. 0.01827
0.574250 0.578000 0.570500
2. 0.02384
0.591750 0.672000 0.511500
3. 0.03310
0.628000 0.615000 0.641000
4. 0.04379
0.798000 0.848500 0.747500
5. 0.06572
0.767500 0.726500 0.808500


### (multimap+loss2)
> 使用模型 logging/0.06572_2e-10_multimap/2019.11.25--17-43-41/checkpoints/checkpoint_of_epoch_10.pyt 生成pro，再用pro做实际STC隐写生成stego，再把cover和stego一起放进TF-resnet检测，结果如下。
1. 0.01827
---------test_data_1.00--------
Tensorflow test_accuracy : accuracy 0.57475000
Tensorflow tp_accuracy : accuracy 0.54100000
Tensorflow tn_accuracy : accuracy 0.60850000
2. 0.02384
0.570000
0.486000
0.654000
3. 0.03310
---------test_data_1.00--------
Tensorflow test_accuracy : accuracy 0.65375000
Tensorflow tp_accuracy : accuracy 0.64500000
Tensorflow tn_accuracy : accuracy 0.66250000
4. 0.04379
---------test_data_1.00--------
Tensorflow test_accuracy : accuracy 0.70250000
Tensorflow tp_accuracy : accuracy 0.70850000
Tensorflow tn_accuracy : accuracy 0.69650000
5. 0.06572
---------test_data_1.00--------
  test_accuracy : accuracy 0.75600000
  tp_accuracy : accuracy 0.77600000
  tn_accuracy : accuracy 0.73600000



### --11.6
1. res-net
隐写容量计算方法： kbps = 取整(128×1024×α) / 1.463 s
最大可嵌容量(α=0.5) = 128×1024×0.5/1.463 s ≈ 44.7956 kbps
EECS 最大(α=1) 11.8611 kbps

容量(Kbps)	|payload α(bit per Qmdct)| 		test_acc|		tp| tn
--|:--:|:--:|:--:|--:	
1.6362 kbps(误差 + 0.8472 bps)|	α = 0.01827|0.555500	|0.633500|0.477500
2.1359 kbps(误差 + 0.1219 bps)|	α = 0.02384|0.573000	|0.669500|0.476500
2.965  kbps(误差 + 0.1401 bps)|	α = 0.03310|0.728750	|0.811000|0.646500
3.9233 kbps(误差 + 0.1450 bps)|	α = 0.04379|0.719750	|0.721500|0.718000
5.8879 kbps(误差 + 0.0016 bps)|	α = 0.06572|0.876250	|0.918000|0.834500	


2. IWDW
cover-stego 4k对，train：test ≈ 8：2。
payload(bit per Qmdct)|test_acc
--|:--:
α = 0.01827|  0.5224 (+/- 0.0044)
α = 0.02384|  0.5314 (+/- 0.0083)
α = 0.03310|  0.5491 (+/- 0.0034)
α = 0.04379|  0.5632 (+/- 0.0053)
α = 0.06572|  0.6127 (+/- 0.0072)

