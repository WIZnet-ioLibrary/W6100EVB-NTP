#include <stdio.h>
#include "wizchip_conf.h"
#include "loopback.h"
#include "board_init.h"

#include "sntp.h"
wiz_NetInfo gWIZNETINFO = { .mac = {0x00,0x08,0xdc,0xFF,0xFF,0xFF},
							.ip = {192,168,177,25},
							.sn = {255, 255, 255, 0},
							.gw = {192, 168, 177, 1},
							.dns = {168, 126, 63, 1},
							//.dhcp = NETINFO_STATIC,
							.lla={0xfe,0x80,0x00,0x00,
									0x00,0x00, 0x00,0x00,
									0x02,0x08, 0xdc,0xff,
									0xfe,0x57, 0x57,0x25},   ///< Source Link Local Address
							.gua={0x00, 0x00, 0x00, 0x00,
									0x00, 0x00, 0x00, 0x00,
									0x00, 0x00, 0x00, 0x00,
									0x00, 0x00, 0x00, 0x00},   ///< Source Global Unicast Address
							.sn6={0xff,0xff,0xff,0xff,
									0xff,0xff,0xff,0xff,
									0x00, 0x00, 0x00, 0x00,
									0x00, 0x00, 0x00, 0x00 },   ///< IPv6 Prefix
							.gw6={0x00, 0x00, 0x00, 0x00,
									0x00, 0x00, 0x00, 0x00,
									0x00, 0x00, 0x00, 0x00,
									0x00, 0x00, 0x00, 0x00}   ///< Gateway IPv6 Address
};

wiz_NetInfo gWIZNETINFO_M = { .mac = {0x00,0x08,0xdc,0xFF,0xFF,0xFF},
							.ip = {192,168,177,25},
							.sn = {255, 255, 255, 0},
							.gw = {192, 168, 177, 1},
							.dns = {168, 126, 63, 1},
							//.dhcp = NETINFO_STATIC,
							.lla={0xfe,0x80,0x00,0x00,
									0x00,0x00, 0x00,0x00,
									0x02,0x08, 0xdc,0xff,
									0xfe,0xff, 0xff,0xff},   ///< Source Link Local Address
							.gua={0x20,0x01,0x02,0xb8,
									0x00,0x10,0x00,0x01,
									0x02,0x08,0xdc,0xff,
									0xfe,0xff,0xff,0xff},   ///< Source Global Unicast Address
							.sn6={0xff,0xff,0xff,0xff,
									0xff,0xff,0xff,0xff,
									0x00,0x00,0x00, 0x00,
									0x00,0x00,0x00,0x00 },   ///< IPv6 Prefix
							.gw6={0xfe, 0x80, 0x00,0x00,
									0x00,0x00,0x00,0x00,
									0x02,0x00, 0x87,0xff,
									0xfe,0x08, 0x4c,0x81}   ///< Gateway IPv6 Address
};
                              //DST_IP port

#define ETH_MAX_BUF_SIZE	1024
unsigned char ethBuf0[ETH_MAX_BUF_SIZE];
unsigned char ethBuf1[ETH_MAX_BUF_SIZE];
unsigned char ethBuf2[ETH_MAX_BUF_SIZE];
unsigned char ethBuf3[ETH_MAX_BUF_SIZE];
unsigned char ethBuf4[ETH_MAX_BUF_SIZE];
unsigned char ethBuf5[ETH_MAX_BUF_SIZE];
unsigned char ethBuf6[ETH_MAX_BUF_SIZE];
unsigned char ethBuf7[ETH_MAX_BUF_SIZE];



void print_network_information(void);
void print_ipv6_addr(uint8_t* name, uint8_t* ip6addr);
int main(void)
{

	uint8_t syslock = SYS_NET_LOCK;
	datetime time;
	uint8_t ntp_server[4] = {216,239,35,8}; //time.google.com
	uint8_t ntp_server6[16]= {0x20,0x01,0x48,0x60,	//time.google.com
						0x48,0x06,0x00,0x00,
						0x00,0x00,0x00,0x00,
						0x00,0x00,0x00,0x00};




	BoardInitialze();


	ctlwizchip(CW_SYS_UNLOCK,& syslock);
	ctlnetwork(CN_SET_NETINFO,&gWIZNETINFO);
	// Auto Set IPv6
		if(1 != AddressAutoConfig_Init(&gWIZNETINFO))
		{
			// Manual Set IPv6
			gWIZNETINFO = gWIZNETINFO_M;
			ctlnetwork(CN_SET_NETINFO,&gWIZNETINFO);
		}

	// Get My Address
	printf("Register value after W6100 initialize!\r\n");
	print_network_information();
	printf("\r\n=======================================\r\n");
	printf("=======================================\r\n");
	printf(">> W6100 based NTP Example\r\n");
	printf("=======================================\r\n");

	SNTP_init(ntp_server,40,ethBuf0,4);
    SNTP_init(ntp_server6,40,ethBuf1,16);


	while(1)
    {
	   	if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_8)== Bit_RESET)
			{
	    		while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_8)== Bit_RESET);

					printf("\r\n########## USer1 was released.IPv6\r\n");
						while (SNTP_run(0,&time,16,AS_IPV6) != 1);
					printf("IPv6 NTP : %d-%d-%d, %d:%d:%d\r\n", time.yy, time.mo, time.dd, time.hh, time.mm, time.ss);

			}
	    	if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1)== Bit_RESET)
	    	{
				while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1)== Bit_RESET);

					printf("\r\n########## USer0 was released. IPv4\r\n");
						while (SNTP_run(1,&time,4,AS_IPV4) != 1);
					printf("IPv4 NTP : %d-%d-%d, %d:%d:%d\r\n", time.yy, time.mo, time.dd, time.hh, time.mm, time.ss);

	    	}
	    }

}

void delay(unsigned int count)
{
	int temp;
	temp = count + TIM2_gettimer();
	while(temp > TIM2_gettimer()){}
}

void print_network_information(void)
{
	wizchip_getnetinfo(&gWIZNETINFO);

	printf("Mac address: %02x:%02x:%02x:%02x:%02x:%02x\n\r",gWIZNETINFO.mac[0],gWIZNETINFO.mac[1],gWIZNETINFO.mac[2],gWIZNETINFO.mac[3],gWIZNETINFO.mac[4],gWIZNETINFO.mac[5]);
	printf("IP address : %d.%d.%d.%d\n\r",gWIZNETINFO.ip[0],gWIZNETINFO.ip[1],gWIZNETINFO.ip[2],gWIZNETINFO.ip[3]);
	printf("SM Mask    : %d.%d.%d.%d\n\r",gWIZNETINFO.sn[0],gWIZNETINFO.sn[1],gWIZNETINFO.sn[2],gWIZNETINFO.sn[3]);
	printf("Gate way   : %d.%d.%d.%d\n\r",gWIZNETINFO.gw[0],gWIZNETINFO.gw[1],gWIZNETINFO.gw[2],gWIZNETINFO.gw[3]);
	printf("DNS Server : %d.%d.%d.%d\n\r",gWIZNETINFO.dns[0],gWIZNETINFO.dns[1],gWIZNETINFO.dns[2],gWIZNETINFO.dns[3]);

	print_ipv6_addr("GW6 ", gWIZNETINFO.gw6);
	print_ipv6_addr("LLA ", gWIZNETINFO.lla);
	print_ipv6_addr("GUA ", gWIZNETINFO.gua);
	print_ipv6_addr("SUB6", gWIZNETINFO.sn6);

	printf("\r\nNETCFGLOCK : %x\r\n", getNETLCKR());
}

void print_ipv6_addr(uint8_t* name, uint8_t* ip6addr)
{
	printf("%s : ", name);
	printf("%04X:%04X", ((uint16_t)ip6addr[0] << 8) | ((uint16_t)ip6addr[1]), ((uint16_t)ip6addr[2] << 8) | ((uint16_t)ip6addr[3]));
	printf(":%04X:%04X", ((uint16_t)ip6addr[4] << 8) | ((uint16_t)ip6addr[5]), ((uint16_t)ip6addr[6] << 8) | ((uint16_t)ip6addr[7]));
	printf(":%04X:%04X", ((uint16_t)ip6addr[8] << 8) | ((uint16_t)ip6addr[9]), ((uint16_t)ip6addr[10] << 8) | ((uint16_t)ip6addr[11]));
	printf(":%04X:%04X\r\n", ((uint16_t)ip6addr[12] << 8) | ((uint16_t)ip6addr[13]), ((uint16_t)ip6addr[14] << 8) | ((uint16_t)ip6addr[15]));
}
