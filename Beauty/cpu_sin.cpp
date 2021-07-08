/*
int busy_time=10;
int idle_time=busy_time;

Int64 start_time=0;
while (true){
	start_time=GetTickCount();
	while ((GetTickCOunt()-start_time)<= busy_time){
		;
	}
	Sleep(idle_time);
}

C# code
static void MakeUsage(float level){
	PerformanceCounter p=new PerformanceCounter("Processor", "% Processor Time", "_Total");

	while (true){
		if (p.NextValue()>level){
			System.Threading.Thread.Sleep(10);
		}
	}
}
*/

#include "Windows.h"
#include "stdlib.h"
#include "math.h"
#include "time.h"

const double SPLIT=0.01;
const int COUNT=200;
const double PI=3.14159265;
const int INTERVAL =300;

//int _tmain(int argc, _TCHAR* argv[]){
int main(int argc, _TCHAR* argv[]){
	DWORD busySpan[COUNT];    //array of busy times
	DWORD IdleSpan[COUNT];    //array of idle times
	int half=INTERVAL/2;
	double radian=0.0;

	for (int i=0; i<COUNT; i++){
		busySpan[i]=(DWORD)(half + (sin (PI *radian)*half));
		idleSpan[i]=INTERVAL- busySpan[i];
		radian+=SPLIT;
	}
	
	DWORD startTime=0;
	int j=0;
	while (true){
		j=j%COUNT;
		startTime=GetTickCount();
		while ((GetTickCount()- startTime)<= busySpan[j]){
			;
		}
		Sleep(idleSpan[j]);
		j++;
	}
	return 0;
}

//*/
/*
#include <windows.h>
#include <math.h>
#include <time.h>

void make_cpu_usage()
{
	for (;;)
	{
		time_t t = time(NULL);
		double f = sin((double) t / 9);
		int usage = (int) ((1 + f) / 2 * CLOCKS_PER_SEC);
		clock_t clk = clock();
		while (clock() - clk < usage);  // Cost CPU
		while (time(NULL) == t)         // Relinquish
			Sleep(1);
	}
}

int main (){
	//make_cpu_usage();
	return 0;
}
*/
