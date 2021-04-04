#include "camerathreads.h"

CameraThreads::CameraThreads(QWidget *parent) : QThread(parent){


}

void CameraThreads::run(){
    for(int i=0; i<11000; i++){
        emit NumberChange(i);
    }
}

void CameraThreads::NumberChange(int number){

}
