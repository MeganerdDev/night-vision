![night-vision](./asset/logo.png)

# night-vision
Virtual cursor for LXC Containers running X11 display

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

### Building
You can use a pre-made build or run:
```bash
$ g++ night-vision.cpp -o ./build/night-vision -lX11
```

### Python
There is also a python release of night-vision in `./python`
It uses more CPU resource, but is still viable at 100-ms delay

The `./python` directory also includes a poetry virtual environment
