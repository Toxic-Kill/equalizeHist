#include <iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	cv::Mat dstMat;
	//读取图像
	cv::Mat srcMat = cv::imread("D:\\Files\\etest.jpg");
	//检查读取成功性
	if (srcMat.empty())
	{
		std::cout << "Fail to open" << std::endl;
		return -1;
	}

	//分离三通道
	std::vector<cv::Mat>channels;
	cv::split(srcMat, channels);

	//分别进行直方图均衡
	cv::equalizeHist(channels[0], channels[0]);
	cv::equalizeHist(channels[1], channels[1]);
	cv::equalizeHist(channels[2], channels[2]);

	//合成目标图像
	cv::merge(channels, dstMat);

	//显示图像
	cv::imshow("dst", dstMat);
	waitKey(0);
}