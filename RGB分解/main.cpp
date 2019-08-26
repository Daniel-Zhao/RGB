#include<iostream>
#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	Mat orig;
	orig = imread("background.jpg");
	if (orig.empty())
		cout << "读入失败" << endl;
	imshow("宫水三叶", orig);
	vector<Mat>m;
	split(orig, m); //提取通道信息，但是当未把其他通道设置为0时显示为灰度图，但各通道信息不同
	vector<Mat>Rchannels, Gchannels, Bchannels;
	//提取通道信息，把orig的通道数据复制到channals
	split(orig, Rchannels);
	split(orig, Gchannels);
	split(orig, Bchannels);
	//将其他通道信息设置为0
	Rchannels[1] = 0;
	Rchannels[2] = 0;
	Gchannels[0] = 0;
	Gchannels[2] = 0;
	Bchannels[0] = 0;
	Bchannels[1] = 0;
	//合并通道信息
	merge(Rchannels, m[0]);
	merge(Gchannels, m[1]);
	merge(Bchannels, m[2]);
	//显示各通道信息
	imshow("Blue", m[0]);
	imshow("Green", m[1]);
	imshow("Red", m[2]);
	waitKey(0);
	return 0;
}
