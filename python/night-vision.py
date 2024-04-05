from Xlib import X, display
import time

d = display.Display()
root = d.screen().root

window = root.create_window(-10, -10, 20, 20, 1, X.CopyFromParent,
                            X.InputOutput, X.CopyFromParent,
                            background_pixel=d.screen().white_pixel,
                            override_redirect=True)

gc = window.create_gc()

window.map()

def draw_crosshair():
    window.clear_area(0, 0, 20, 20)
    window.line(gc, 10, 0, 10, 20)
    window.line(gc, 0, 10, 20, 10)

while True:
    pointer = root.query_pointer()
    x, y = pointer.root_x, pointer.root_y

    window.configure(x=x - 10, y=y - 10)

    draw_crosshair()

    d.flush()

    time.sleep(0.1)
