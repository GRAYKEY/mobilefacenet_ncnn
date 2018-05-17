# mobilefacenet_ncnn
A simple example implementing mobilefacenet for face recognition on ncnn. 

---
# introduction
[MobileFaceNets: Efficient CNNs for Accurate Real-time Face Verification on Mobile Devices](https://arxiv.org/abs/1804.07573) is an art-of-the-state deep learning method for face recognition. It's designed for the mobile devices. 
[ncnn](https://github.com/Tencent/ncnn) is a high-performance neural network inference computing framework optimized for mobile platforms。
This repo is a simple example implementing mobilefacenet on ncnn.

---
# environment
- vs 2015
- cmake
- ncnn
- opencv2.4.13

It is tested on windows10. the needed libraries are in 3rparty. You can replace them with yours.

---
# how to use
If you are familiar with how to build, compile and link, you just need the source code files in the src folder, model in the models folder, ncnn and opencv. You can skip all steps run it easy.

1.clone this repo.

2.If you want to use your all library, modify the CMakeLists.txt according to your environment. <br>
Or just use the library in 3rparty and not modify it.

3.run the build.bat in tools folder.it will generate vs2015 folder.

4.(if you modify in step 2 and make sure your environment right, skip this step)<br>
if you didn't change CMakeLists.txt and use my 3rparty library, copy the .dll in 3rparty/opencv/bin to vs2015 folder.

5.open the mobilefacenet_ncnn.sln in vs2015 folder. choose mobilefacenet_ncnn as the startup project. choose release x64 and compile.

---
This model used is just 98.6% on lfw. You can replace it with your excellent models.

Enjoy it!

---
# 中文
mobilefacenent在ncnn上的实现。

---
# 运行步骤
如果你熟悉如何生成、编译、链接，只需要src文件夹的源码和models文件夹的模型和ncnn、opencv库。相信你可以很容易用自己的方法运行起来。

下面步骤是对于新手而言，如何在vs2015上运行。

1、下载该仓库（废话……）
2、想用自己的库，根据自己电脑环境修改CMakeLists.txt配置。不修改就直接用我3rparty里的。
3、运行tools文件夹下的build.bat生成vs2015文件夹。
4、如果第2步没修改，那么把3rparty/opencv/bin里的.dll动态链接都复制到生成的vs2015文件夹。
5、打开vs2015文件夹里面的mobilefacenet_ncnn.sln的解决方案，在解决方案资源管理器中将mobilefacenet_ncnn设为启动项目，编译release x64。

没什么错就能运行了

---
用的模型比较烂。可以替换成自己的模型。<br>
注意用的模型是mxnet还是caffe转过来的。mxnet一般网络里减过均值并归一化过。ncnn Mat数据不需要再处理。caffe转的模型，输入数据就需要自己去减均值并归一化了<br>
这个工程主要就是踩踩坑。有些地方实现效率有点低。