# MartiniBot
A robot who will locate the user and deliver martinis when the users requests

Be sure to check out the Wiki for more details on development and creation of this robot.

[WIKI](https://github.com/Peter-Wilson/MartiniBot/wiki)



#Components
There are 2 main components for the Martini-bot. Those components are the remote control and the Martini-bot itself. The 
2 components work together to ensure that the martini bot fulfills its purpose and delivers it's payload to the 
user.

##Remote:
	The remote was built with a "hackduino" as it's microcontroller. It uses XBee radio communication to give and 
	recieve commands from the robot. The radio antenna sticks out from the bottom of the remove. It also uses an Ultrasonic 
	sensor to broadcast the location of the remote to the robot. This needs to be pointed at the robot at all times.
	To activate the robot, simply press the button on the middle of the remote and that will activate the Martini bot to move towards
	the user. Here is an image of the remote. Click on it to see a video of it.

	[![ScreenShot](https://github.com/Peter-Wilson/MartiniBot/blob/develop/Pictures/IMG_20160420_134347.jpg)](https://youtu.be/oRUg_URGGXE)
	
	
##Martini-Bot:
	The martini bot utilizes the Romeo arduino as it's micro controller. This worked out well for us since it had built in 
	motor controls which we would utilize to move the robot forward. It also has an ultrasonic sensor to pick up the signals from the 
	remote. It has and XBee radio to send and recieve commands from the remote. Finally it also has encoders that are controlled by an
	ATtiny to determine where and how far the bot travelled. Below is an image of the robot. Click on the image to see a video of the 
	robot in action.
	
	[![ScreenShot](https://github.com/Peter-Wilson/MartiniBot/blob/develop/Pictures/IMG_20160420_134347.jpg)](https://youtu.be/oRUg_URGGXE)
