#include <stdio.h>
#include <tins/tins.h>
#include <thread>

using namespace Tins;
using namespace std;
void * func(void * ssid)
{

        PacketSender sender;
        Dot11Beacon beacon;
        RadioTap radio;

        beacon.addr1(Dot11::BROADCAST);
        beacon.addr2("00:01:02:03:04:05");
        beacon.addr3(beacon.addr2());

        beacon.ssid((char *)ssid);
        beacon.ds_parameter_set(8);
        beacon.supported_rates({ 1.0f, 5.5f, 11.0f });

        radio = RadioTap() / beacon;

        beacon.rsn_information(RSNInformation::wpa2_psk());

        while(1)
        {
                sender.send(radio,"mon0");
        }
}



int main(void)
{
        pthread_t t1;
        pthread_t t2;
        pthread_t t3;
        int thr_id;
        int status;
        thr_id = pthread_create(&t1, NULL, func, (void *)"mansae");
        thr_id = pthread_create(&t2, NULL, func, (void *)"Best of the Best");
        thr_id = pthread_create(&t2, NULL, func, (void *)"veronica");
        pthread_join(t1,(void **)&status);
        pthread_join(t2,(void **)&status);
        pthread_join(t3,(void **)&status);
        return 0;
}
