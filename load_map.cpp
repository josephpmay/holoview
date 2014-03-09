#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <string>
#include <pcl/keypoints/sift_keypoint.h>

class RoomMap {
  void load_map (const std::string&);
  void extract_normal_features(const pcl::PointCloud<pcl::PointXYZRGB& cloudInput);
  void extract_feature_keypoints(cl::PointCloud<pcl::PointXYZRGB>::Ptr &points,
                                          float min_scale, int nr_octaves,
                                          int nr_scales_per_octave,float min_contrast,
                                          pcl::PointCloud<pcl::PointWithScale>::Ptr &keypoints_out);
};


void RoomMap::load_map (const std::string& fileName)
{
  pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZRGB>);
  if (pcl::io::loadPCDFfile<pcl::PointXYZRGB> (fileName, *cloud) == -1) //* loads the file
    {
      PCL_ERROR ("Couldn't read map file \n");
      return (-1);
    }
    std::cout << "Loaded "
              << cloud->width * cloud->height
              <<" data points from map.pcd with the following fields: "
              << std::endl;
    for (size_t i =0; i< cloud->points.size (); ++i)
      std::cout << "  "<< cloud->points[i].x
                << " " << cloud->points[i].y
                << " " << cloud->points[i].z <<std::endl;
}

void RoomMap::extract_normal_features(const pcl::PointCloud<pcl::PointXYZRGB& cloudInput)
{
  pcl::NormalEstimation<pcl::PointXYZRGB, pcl::Normal> ne;
  ne.setInputCloud (cloudInput);

  pcl::search::KdTree<pcl::PointXYZRGB>::Ptr tree (new pcl::search::KdTree<pcl::PointXYZRGB> ());
  ne.setSearchMethod (tree);

  pcl::PointCloud<pcl::Normal>::Ptr cloud_normals (new pcl::PointCloud<pcl::Normal>);

  ne.compute (*cloud_normals);
}

void RoomMap::extract_feature_keypoints(pcl::PointCloud<pcl::PointXYZRGB>::Ptr &points,
                                        float min_scale, int nr_octaves,
                                        int nr_scales_per_octave,float min_contrast,
                                        pcl::PointCloud<pcl::PointWithScale>::Ptr &keypoints_out)
{
  pcl::SIFTKeypoint<pcl::PointXYZRGB, pcl::PointWithScale> sift_detect;

  //Use a FLANN-based KdTree to perform neighborhood searches
  sift_detect.setSearchMethod (pcl::search::KdTree<pcl::PointXYZRGB>::Ptr
                                (new pcl::search::KdTree<pcl::PointXYZRGY>));

  //Set the detection parameters
  sift_detect.setScales (min_scale, nr_octaves, nr_scales_per_octave);
  sift_detect.setMinimumContrast (min_contrast);

  //Set the input
  sift_detect.setInputCloud (points);

  //Detect the keypoints and store them in "keypoints_out"
  sift_detect.compute (*keypoints_out);
}

int
main ()
  {
      RoomMap livingRoom;
      livingRoom.load_map ("map.pcb");
      livingRoom.extract_normal_features(cloud);
      livingRoom.extract_feature_keypoints(cloud, .5, 8, 8, .7,
                                           pcl::PointCloud<pcl::PointWithScale>::Ptr &keypoints_out)
      return (0);
  }
