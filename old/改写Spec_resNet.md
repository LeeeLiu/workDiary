
[torch resnet 库 使用示例](https://blog.csdn.net/litt1e/article/details/89316705)
[dengkai's](https://github.com/LuisKay/Spec_ResNet)

kernel padding=2  [1, 1, 5, 5]
in   [4, 1, 128, 1024]
out  [4, 1, 128, 1024]


kernel: [3,3,1,4] [filter_size, filter_size, in_filters, out_filters]
in (4, 128, 1024, 1)
out (4, 128, 1024, 4)

[1,4,3,3]

### tf
全连接 [4，40]-> [4，2]
softmax ->[4,2]
CE -> [4,] ->mean -> 标量
get_acc 计算准确率

### torch
全连接：
self.fullcon2 = nn.Linear(256, 2)    [4,256] -> [4,2]  (batch_size=4)
CELoss：
D的softmax输出d_on_cover[4，2], d_target_label_cover[4] -> 标量d_loss_on_cover         

有关resnet
https://github.com/yunjey/pytorch-tutorial/blob/master/tutorials/02-intermediate/deep_residual_network/main.py

1. torch版本改写ing

torch.optim.Adam(params, lr=0.001, betas=(0.9, 0.999), eps=1e-08, weight_decay=0.0002)

共享变量
http://www.tensorfly.cn/tfdoc/how_tos/overview.html
https://blog.csdn.net/cyiano/article/details/72652482

[样本总数,256,124]
[ , 128, 1024]
