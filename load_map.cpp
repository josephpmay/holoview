#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>


class RoomMap {
  void load_map (const std::string&);
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

//void RoomMap::extract_features()
//{

//}

int
main ()
  {
      RoomMap livingRoom;
      livingRoom.load_map ("map.pcb");
      return (0);
  }
