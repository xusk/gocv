#ifndef _OPENCV3_FAST_LINE_DETECTOR_H_
#define _OPENCV3_FAST_LINE_DETECTOR_H_

#ifdef __cplusplus
#include <opencv2/opencv.hpp>
#include <opencv2/ximgproc.hpp>

extern "C" {
#endif

#include "../core.h"

#ifdef __cplusplus
typedef cv::Ptr<cv::ximgproc::FastLineDetector>* FastLineDetectorPtr;
#else
typedef void* FastLineDetectorPtr;
#endif

FastLineDetectorPtr FastLineDetector_Create();
void FastLineDetector_Detect(FastLineDetectorPtr dr, Mat image, Vecs4f* lines_in);

#ifdef __cplusplus
}
#endif

#endif //_OPENCV3_FAST_LINE_DETECTOR_H_
