#include <X11/Xlib.h>
#include <unistd.h>
#include <cstdlib>

int main(int argc, char* argv[]) {
    Display* display = XOpenDisplay(nullptr);
    if (!display) return -1;

    Window root = DefaultRootWindow(display);
    int screen = DefaultScreen(display);
    Colormap colormap = DefaultColormap(display, screen);

    XColor bgColor, exactBgColor;
    XAllocNamedColor(display, colormap, "#2D353B", &bgColor, &bgColor);

    XColor crossColor, exactCrossColor;
    XAllocNamedColor(display, colormap, "#6FA07E", &crossColor, &crossColor);

    XColor borderColor, exactBorderColor;
    XAllocNamedColor(display, colormap, "#485953", &borderColor, &borderColor);

    Window window = XCreateSimpleWindow(display, root, 0, 0, 24, 24, 2,
                                        borderColor.pixel, bgColor.pixel);

    XSetWindowAttributes attrs;
    attrs.override_redirect = True;
    attrs.background_pixel = bgColor.pixel;
    XChangeWindowAttributes(display, window, CWOverrideRedirect | CWBackPixel, &attrs);

    XMapRaised(display, window);

    GC gc = XCreateGC(display, window, 0, nullptr);
    XSetForeground(display, gc, crossColor.pixel);

    int sleepTime = 100000;
    if (argc > 1) {
        sleepTime = atoi(argv[1]) * 1000;
    }

    int lastX = -1, lastY = -1;

    while (true) {
        Window dummy;
        int x, y, dummy2;
        unsigned int dummy3;

        if (XQueryPointer(display, root, &dummy, &dummy, &x, &y, &dummy2, &dummy2, &dummy3)) {
            if (x != lastX || y != lastY) {
                lastX = x;
                lastY = y;
                XMoveWindow(display, window, x - 12, y - 12);

                XClearWindow(display, window);
                for (int offset = -1; offset <= 1; ++offset) {
                    XDrawLine(display, window, gc, 12 + offset, 4, 12 + offset, 20);
                    XDrawLine(display, window, gc, 4, 12 + offset, 20, 12 + offset);
                }
                XFlush(display);
            }
        }

        usleep(sleepTime);
    }

    XCloseDisplay(display);
    return 0;
}

