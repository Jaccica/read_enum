// test_enum.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

enum {
	ALARM_EVENT_MD = 1 << 0,
	ALARM_EVENT_ETH_LOST = 1 << 1,
	ALARM_EVENT_AUDIO_IN = 1 << 2,
	ALARM_EVENT_GIO_IN = 1 << 3,
	ALARM_EVENT_IP_CONFLICT = 1 << 4,
	ALARM_EVENT_SD_FULL = 1 << 5,
	ALARM_EVENT_COVER = 1 << 6,
	ALARM_EVENT_MOTION_DETECT = 1 << 7,
};

int main()
{
	int sem_value;
	int status = ALARM_EVENT_ETH_LOST | ALARM_EVENT_MD | ALARM_EVENT_COVER | ALARM_EVENT_MOTION_DETECT;
	for (int event_num = 1; event_num <= 128; )
	{
		//sem_value = (status >> event_num) & 1;
		sem_value = status & event_num;
		if (sem_value == ALARM_EVENT_MD)
		{
			cout << "1" << endl;
		}
		else if (sem_value == ALARM_EVENT_ETH_LOST)
		{
			cout << "2" << endl;
		}
		else if (sem_value == ALARM_EVENT_AUDIO_IN)
		{
			cout << "4" << endl;
		}
		else if (sem_value == ALARM_EVENT_GIO_IN)
		{
			cout << "8" << endl;
		}
		else if (sem_value == ALARM_EVENT_IP_CONFLICT)
		{
			cout << "16" << endl;
		}
		else if (sem_value == ALARM_EVENT_SD_FULL)
		{
			cout << "32" << endl;
		}
		else if (sem_value == ALARM_EVENT_COVER)
		{
			cout << "64" << endl;
		}
		else if (sem_value == ALARM_EVENT_MOTION_DETECT)
		{
			cout << "128" << endl;
		}
		event_num *= 2;
	}
	return 0;
}


