#ifndef thumbnail_viewer
#define thumbnail_viewer

#include <gtk/gtk.h>
#include <gdk-pixbuf/gdk-pixbuf.h>
#include <dirent.h>
#include <sys/types.h>
#include <iostream>
#include <string>


class ThumbnailViewer {

int thumbnailWidth = 110;;
int thumbnailHeight = 70;

int windowWidth = 400;
int windowHeight = 300;

std::string folder_path;


void populateFlowbox(GtkWidget *flowbox, std::string folder_path);



public :

int getThumbnailWidth();
void setThumbnailWidth(int thumbnailWidth);
int getThumbnailHeight();
void setThumbnailHeight(int thumbnailHeight);

int getWindowWidth();
void setWindowWidth(int windowWidth);
int getWindowHeight();
void setWindowHeight(int windowHeight);

std::string getFolderPath();
void setFolderPath(std::string folder_path);

ThumbnailViewer(int argc, char *argv[]);

};





#endif