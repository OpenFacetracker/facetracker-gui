[![GitHub version](https://badge.fury.io/gh/invicnaper%2FMWF.svg)](http://badge.fury.io/gh/invicnaper%2FMWF) [![Code Climate](https://codeclimate.com/github/invicnaper/MWF/badges/gpa.svg)](https://codeclimate.com/github/invicnaper/MWF)
# facetracker-gui
facetracker-gui contient facetracker-core écrit en C++ ainsi que l'interface graphique écrite en C++ et en QT

#Screenshots

![alt text](http://naper.eu/me/images/facetracker.jpg "Facetracker Core")

#Utilisation 
Facetracker est multi-plateforme disponible pour Linux et Windows .

#Installation Linux (Facetracker-core)

    $ git clone https://github.com/Facetracker-project/facetracker-gui.git
    $ cd facetracker/
    
installation des dépendences : 

    $ sudo apt-get install libopencv-dev
    
utilisation du fichier makefile : 

    $ make 
    make ftall		  : Build facetracker
    make memleaks		: Check memory leaks
    
pour compiler tout les modules du projet : 

    $ make ftall
    
puis lancer : 

    $ ./facetracker -o
    
#Installation Linux(Facetracker-gui Interface graphique)

Ouvrez le fichier <b>facetracker_gui.pro</b> avec Qt creator .

#Installation Windows(Facetracker core)

Ouvrez le fichier <b>Facetracker.sln</b>

#Installation Windows(Facetracker -gui Interface graphique)

Ouvrez le fichier <b>facetracker_gui.pro</b> avec Qt creator .


#Commandes Disponibles

-o : Permet d'ouvrir une source multimedia (Camera , Image , vidéo , lien rtsp ..)

    $ ./facetracker -o CAM0 
    $ ./facetracker -o video.avi


    


    
    
