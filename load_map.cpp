#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <string>
#include <pcl/keypoints/sift_keypoint.h>

class RoomMap {
  void load_map (const std::string&);
  void extract_normal_features(const pcl::PointCloud<pcl::PointXYZ& cloudInput)
};


void RoomMap::load_map (const std::string& fileName)
{
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
  if (pcl::io::loadPCDFfile<pcl::PointXYZ> (fileName, *cloud) == -1) //* loads the file
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

void RoomMap::extract_normal_features(const pcl::PointCloud<pcl::PointXYZ& cloudInput)
{
  pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> ne;
  ne.setInputCloud (cloudInput);

  pcl::search::KdTree<pcl::PointXYZ>::Ptr tree (new pcl::search::KdTree<pcl::PointXYZ> ());
  ne.setSearchMethod (tree);

  pcl::PointCloud<pcl::Normal>::Ptr cloud_normals (new pcl::PointCloud<pcl::Normal>);

  ne.compute (*cloud_normals);
}

void RoomMap::extract_feature_keypoints()
{
  
}

int
main ()
  {
      RoomMap livingRoom;
      livingRoom.load_map ("map.pcb");
      livingRoom.extract_normal_features(cloud);
      return (0);
  }
