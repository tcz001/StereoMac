# StereoMac

A quick hack of Stereo Vision & Screen Capture tool for Mac OS X

![Screen Shot](/screenshot.png?raw=true "Screen Shot")

Using:

- OpenCV
- Quartz Display Service for faster in memory screen capture
- Barrel Distortion for stereo vision calibration

## Quick Start

```
git clone git@github.com:tcz001/StereoMac.git
cd StereoMac
cmake . && make && ./DisplayStereo
```

## Supported Devices

Any device you can connect to the mac via display port or HDMI. I've tried PSVR it works fine to me.
Plan to provide WebRTC service for mobile.
No head track now, plan to support two camera stereo head track in future.

## Credits

barrel_dist library is from [coreyshuman/stereo_raspi](https://github.com/coreyshuman/stereo_raspi)
