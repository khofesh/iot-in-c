# Raspberry Pi IoT in C

## BCM 2835

```shell
sudo apt install libbcm2835-dev
```

check where files are installed

```shell
dpkg -L libbcm2835-dev
```

## Rasberry Pi General

**clock speed**

```shell
sudo vcgencmd measure_clock arm
```

this gives you the frequency that all of the cores are running at.

**discover the current active governor**

```shell
sudo cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor
```

**check the available**

```shell
sudo cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_available_governors
```

> a set of governors control how the frequency is varied

> The cpufreq governor "ondemand" sets the CPU frequency depending on
> the current system load. Load estimation is triggered by the scheduler
> through the update_util_data->func hook; when triggered, cpufreq
> checks the CPU-usage statistics over the last period and the governor
> sets the CPU accordingly.

**the current clock rate according to Linux**

```shell
cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_cur_freq
```

**the maximum and minimum frequencies**

```shell
cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_min_freq
cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_max_freq
```

**set fixed clock frequency**

```shell
sudo sh -c "echo performance > /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor"
```

# References
- https://www.airspayce.com/mikem/bcm2835/index.html