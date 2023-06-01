#include "totp-internal.h"

pgfe_otp_counter_t calc_periodic_counter(
    time_t realtime, pgfe_totp_interval_t interval, time_t initial_time, pgfe_totp_delta_t *delta_out
) {
    time_t time_offset = realtime - initial_time;
    if (delta_out) {
        *delta_out = interval - time_offset % interval;
    }
    return time_offset / interval;
}

inline time_t curtime() {
    return time(NULL);
}