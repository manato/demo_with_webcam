#!/bin/sh
# gnome-terminal -e './autonomous_driving_system/autod' &
# gnome-terminal -e './autonomous_driving_system/load_img' &
# gnome-terminal -e './geye/gccRelease/CAR_TRACKING.exe' &
# gnome-terminal -e './sign_detection/AdaDetector classifier.xml ./sign_detection/sample.png -merge' &
# gnome-terminal -e './ghostEye_server/watchman' &

#widow_size="80x25"
#window_size="107x37"
window_size="90x30"

# xterm -hold -geometry $window_size+0+0 -title "create shared memory" -e "cd $PWD/autonomous_driving_system/; $PWD/autonomous_driving_system/autod" &
# xterm -hold -geometry $window_size+560+0 -title "load dummy image" -e "cd $PWD/autonomous_driving_system/; $PWD/autonomous_driving_system/load_img" &
# xterm -hold -geometry $window_size+1120+0 -title "car detection program" -e "cd $PWD/geye/; sudo $PWD/geye/gccRelease/CAR_TRACKING.exe" &
# xterm -hold -geometry $window_size+0+450 -title "sign detection program" -e "cd $PWD/sign_detection/; $PWD/sign_detection/AdaDetector $PWD/sign_detection/classifier.xml $PWD/sign_detection/sample.png -merge" &
# xterm -hold -geometry $window_size+560+450 -title "GhostEye server" -e "cd $PWD/ghostEye_server/; $PWD/ghostEye_server/watchman" &


xterm -hold -geometry $window_size+0+0 -title "create shared memory" -e "cd $PWD/autonomous_driving_system/; ./autod" &

sleep 1

xterm -geometry $window_size+560+0 -title "load dummy image" -e "cd $PWD/autonomous_driving_system/; ./load_img" &

#xterm -hold -geometry $window_size+1120+0 -title "car detection program" -e "cd $PWD/geye/; sudo ./gccRelease/CAR_TRACKING.exe" &
xterm -hold -geometry $window_size+560+0 -title "car detection program" -e "cd $PWD/geye_car/; ./gccRelease/CAR_TRACKING.exe" &

xterm -hold -geometry $window_size+1120+0 -title "pedestorian detection program" -e "cd $PWD/geye_pds/; ./gccRelease/CAR_TRACKING.exe" &

#xterm -hold -geometry $window_size+0+450 -title "sign detection program" -e "cd $PWD/sign_detection/; ./AdaDetector ./classifier.xml ./sample.png -merge -mindetections 3" &
xterm -hold -geometry $window_size+0+450 -title "sign detection program" -e "cd $PWD/sign_detection/; ./AdaDetector ./classifier.xml ./sample.png -merge " &

xterm -hold -geometry $window_size+560+450 -title "ghosteye server" -e "cd $PWD/ghostEye_server/; ./watchman" &

