


1. torch版本改写ing
x = x.float()
spec_res = x.view(-1, self.hps.feature_row, self.hps.feature_col, 1)
spec_filtered = self.fixed_conv('fixed_conv_filter', spec_res, 3, 1, self.hps.channels, [1, 1, 1, 1])

共享变量
http://www.tensorfly.cn/tfdoc/how_tos/overview.html

https://blog.csdn.net/cyiano/article/details/72652482

[样本总数,256,124]
[ , 128, 1024]
