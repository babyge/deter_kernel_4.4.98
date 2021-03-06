#include <net/deter_ops.h>

#if DETER_ENABLE
/* default function for create recorder */
static void recorder_create_default(struct sock* sk, struct sk_buff* skb){
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

/* default function for new tcp_splice_read */
static u32 new_splice_read_default(struct sock *sk, size_t len, unsigned int flags){
	return 0;
}

/* default function for new tcp_close */
static u32 new_close_default(struct sock *sk, long timeout){
	return 0;
}

/* default function for new setsockopt */
static u32 new_setsockopt_default(struct sock *sk, int level, int optname, char __user *optval, unsigned int optlen){
	return 0;
}

/* default function for sockcall_lock */
static void sockcall_lock_default(struct sock *sk, u32 sc_id){
	return;
}

/* default function for sockcall_before_lock */
static void sockcall_before_lock_default(struct sock *sk, u32 sc_id){
	return;
}

/* default function for incoming_pkt */
static void incoming_pkt_default(struct sock *sk){
	return;
}

/* default function for incoming_pkt_before_lock */
static void incoming_pkt_before_lock_default(struct sock *sk){
	return;
}

/* default function for write_timer */
static void write_timer_default(struct sock *sk){
	return;
}

/* default function for write_timer_before_lock */
static void write_timer_before_lock_default(struct sock *sk){
	return;
}

/* default function for delack_timer */
static void delack_timer_default(struct sock* sk){
	return;
}

/* default function for delack_timer_before_lock */
static void delack_timer_before_lock_default(struct sock* sk){
	return;
}

/* default function for keepalive_timer */
static void keepalive_timer_default(struct sock *sk){
	return;
}

/* default function for keepalive_timer_before_lock */
static void keepalive_timer_before_lock_default(struct sock *sk){
	return;
}

/* default function for tasklet */
void tasklet_default(struct sock *sk){
	return;
}

/* default function for tasklet_before_lock */
void tasklet_before_lock_default(struct sock *sk){
	return;
}

/* default function for mon_net_action */
void mon_net_action_default(struct sock *sk, struct sk_buff *skb){
	return;
}

/* default function for record_fin_seq */
void record_fin_seq_default(struct sock *sk){
	return;
}

/* default function for to_replay_server */
int to_replay_server_default(struct sock *sk){
	return 0;
}

/* default function for log */
int log_default(const struct sock *sk, const char *fmt, ...){
	return 0;
}

/* Default operations.
 * All do nothing */
struct deter_record_ops deter_record_ops_default = {
	.server_recorder_create = recorder_create_default,
	.client_recorder_create = recorder_create_default,
	.recorder_destruct = recorder_destruct_default,
	.new_sendmsg = new_sendmsg_default,
	.new_sendpage = new_sendpage_default,
	.new_recvmsg = new_recvmsg_default,
	.new_splice_read = new_splice_read_default,
	.new_close = new_close_default,
	.new_setsockopt = new_setsockopt_default,
	.sockcall_lock = sockcall_lock_default,
	.sockcall_before_lock = sockcall_before_lock_default,
	.incoming_pkt = incoming_pkt_default,
	.incoming_pkt_before_lock = incoming_pkt_before_lock_default,
	.write_timer = write_timer_default,
	.write_timer_before_lock = write_timer_before_lock_default,
	.delack_timer = delack_timer_default,
	.delack_timer_before_lock = delack_timer_before_lock_default,
	.keepalive_timer = keepalive_timer_default,
	.keepalive_timer_before_lock = keepalive_timer_before_lock_default,
	.tasklet = tasklet_default,
	.tasklet_before_lock = tasklet_before_lock_default,
	.mon_net_action = mon_net_action_default,
	.record_fin_seq = record_fin_seq_default,
	.to_replay_server = to_replay_server_default,
	.read_jiffies = NULL,
	.replay_jiffies = NULL,
	.read_tcp_time_stamp = NULL,
	.replay_tcp_time_stamp = NULL,
	.tcp_under_memory_pressure = NULL,
	.replay_tcp_under_memory_pressure = NULL,
	.sk_under_memory_pressure = NULL,
	.replay_sk_under_memory_pressure = NULL,
	.sk_memory_allocated = NULL,
	.replay_sk_memory_allocated = NULL,
	.sk_sockets_allocated_read_positive = NULL,
	.replay_sk_socket_allocated_read_positive = NULL,
	.skb_mstamp_get = NULL,
	.record_skb_still_in_host_queue = NULL,
	.replay_skb_still_in_host_queue = NULL,
	.general_event = NULL,
	.log = log_default,
	.tx_stamp = NULL,
};
EXPORT_SYMBOL(deter_record_ops_default);

/* The operations that are used during runtime.
 * By default use default functions (do nothing), 
 * but DETER kernel module can change it to concrete deter operations */
struct deter_record_ops deter_record_ops = {
	.server_recorder_create = recorder_create_default,
	.client_recorder_create = recorder_create_default,
	.recorder_destruct = recorder_destruct_default,
	.new_sendmsg = new_sendmsg_default,
	.new_sendpage = new_sendpage_default,
	.new_recvmsg = new_recvmsg_default,
	.new_splice_read = new_splice_read_default,
	.new_close = new_close_default,
	.new_setsockopt = new_setsockopt_default,
	.sockcall_lock = sockcall_lock_default,
	.sockcall_before_lock = sockcall_before_lock_default,
	.incoming_pkt = incoming_pkt_default,
	.incoming_pkt_before_lock = incoming_pkt_before_lock_default,
	.write_timer = write_timer_default,
	.write_timer_before_lock = write_timer_before_lock_default,
	.delack_timer = delack_timer_default,
	.delack_timer_before_lock = delack_timer_before_lock_default,
	.keepalive_timer = keepalive_timer_default,
	.keepalive_timer_before_lock = keepalive_timer_before_lock_default,
	.tasklet = tasklet_default,
	.tasklet_before_lock = tasklet_before_lock_default,
	.mon_net_action = mon_net_action_default,
	.record_fin_seq = record_fin_seq_default,
	.to_replay_server = to_replay_server_default,
	.read_jiffies = NULL,
	.replay_jiffies = NULL,
	.read_tcp_time_stamp = NULL,
	.replay_tcp_time_stamp = NULL,
	.tcp_under_memory_pressure = NULL,
	.replay_tcp_under_memory_pressure = NULL,
	.sk_under_memory_pressure = NULL,
	.replay_sk_under_memory_pressure = NULL,
	.sk_memory_allocated = NULL,
	.replay_sk_memory_allocated = NULL,
	.sk_sockets_allocated_read_positive = NULL,
	.replay_sk_socket_allocated_read_positive = NULL,
	.skb_mstamp_get = NULL,
	.record_skb_still_in_host_queue = NULL,
	.replay_skb_still_in_host_queue = NULL,
	.general_event = NULL,
	.log = log_default,
	.tx_stamp = NULL,
};
EXPORT_SYMBOL(deter_record_ops);

void (*deter_record_effect_bool)(const struct sock *sk, int loc, bool v) = NULL;
EXPORT_SYMBOL(deter_record_effect_bool);

bool (*deter_replay_effect_bool)(const struct sock *sk, int loc) = NULL;
EXPORT_SYMBOL(deter_replay_effect_bool);

void (*advanced_event)(const struct sock *sk, u8 func_num, u8 loc, u8 fmt, int n, ...) = NULL;
EXPORT_SYMBOL(advanced_event);

void (*deter_record_alert)(const struct sock *sk, int loc) = NULL;
EXPORT_SYMBOL(deter_record_alert);

#endif /* DETER_ENABLE */
