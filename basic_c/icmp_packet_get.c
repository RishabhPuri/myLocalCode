#include <sys/socket.h>
#include <sys/types.h>
#include <linux/in.h>
#include <linux/ipv6.h>
#include <linux/netfilter.h>
#include <libipq.h>
#include <stdio.h>

#define BUFSIZE 2048

static void die(struct ipq_handle *h)
{
	ipq_perror("passer");
	ipq_destroy_handle(h);
	exit(1);

}

int main(int argc, char **argv)
{
	int status, len_t;
	unsigned char buf[BUFSIZE];
	struct ipq_handle *h;

	h = ipq_create_handle(0, PF_INET);
	printf("handle created %d",status);
	if (!h)
		die(h);

	status = ipq_set_mode(h, IPQ_COPY_PACKET, BUFSIZE);
		printf("mode set %d",status);
	if (status < 0)
		die(h);

	do{
		len_t = ipq_read(h, buf, BUFSIZE, 0);
		printf("started reading %d",status);
		if (len_t < 0)
			die(h);

		switch (ipq_message_type(buf)) {
			case NLMSG_ERROR:
				fprintf(stderr, "Received error message %d\n",
						ipq_get_msgerr(buf));
				break;
			case IPQM_PACKET: {
				fprintf(stderr, "Received message %d\n",
						ipq_get_msgerr(buf));

						  ipq_packet_msg_t *m = ipq_get_packet(buf);

						  status = ipq_set_verdict(h, m->packet_id,
								  NF_ACCEPT, 0, NULL);
						  if (status < 0)
							  die(h);
						  break;
					  }

			default:
					  fprintf(stderr, "Unknown message type!\n");
					  break;
		}
	} while (1);

	ipq_destroy_handle(h);
	return 0;
}

