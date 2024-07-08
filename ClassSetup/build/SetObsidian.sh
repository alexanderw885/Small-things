# resizes the window to full height and 50% width and moves into upper left corner

#define the height in px of the top system-bar:
TOPMARGIN=36 # 27

#sum in px of all horizontal borders:
RIGHTMARGIN=0 # 10

#size of task bar
TASKBAR=50

# get width of screen and height of screen
SCREEN_WIDTH=$(xwininfo -root | awk '$1=="Width:" {print $2}')
SCREEN_HEIGHT=$(xwininfo -root | awk '$1=="Height:" {print $2}')

# setting values to adjust for Obsidian
#move to left side of screen
X=0
Y=0
W=$(( $SCREEN_WIDTH / 2 - $RIGHTMARGIN ))
H=$(( $SCREEN_HEIGHT - $TASKBAR))

ADDR=$(wmctrl -l | ./GrabWindow "Obsidian")

# If window does not exist, make a new one
if [ -z "${ADDR}" ]; then
    obsidian &
fi

# Keep trying to grab window until it loads in
while [ -z "${ADDR}" ]; do
    ADDR=$(wmctrl -l | ./GrabWindow "Obsidian")
done

# Resize window
wmctrl -r "${ADDR}" -b remove,maximized_vert,maximized_horz && \
wmctrl -r "${ADDR}" -e 0,$X,$Y,$W,$H