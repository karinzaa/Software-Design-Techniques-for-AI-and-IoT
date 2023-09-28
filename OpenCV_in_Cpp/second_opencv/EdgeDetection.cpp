#include "opencv2/core/utility.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <stdio.h>
using namespace cv;
using namespace std;
int edgeThresh = 1;
int edgeThreshScharr=1;
Mat image, gray, blurImage, edge1, edge2, cedge;
const char* window_name1 = "Edge map : Canny default (Sobel gradient)";
const char* window_name2 = "Edge map : Canny with custom gradient (Scharr)";
// define a trackbar callback
static void onTrackbar(int, void*)
{
    blur(gray, blurImage, Size(3,3));
    // Run the edge detector on grayscale
    Canny(blurImage, edge1, edgeThresh, edgeThresh*3, 3);
    cedge = Scalar::all(0);
    image.copyTo(cedge, edge1);
    imshow(window_name1, cedge);
    Mat dx,dy;
    Scharr(blurImage,dx,CV_16S,1,0);
    Scharr(blurImage,dy,CV_16S,0,1);
    Canny( dx,dy, edge2, edgeThreshScharr, edgeThreshScharr*3 );
    cedge = Scalar::all(0);
    image.copyTo(cedge, edge2);
    imshow(window_name2, cedge);
}
static void help(const char** argv)
{
    printf("\nThis sample demonstrates Canny edge detection\n"
           "Call: "
           "    %s [image_name]\n\n", argv[1]);
}
const char* keys =
{
    "{help h||}{@image |fruits.jpg|input image name}"
};
int main( int argc, const char** argv )
{
    help(argv);
    CommandLineParser parser(argc, argv, keys);
    string filename = parser.get<string>(0);
    Mat image;
    Mat gray;
    Mat edge;
    image = imread( argv[1], 1 );
    if(image.empty())
    {
        printf("Cannot read image file: %s\n", filename.c_str());
        help(argv);
        return -1;
    }

    cvtColor(image, gray, COLOR_BGR2GRAY);
    Canny(gray,edge,10,350);
    namedWindow("Input");
    imshow("Input",image);
    namedWindow("Gray");
    imshow("Gray",gray);
    namedWindow("Canny Edge");
    imshow("Canny Edge",edge);    
    // Wait for a key stroke; the same function arranges events processing
    waitKey(0);
    return 0;
}

