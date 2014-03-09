#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/openni_grabber.h>
#include <pcl/io/openni_camera/openni_driver.h>

class LiveDepth {

//class obviously isn't working currenlty
};

void LiveDepth::grab_data()
{
  pcl::Grabber* interface = new pcl::OpenNIGrabber();

  boost::function<void(const boost::shared_ptr<openni_wrapper::DepthImage>&) f=
    boost::bind (&SampleOpenNiViewer::cloud_cb_, this, _1)

  grabber_.start();

  pcl::PointCloud<pcl::PointXYZ>::Ptr viewCloud (new pcl::PointCloud<pcl::PointXYZ>);
  if (pcl::io::loadPCDFfile<pcl::PointXYZ> (fileName, *cloud) == -1) //* loads the file
    {
      PCL_ERROR ("Couldn't read map file \n");
      return (-1);
    }

//  boost::signals2::connection pcl::Grabber::registerCallback	(	const boost::function< T > & 	callback)
//  pcl::io::savePCDFileASCII ("test_pcd_here.pcd", *cloud);


    //start grabber
    //get cloud data
    //put it in data structure
    //stop grabber
}


int
main()
{

}
