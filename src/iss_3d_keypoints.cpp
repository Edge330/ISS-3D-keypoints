#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/common/io.h>
#include <pcl/keypoints/iss_3d.h>
#include <pcl/features/normal_3d.h>
#include <pcl/visualization/pcl_visualizer.h>


int
main(int, char** argv)
{

pcl::PointCloud<pcl::PointXYZRGBA>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZRGBA>);

if (pcl::io::loadPCDFile<pcl::PointXYZRGBA>(argv[1], *cloud) == -1) // load the file
{
	pcl::console::print_error("Couldn't read file %s!\n", argv[1]);
	return (-1);
}
  std::cout << "points: " << cloud->points.size () <<std::endl;

 
pcl::ISSKeypoint3D<pcl::PointXYZRGBA, pcl::PointXYZRGB> iss_detector;
     
      pcl::PointCloud<pcl::PointXYZRGB>::Ptr keypoints (new pcl::PointCloud<pcl::PointXYZRGB> ());
      pcl::search::KdTree<pcl::PointXYZRGBA>::Ptr tree (new pcl::search::KdTree<pcl::PointXYZRGBA> ());
          
      
      iss_detector.setSearchMethod (tree);
      iss_detector.setSalientRadius (0.007f); 
      iss_detector.setNonMaxRadius (0.005f);  
      iss_detector.setThreshold21 (0.65); //for resolution 0.004f
      iss_detector.setThreshold32 (0.1);  //for resolution 0.004f
      iss_detector.setMinNeighbors (4); //for resolution 0.004f
      iss_detector.setNumberOfThreads (4); //for resolution 0.004f
      iss_detector.setInputCloud (cloud); //
      iss_detector.compute (*keypoints); //


   std::cout << "N of ISS_3D points in the result are " << (*keypoints).points.size () << std::endl;
   pcl::io::savePCDFile("keypoints_iss_3d.pcd", *keypoints, true);

   pcl::visualization::PCLVisualizer viewer("ISS 3D");
   viewer.addPointCloud(cloud, "scene");
   viewer.setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 2, "scene");


   pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZRGB> keypoints_color_handler(keypoints, 0, 0, 255);
   viewer.addPointCloud(keypoints, keypoints_color_handler, "scene_keypoints");
   viewer.setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 4, "scene_keypoints");

   while (!viewer.wasStopped())
   {
	   viewer.spinOnce();
   }

  return 0;
  
}