#include <net/derand_ops.h>

#if DERAND_ENABLE
/* default function for create recorder */
static void recorder_create_default(struct sock* sk){
	return;
}

/* default function for destruct recorder */
static void recorder_destruct_default(struct sock* sk){
	return;
}

/* default function for new tcp_sendmsg */
static u32 new_sendmsg_default(struct sock *sk, struct msghdr *msg, size_t size){
	return 0;
}

/* default function for new tcp_sendpage */
static u32 new_sendpage_default(struct sock *sk, int offset, size_t size, int flags){
	return 0;
}

/* default function for new tcp_recvmsg */
static u32 new_recvmsg_default(struct sock *sk, struct msghdr *msg, size_t len, int nonblock, int flags, int *addr_len){
	return 0;
}

/* default function for sockcall_lock */
static void sockcall_lock_default(struct sock *sk, u32 sc_id){
	return;
}

/* default function for incoming_pkt */
static void incoming_pkt_default(struct sock *sk){
	return;
}

/* default function for write_timer */
static void write_timer_default(struct sock *sk){
	return;
}

/* default function for delack_timer */
static void delack_timer_default(struct sock* sk){
	return;
}

/* default function for keepalive_timer */
static void keepalive_timer_default(struct sock *sk){
	return;
}

/* default function for tasklet */
void tasklet_default(struct sock *sk){
	return;
}

/* Default operations.
 * All do nothing */
struct derand_record_ops derand_record_ops_default = {
	.server_recorder_create = recorder_create_default,
	.client_recorder_create = recorder_create_default,
	.recorder_destruct = recorder_destruct_default,
	.new_sendmsg = new_sendmsg_default,
	.new_sendpage = new_sendpage_default,
	.new_recvmsg = new_recvmsg_default,
	.sockcall_lock = sockcall_lock_default,
	.incoming_pkt = incoming_pkt_default,
	.write_timer = write_timer_default,
	.delack_timer = delack_timer_default,
	.keepalive_timer = keepalive_timer_default,
	.tasklet = tasklet_default,
	.read_jiffies = NULL,
	.read_tcp_time_stamp = NULL,
	.tcp_under_memory_pressure = NULL,
	.sk_under_memory_pressure = NULL,
	.sk_memory_allocated = NULL,
	.sk_sockets_allocated_read_positive = NULL,
	.skb_mstamp_get = NULL,
};
EXPORT_SYMBOL(derand_record_ops_default);

/* The operations that are used during runtime.
 * By default use default functions (do nothing), 
 * but DERAND kernel module can change it to concrete derand operations */
struct derand_record_ops derand_record_ops = {
	.server_recorder_create = recorder_create_default,
	.client_recorder_create = recorder_create_default,
	.recorder_destruct = recorder_destruct_default,
	.new_sendmsg = new_sendmsg_default,
	.new_sendpage = new_sendpage_default,
	.new_recvmsg = new_recvmsg_default,
	.sockcall_lock = sockcall_lock_default,
	.incoming_pkt = incoming_pkt_default,
	.write_timer = write_timer_default,
	.delack_timer = delack_timer_default,
	.keepalive_timer = keepalive_timer_default,
	.tasklet = tasklet_default,
	.read_jiffies = NULL,
	.read_tcp_time_stamp = NULL,
	.tcp_under_memory_pressure = NULL,
	.sk_under_memory_pressure = NULL,
	.sk_memory_allocated = NULL,
	.sk_sockets_allocated_read_positive = NULL,
	.skb_mstamp_get = NULL,
};
EXPORT_SYMBOL(derand_record_ops);

void (*derand_record_effect_bool)(const struct sock *sk, int loc, bool v) = NULL;
EXPORT_SYMBOL(derand_record_effect_bool);

#endif /* DERAND_ENABLE */