#!/bin/bash
# resizes the window to full height and 50% width and moves into upper right corner

#define the height in px of the top system-bar:
TOPMARGIN=36 # 27

#sum in px of all horizontal borders:
RIGHTMARGIN=0 # 10

#size of task bar
TASKBAR=50

# get width of screen and height of screen
SCREEN_WIDTH=$(xwininfo -root | awk '$1=="Width:" {print $2}')
SCREEN_HEIGHT=$(xwininfo -root | awk '$1=="Height:" {print $2}')

# Setting values for Chrome
# moving to the right half of the screen:
X=$(( $SCREEN_WIDTH / 2 ))
Y=$TOPMARGIN
W=$(( $SCREEN_WIDTH / 2 - $RIGHTMARGIN ))
H=$(( $SCREEN_HEIGHT - $TOPMARGIN - $TASKBAR))


ADDR=$(wmctrl -l | ./GrabWindow "Google Chrome")

# If window doesn't exist, make a new one
if [ -z "${ADDR}" ]; then
    google-chrome-stable &
fi

# Keep trying to get window name until window loads
while [ -z "${ADDR}" ]; do
    ADDR=$(wmctrl -l | ./GrabWindow "Google Chrome")
done

# Resize window
wmctrl -r "${ADDR}" -b remove,maximized_vert,maximized_horz && \
wmctrl -r "${ADDR}" -e 0,$X,$Y,$W,$H 
google-chrome https://www.uvic.ca/cas/login?service=https%3A%2F%2Fwww.uvic.ca%2Ftools%2Findex.php