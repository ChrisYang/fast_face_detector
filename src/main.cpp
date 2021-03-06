#include <iostream>
#include <opencv2/opencv.hpp>
#include "face_detector.h"


int main(int argc, char **argv)
{
	if(argc != 2)
	{
		std::cout << "Usage: ./" << argv[0] << "model.xml image";
		exit(-1);
	}
	
    cv::Mat image = cv::imread(argv[2]);
    ffd::detector::FFDDetector detector(argv[1], 60.);
    
    detector.process(image);
    std::vector<cv::Rect> rect = detector.getBBoxes();

    for(const auto &i : rect)
    {
        cv::rectangle(image, i, cv::Scalar(255, 0, 0), 2);
    }
    
    cv::imshow("image", image);
    cv::waitKey(0);
    return 0;
}
