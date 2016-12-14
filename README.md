# StereoMac

A stereo vision Screen capture tool for Mac OS X

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

## Credits

barrel_dist library is from [coreyshuman/stereo_raspi](https://github.com/coreyshuman/stereo_raspi)
