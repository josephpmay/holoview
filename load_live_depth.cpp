#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/openni_grabber.h>
#include <pcl/io/openni_camera/openni_driver.h>

class LiveDepth {


};

void LiveDepth::grab_data()
{
  pcl::Grabber* interface = new pcl::OpenNIGrabber();

  boost::function<void(const boost::shared_ptr<openni_wrapper::DepthImage>&) f= 
    boost::bind (&SampleOpenNiViewer::cloud_cb_, this, _1)
}


int
main()
{

}
