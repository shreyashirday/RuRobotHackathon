#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "decepticon/decepticon.hpp"


using namespace cv;
void traverse(Decepticon *dec);
bool matchImage(Decepticon *dec);
bool initial = false;

int main() {
  Decepticon d;
  
  

  return 0;
}



void traverse(Decepticon& dec){
  int distanceInCm = dec.get_sonar();
  int distanceInMeters = distanceInCm/100;
  double metersToFeet = distanceInMeters * 3.28;
  double metersToInches = distanceInMeters * 39.37;
  
  if(metersToFeet < 2.1){
          dec.set_left(150)
    

  }



}


double getFeet(Decepticon& dec){

return ((dec.get_sonar()/100) * 3.28);

}

double getInches(Decepticon& dec){

return ((dec.get_sonar()/100) * 39.37);

}
