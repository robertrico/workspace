#include <gtk/gtk.h>

static void destroy (GtkWidget*,gpointer);
static gboolean delete_event (GtkWidget*,GdkEvent*,gpointer);

int main(int argc, char *argv[]){
	
	GtkWidget *window, *label;

	/*Initialize GTK+ and all of its libraries*/
	gtk_init (&argc, &argv);

	/*Creates new window, and title*/
	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window),"Hola Mundo!");
	gtk_container_set_border_width (GTK_CONTAINER(window), 10);
	gtk_widget_set_size_request (window, 200, 100);

	/*Connect destroy and delete-event signals*/
	g_signal_connect (G_OBJECT (window),"destroy",
					  G_CALLBACK(destroy), NULL);
	g_signal_connect (G_OBJECT (window),"delete_event",
					  G_CALLBACK(delete_event), NULL);

	/*New Label*/
	label = gtk_label_new ("This is selectable");
	gtk_label_set_selectable (GTK_LABEL (label), TRUE);

	/*Add Label to child widget of window*/
	gtk_container_add(GTK_CONTAINER (window), label);
	gtk_widget_show_all(window);

	/*Main Loop*/
	gtk_main();
	return 0;

}

static void destroy (GtkWidget *window, gpointer data){
	gtk_main_quit();
}

/*Return FALSE to destroy the widget. True cancels the delete event. Confirmation of app quit*/
static gboolean delete_event(GtkWidget *window, 
				   	 		 GdkEvent *event, 
				   	 		 gpointer data)
{
	return FALSE;
}