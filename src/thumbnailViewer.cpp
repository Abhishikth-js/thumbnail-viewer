#include "../include/thumbnailViewer.h"

// getters and setters to altr the dimensions of the thumbnails
int ThumbnailViewer::getThumbnailWidth() {
    return thumbnailWidth;
}

void ThumbnailViewer::setThumbnailWidth(int thumbnailWidth) {
    this->thumbnailWidth = thumbnailWidth;
}

int ThumbnailViewer::getThumbnailHeight() {
    return thumbnailHeight;
}

void ThumbnailViewer::setThumbnailHeight(int thumbnailHeight) {
    this->thumbnailHeight = thumbnailHeight;
}



// getters and setters to alter the dimensions of the window 
int ThumbnailViewer::getWindowWidth() {
    return windowWidth;
}
void ThumbnailViewer::setWindowWidth(int windowWidth) {
    this->windowWidth = windowWidth;
}
int ThumbnailViewer::getWindowHeight() {
    return windowHeight;
}
void ThumbnailViewer::setWindowHeight(int windowHeight) {
    this->windowHeight = windowHeight;
}



// getters and setter to specifiy the folder path which consists of image
//files
std::string ThumbnailViewer::getFolderPath() {
    return folder_path;
}

void ThumbnailViewer::setFolderPath(std::string folder_path) {
    this->folder_path = folder_path;
}


void ThumbnailViewer::populateFlowbox(GtkWidget *flowbox, std::string folder_path) {
 struct dirent *entry;
    DIR *dp;
    const char* constPath = folder_path.c_str();
    dp = opendir(constPath);
    if (dp != NULL) {
        while ((entry = readdir(dp))) {
            const char *name = entry->d_name;
            if (strcmp(name, ".") != 0 && strcmp(name, "..") != 0) {
                char *file_path = g_build_filename(constPath, name, NULL);
                GdkPixbuf *orig_pixbuf = gdk_pixbuf_new_from_file(file_path, NULL);
                if (orig_pixbuf != NULL) {
                    GdkPixbuf *pixbuf = gdk_pixbuf_scale_simple(orig_pixbuf, thumbnailWidth, thumbnailHeight, GDK_INTERP_BILINEAR);
                    GtkWidget *image = gtk_image_new_from_pixbuf(pixbuf);

                    // Create a button to hold the image without a border
                    GtkWidget *button = gtk_button_new();
                    gtk_button_set_relief(GTK_BUTTON(button), GTK_RELIEF_NONE);
                    gtk_container_add(GTK_CONTAINER(button), image);

                    // Connect a signal to handle button clicks (if needed)
                    // g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(your_callback_function), data);

                    gtk_container_add(GTK_CONTAINER(flowbox), button);

                    g_object_unref(orig_pixbuf);
                    g_free(file_path);
                }
            }
        }
        closedir(dp);
    }   
}

ThumbnailViewer::ThumbnailViewer(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Thumbnail Viewer");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    gtk_widget_set_size_request(window, windowWidth, windowHeight);

    GtkWidget *scrolled_window = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window),
                                   GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);

    GtkWidget *flowbox = gtk_flow_box_new();
    gtk_flow_box_set_homogeneous(GTK_FLOW_BOX(flowbox), TRUE);
    gtk_flow_box_set_column_spacing(GTK_FLOW_BOX(flowbox), 10);
    gtk_flow_box_set_row_spacing(GTK_FLOW_BOX(flowbox), 10);

    gtk_container_add(GTK_CONTAINER(scrolled_window), flowbox);
    gtk_container_add(GTK_CONTAINER(window), scrolled_window);


    // relative path not supported, specify absolute path
    folder_path = "/home/ee212468/Documents/images";
    populateFlowbox(flowbox, folder_path);

    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(window);

    gtk_main();

}