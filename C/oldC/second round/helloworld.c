#include <gtk/gtk.h>

int main(int argc, char *argv[]){
	
	GtkWidget *window;

	/*Initialize GTK+ and all of its libraries*/
	gtk_init (&argc, &argv);

	/*Creates new window, and title*/
	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window),"Hola Mundo!");
	gtk_widget_show(window);

	/*Main Loop*/
	gtk_main();
	return 0;

}