#include <iostream>
#include <cstdio>
#include <ctime>
#include <cv.h>
#include <highgui.h>
#include <unistd.h>

using namespace std;

int main () {
    int i, num;
    long int t;
    char c,l;
    float ram;
    FILE * fp = fopen ("waittime.bin", "wb+");

    cout<<"Initializing settings and gestures ...\n";

    ram = ((size_t)sysconf( _SC_PHYS_PAGES ) * (size_t)sysconf( _SC_PAGE_SIZE )) / (1024 * 1024 * 1024);
    cout<<"Testing the webcam ...\n";
    cout<<"Wait (about 5 to 10 seconds)...\n";

    c = cvWaitKey(3000);
    CvCapture* capture = cvCreateCameraCapture( 0 );
    IplImage *frames = cvQueryFrame( capture );
    i=0;
    t=time(0);
    while (true) {
        c = cvWaitKey(1);
        frames = cvQueryFrame( capture );
        if(i>=128) break;
        i++;
    }
    t=time (0)-t-1;
    //cout<<t<<endl;
    cvReleaseCapture ( &capture );

    num=(128/t)+1 ;
    cout<<"\nFrames per second set at "<<num<<" .\n\n";
    fwrite (&num, 4, 1, fp);
    fwrite (&ram, 4, 1, fp);
    fclose (fp);
    fp = fopen("gestures.bin","wb+");
    char str1[32] = "sudmalroxv";
    for(i=0; i<32; i++) {
        l = str1[i];
        fwrite(&l,1,1,fp);
    }
    fclose(fp);

    return 0;
}

