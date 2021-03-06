
#include <iostream>
using namespace std;

#include "ophwrp.h"


// Define I/O Data File Path
#define INPUT_3D_MODEL	"TestPointCloud_WRP.ply" // 3D Point Cloud Data Base
#define INPUT_CONFIG	"TestSpecWRP.xml" // Parameters Config Specification
#define OUTPUT_BMP		"result/Result_WRP.bmp" // WRP complex field Image Output Bitmap File Name

int main(int argc, char **argv)
{
	cout << "OpenHolo Library : Generation Hologram - Wavefront Recording Plane(WRP) Example" << endl;

	ophWRP* ow=new ophWRP;

	ow->loadPointCloud(INPUT_3D_MODEL);
	ow->readConfig(INPUT_CONFIG);

	int n = 3;
	double time = ow->calculateWRP(0.5e-3);
	
	ow->encodefield();

	ow->normalize();

	ow->save(OUTPUT_BMP);

	ow->release();

	return 0;

}




