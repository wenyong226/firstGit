// winPcap.cpp : 定义控制台应用程序的入口点。

#include "stdafx.h"
#define HAVE_REMOTE
#include "pcap.h"
#include "remote-ext.h"


#define PCAP_ERRBUG_SIZE 1024

#define HAVE_REMOTE
int _tmain(int argc, _TCHAR* argv[])
{
	pcap_if_t *alldevs;
	pcap_if_t *d;
	int   i = 0;
	char  errbuf[PCAP_ERRBUG_SIZE];

	if(pcap_findalldevs_ex(PCAP_SRC_IF_STRING, NULL, &alldevs, errbuf) == -1){
		fprintf(stderr, "Error in pcap_findalldevs_ex: %s \n", errbuf);
		exit(1);
	}

	for(d = alldevs; d != NULL; d = d->next){
		printf("\n%d.  %s\n", ++i, d->name);
		if(d->description)
			printf(" (%s)\n", d->description);
		else
			printf("  No description availiable\n");
	}

	if(i == 0){
		printf("\nNo interfaces found! Make sure WinPcap is installed.\n");
		return 1;
	}
	pcap_freealldevs(alldevs);

	system("pause");
	return 0;
}

