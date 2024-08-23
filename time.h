#ifndef TIME_H
#define TIME_H

#ifdef C2_TIME
    #define PERIOD_MS 20
#else
    #define PERIOD_MS 100
#endif

long long currentTimeMillis(void);

#endif /* TIME_H */
