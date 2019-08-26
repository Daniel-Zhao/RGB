#include<iostream>
#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	Mat orig;
	orig = imread("background.jpg");
	if (orig.empty())
		cout << "����ʧ��" << endl;
	imshow("��ˮ��Ҷ", orig);
	vector<Mat>m;
	split(orig, m); //��ȡͨ����Ϣ�����ǵ�δ������ͨ������Ϊ0ʱ��ʾΪ�Ҷ�ͼ������ͨ����Ϣ��ͬ
	vector<Mat>Rchannels, Gchannels, Bchannels;
	//��ȡͨ����Ϣ����orig��ͨ�����ݸ��Ƶ�channals
	split(orig, Rchannels);
	split(orig, Gchannels);
	split(orig, Bchannels);
	//������ͨ����Ϣ����Ϊ0
	Rchannels[1] = 0;
	Rchannels[2] = 0;
	Gchannels[0] = 0;
	Gchannels[2] = 0;
	Bchannels[0] = 0;
	Bchannels[1] = 0;
	//�ϲ�ͨ����Ϣ
	merge(Rchannels, m[0]);
	merge(Gchannels, m[1]);
	merge(Bchannels, m[2]);
	//��ʾ��ͨ����Ϣ
	imshow("Blue", m[0]);
	imshow("Green", m[1]);
	imshow("Red", m[2]);
	waitKey(0);
	return 0;
}
