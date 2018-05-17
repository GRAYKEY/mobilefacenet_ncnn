#include <iostream>
#include <time.h>
//#include <opencv2/opencv.hpp>
#include "net.h"
#include "mobilefacenet.h"



int main()
{
	char *model_path = "../models";
	Recognize recognize(model_path);

	cv::Mat img1 = cv::imread("../pic/Aaron_Tippin_0001.jpg", CV_LOAD_IMAGE_COLOR);
	cv::Mat img2 = cv::imread("../pic/Aaron_Peirsol_0004.jpg", CV_LOAD_IMAGE_COLOR);
	std::vector<float> feature1;
	std::vector<float> feature2;

	clock_t start_time = clock();
	recognize.start(img1, feature1);
	recognize.start(img2, feature2);
	double similar = calculSimilar(feature1, feature2);
	clock_t finish_time = clock();
	double total_time = (double)(finish_time - start_time) / CLOCKS_PER_SEC;

	std::cout << "time" << total_time * 1000 << "ms" << std::endl;
	std::cout << "similarity is : " << similar << std::endl;
	cv::imshow("left", img1);
	cv::imshow("right", img2);
	cv::waitKey(0);

	return 0;
}