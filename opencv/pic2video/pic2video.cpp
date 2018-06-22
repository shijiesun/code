#include <opencv2/opencv.hpp>
#include <cstdio>
#include <string>

using namespace cv;

int main(int argc, char * argv[])
{
    if(argc < 4) {
        std::cerr << "usage:" << argv[0] << " imagespath fps videoname" << std::endl;
        return 1;
    }
    std::string imagespath = argv[1];
    int fps = std::stoi(argv[2]);
    std::string videoname = std::string(argv[3]) + ".avi";

    //【1】输出视频
    VideoWriter writer(videoname.c_str(), VideoWriter::fourcc('M', 'J', 'P', 'G'), fps, Size(1280, 720)); //此处的尺寸针对不同的视频需要调整
    //【2】循环显示每一帧
    int i = 1;
    char name[30];
//  Mat frame;//定义一个Mat变量，用于存储每一帧的图像
    while(1)
    {
        std::string path = imagespath + "/image-%05d.jpeg";
        sprintf(name, path.c_str(), i);//注意：图片名称依次是0000001.jpg,00000002.jpg.....； 在linux下，路径中'\\'替换为'/'
        std::cout << name << std::endl;
        Mat frame = imread(name);
        i++;
        //若视频播放完成，退出循环
        if (frame.empty())
        {
            break;
        }
        imshow("output", frame);
        writer << frame;
        waitKey(30);
    }
    return 0;
}
