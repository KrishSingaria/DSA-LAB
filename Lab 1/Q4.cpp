#include <iostream>
#include <cmath>
using namespace std;

float calculateVolume(int r,int h){
    return M_PI*h*pow(r,2);
}
float calculateSurfaceArea(int r,int h){
    return 2*M_PI*r*h + 2*M_PI*pow(r,2);
}
int main()
{
    int r,h =-1;
    while (r<0||h<0)
    {
        cout<<"Enter radius of Cylinder:";
        cin>>r;
        cout<<"Enter height of Cylinder:";
        cin>>h; 
    }
    cout<<"Volume:"<<calculateVolume(r,h)<<endl;
    cout<<"SurfaceArea:"<<calculateSurfaceArea(r,h)<<endl;
    return 0;
}