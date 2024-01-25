# thumbnail-viewer applicaton
This application genrates a GUI window, reads all the images from a
desired folder and displays their thumbnails in the window.

## implementation
This application is implemented usig gtk which is a GUI library.
The widgets used here are gtk window and flexbox. 

## requirements
You need to have g++ compiler and the gtk library in your system
in order to run the apploication.

## usage
Before running the makefile in your terminal, go to the src folder and access the thumbnailViewer.cpp file. Go to the block which starts with "ThumbnailViewer::ThumbnailViewer....". Just beneath the comments that tells you to specify the folder's path, you get to see a variable by the name "folder_path". use the variable to set the absolute path of the folder where you images are situated.

Run the makefile by typing "make" in your terminal. This will genrate an executable by the name "thumbnail_viewer".

To the executable, type "./thumbnail_viewer".

## referneces
To know more about gtk, [click here](https://www.gtk.org/docs/).