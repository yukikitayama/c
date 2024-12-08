# time.h

Overview
- `time.h` header declares functions that produce the time and date when you call them
- `clock()`returns amount of processor time used by the program, not clock time
  - Call at the start and end of some process in a program
  - The difference is a measure of the processor time.
- `time()` returns the number of seconds from an arbitrary epoch
  - Calendar time
- `ctime()` and `asctime()` give current date and day of time
- `gmtime()` converts time value into coordinated universal time (UTC)
- `localtime()` returns structure of type struct tm

struct tm
- This is structure of what `localtime()` returns
- `tm_sec`
- tm_min
- tm_hour
- tm_mday
- tm_mon
- tm_year
- `tm_isdst`
...

Day for a data
- `mktime()`

```
clock_t start = 0, end = 0;
double cpu_time = 0.0;

start = clock();
// Some process
end = clock();

cpu_time = (double) (end - start) / CLOCKS_PER_SEC;  // Processor time in seconds
```

```
char time_str[30] = {'\0'};
time_t calendar = time(NULL);
printf("%s", ctime(&calendar));
```