
#include <jni.h>
#include "ndk_log.h"

#include <pcap.h>

/* default snap length (maximum bytes per packet to capture) */
#define SNAP_LEN 65535 //1518


#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT void JNICALL Java_com_mtzijin_androidtcpdumpsdk_TcpDumpInterface_cinit
  (JNIEnv * evn, jobject obj)
{
	log_t(TAG_NETWORK, "Enter cinit");
}


JNIEXPORT void JNICALL Java_com_mtzijin_androidtcpdumpsdk_TcpDumpInterface_cstart
  (JNIEnv * evn, jobject obj)
{
	log_t(TAG_NETWORK, "Enter cstart");
	do{
		const char *dev = "wlan0";			/* capture device name */
		char errbuf[PCAP_ERRBUF_SIZE];		/* error buffer */
		pcap_t *handle;				/* packet capture handle */
		
		const char * filter_exp = "host 192.168.17.151 and port 18600";		/* filter expression [3] */
		struct bpf_program fp;			/* compiled filter program (expression) */
		bpf_u_int32 mask;			/* subnet mask */
		bpf_u_int32 net;			/* ip */
		int num_packets = -1;
	
		/* find a capture device */
//		dev = pcap_lookupdev(errbuf);
//		if (dev == NULL) {
//			log_w(TAG_NETWORK, "Couldn't find default device: %s",errbuf);
//			break;
//		}
		log_d(TAG_NETWORK, "dev: %s",dev);

		/* get network number and mask associated with capture device */
		if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
			log_w(TAG_NETWORK, "Couldn't get netmask for device %s: %s", dev, errbuf);
			net = 0;
			mask = 0;
			break;
		}
		
		log_d(TAG_NETWORK, "Number of packets: %d", num_packets);
		log_d(TAG_NETWORK, "Filter expression: %s", filter_exp);

		/* open capture device */
		handle = pcap_open_live(dev, SNAP_LEN, 1, 1000, errbuf);
		if (handle == NULL) {
			log_w(TAG_NETWORK, "Couldn't open device %s: %s", dev, errbuf);
			break;
		}
		
		/* make sure we're capturing on an Ethernet device [2] */
		if (pcap_datalink(handle) != DLT_EN10MB) {
			log_w(TAG_NETWORK, "%s is not an Ethernet", dev);
			break;
		}

		/* compile the filter expression */
		if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
			log_w(TAG_NETWORK, "Couldn't parse filter %s: %s",filter_exp, pcap_geterr(handle));
			break;
		}

		/* apply the compiled filter */
		if (pcap_setfilter(handle, &fp) == -1) {
			log_w(TAG_NETWORK, "Couldn't install filter %s: %s", filter_exp, pcap_geterr(handle));
			break;
		}
	
		log_i(TAG_NETWORK, "Before pcap_loop.");
		/* now we can set our callback function */
		//pcap_loop(handle, num_packets, got_packet, (u_char*)&count);

		/* cleanup */
		pcap_freecode(&fp);
		pcap_close(handle);

		log_i(TAG_NETWORK, "Capture complete.");
	}while(0);
}

JNIEXPORT void JNICALL Java_com_mtzijin_androidtcpdumpsdk_TcpDumpInterface_cfinal
  (JNIEnv * evn, jobject obj)
{
	log_t(TAG_NETWORK, "Enter cfinal");
}


#ifdef __cplusplus
}
#endif

