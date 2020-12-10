// This file is part of OpenCV project.
// It is subject to the license terms in the LICENSE file found in the top-level directory
// of this distribution and at http://opencv.org/license.html.

#include "fast_line_detector.h"
#include <vector>
#include <iostream>
/////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////

FastLineDetectorPtr FastLineDetector_Create() {
    return new cv::Ptr<cv::ximgproc::FastLineDetector>(cv::ximgproc::createFastLineDetector());
}

void FastLineDetector_Detect(FastLineDetectorPtr dr, Mat image, Vecs4f *lines_in) {

    std::vector<cv::Vec4f> lines_fld;
    (*dr)->detect(*image, lines_fld);
    if (lines_fld.empty()) {
        return;
    }
    //TODO release memory
    lines_in->vecs = new ::Vec4f[lines_fld.size()];
    lines_in->length = lines_fld.size();
    for(int i = 0; i < lines_fld.size(); i++) {
        lines_in->vecs[i].x1 = lines_fld[i][0];
        lines_in->vecs[i].y1 = lines_fld[i][1];
        lines_in->vecs[i].x2 = lines_fld[i][2];
        lines_in->vecs[i].y2 = lines_fld[i][3];
    }
}
