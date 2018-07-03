# ISS-3D-keypoints
Some working example of keypoint detection algorithm using Point Cloud Library (PCL).

ISSKeypoint3D detects the Intrinsic Shape Signatures keypoints for a given point cloud.
This class is based on a particular implementation made by Federico Tombari and Samuele Salti and it has been explicitly adapted to PCL.

Just download .cpp file and CMakeLists.txt and build .exe file. 

Parameters in algoritm are set for resolution 0.004f, so if you have higher resolution feel free to put higher values for iss_detector.setSalientRadius and iss_detector.setNonMaxRadius, also might you'll need change the other parameters for correct result.

![Blue points are ISS-3D keypoints](https://i.imgur.com/xzk97Tr.jpg)


      
