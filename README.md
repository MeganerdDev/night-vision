<div align="center">
    <img src="asset/logo.png" alt="night-vision-logo" width="25%" />
</div>

# night-vision
Virtual cursor for LXC Containers running X11 display

<div align="center">
  <video width="50%" controls>
    <source src="asset/nv-demo.webm" type="video/webm">
    Your browser does not support the webm.
  </video>
</div>

[night-vision demo.webm](https://github.com/MeganerdDev/night-vision/blob/main/asset/nv-demo.webm)

### Usage
```bash
$ ./night-vision {ms}
```

`{ms}` Milliseconds delay between cursor iteration, default: 100

```bash
# 50-ms delay is fine, 10-100 is probably the expected range
$ ./night-vision 50
# 1-ms delay, uses more CPU resource naturally
$ ./night-vision 1
```

### Building from source
```bash
$ g++ night-vision.cpp -o ./build/night-vision -lX11
```

### Compiled release builds
Compiled builds are available for amd64, aarch64 at the moment. 

### Contributing
Keep CPU cost to minimum on PRs since we are targing ARM.

### Python
There is also a python release of night-vision in `./python`
It uses more CPU resource, but is still viable at 100-ms delay

The `./python` directory also includes a poetry virtual environment
