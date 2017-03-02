#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cstring>

using namespace std;
class RainGauge
{
    double dRainInCm;
    char cLocation[20];
public:

    RainGauge();
    void fnReadMeasrment();
    void fnDispReading();
    friend double fnCalcAvg(RainGauge[],int);
};
RainGauge::RainGauge()
{
    dRainInCm=0.0;
    strcpy(cLocation,"\0");
}
void RainGauge::fnReadMeasrment()
{
    cout<<"enter location of the Raingauge\n";
    cin>>cLocation;
    srand(time(NULL));
    dRainInCm=((rand()%20+1000)/1000.0);
}
void RainGauge::fnDispReading()
{
    cout<<cLocation<<":"<<dRainInCm<<"cms\n";
}
double fnCalcAvg(RainGauge r[],int iNum)
{
    int i;
    double dAvgRain=0.0;
    for(i-0;i<iNum;i++)
    {
        dAvgRain +=r[i].dRainInCm;
    }
    dAvgRain/=iNum;
    return dAvgRain;
}
int main()
{
    RainGauge rainsensorArray[10];
    double dAvgRainFall;
    int i,iNum;

    cout<<"enter the no of cities\n";
    cin>>iNum;
    for(i=0;i<iNum;i++)
    {
        rainsensorArray[i].fnReadMeasrment();
    }
    cout<<"\n Rainfall Information\n";
    for(i=0;i<iNum;i++)
    {
        rainsensorArray[i].fnDispReading();
    }
    dAvgRainFall=fnCalcAvg(rainsensorArray,iNum);
    cout<<"\n Average RainFall recieved is"<<dAvgRainFall<<"cms\n";
    return 0;

}

