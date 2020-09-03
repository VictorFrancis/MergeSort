#include<iostream>

using namespace std;


void Merge(int Array[], int Start, int MidPoint, int End){

    int LeftArraySize=MidPoint-Start+1;
    int RightArraySize=End-MidPoint;

    int LeftArray[LeftArraySize];
    int RightArray[RightArraySize];

    for(int i=0; i<LeftArraySize; i++){
        LeftArray[i]=Array[Start+i];
    }

    for(int j=0; j<RightArraySize; j++){
        RightArray[j]=Array[MidPoint+(1+j)];
    }

    int LeftArrayIndex=0;
    int RightArrayIndex=0;
    int MergeArrayIndex=Start;

    while(LeftArrayIndex<LeftArraySize && RightArrayIndex<RightArraySize){

        if(LeftArray[LeftArrayIndex]<=RightArray[RightArrayIndex]){

            Array[MergeArrayIndex]=LeftArray[LeftArrayIndex];
            LeftArrayIndex++;
        }
        else{
            Array[MergeArrayIndex]=RightArray[RightArrayIndex];
            RightArrayIndex++;
        }

        MergeArrayIndex++;
    }

    while(LeftArrayIndex<LeftArraySize){
        Array[MergeArrayIndex]=LeftArray[LeftArrayIndex];

        LeftArrayIndex++;
        MergeArrayIndex++;

    }

    while(RightArrayIndex<RightArraySize){
        Array[MergeArrayIndex]=RightArray[RightArrayIndex];

        RightArrayIndex++;
        MergeArrayIndex++;

    }


}

void MergeSort(int Array[], int Start, int End){

    if(Start<End-1){

        int MidPoint=Start+(End-1)/2;

        MergeSort(Array,Start,MidPoint);
        MergeSort(Array,MidPoint+1,End);

        Merge(Array,Start,MidPoint,End-1);
    }

}

int main(){

    int MaxSize;

    cout<<"Enter MaxSize: "<<endl;
    cin>>MaxSize;

    int Array[MaxSize];

    for(int i=0; i<MaxSize; i++){
        cin>>Array[i];
    }

    for(int i=0; i<MaxSize; i++){
        cout<<"["<<Array[i]<<"]";
    }

    cout<<endl;

    MergeSort(Array, 0, MaxSize-1);


    for(int i=0; i<MaxSize; i++){
        cout<<"["<<Array[i]<<"]";
    }





return 0;
}
