#include <gtk/gtk.h>

static void destroy (GtkWidget*,gpointer);
//static gboolean delete_event (GtkWidget*,GdkEvent*,gpointer);
static void test()
{
	g_message("Suck it\n");
}

int main(int argc, char *argv[]){
	
	GtkWidget *window, *label, *button;

	/*Initialize GTK+ and all of its libraries*/
	gtk_init (&argc, &argv);

	/*Creates new window, and title*/
	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window),"Adios Mundo!");
	gtk_container_set_border_width (GTK_CONTAINER(window), 20);
	gtk_widget_set_size_request (window, 300, 200);

	/*Connect destroy and delete-event signals*/
	g_signal_connect (G_OBJECT (window),"destroy",
					  G_CALLBACK(destroy), NULL);
	
	/*New Label*/
	label = gtk_label_new ("This is selectable");
	gtk_label_set_selectable (GTK_LABEL (label), TRUE);

	/*Button*/
	button = gtk_button_new_with_mnemonic ("_Close");
	gtk_button_set_relief (GTK_BUTTON (button), GTK_RELIEF_NONE);

	g_signal_connect (G_OBJECT(button), "clicked",
						G_CALLBACK (test),
						(gpointer) window);

	/*Add Label to child widget of window*/
	gtk_container_add(GTK_CONTAINER (window), button);
	gtk_container_add(GTK_CONTAINER (window), label);
	
	gtk_widget_show_all(window);

	/*Main Loop*/
	gtk_main();
	return 0;

}

static void destroy (GtkWidget *window, gpointer data){
	gtk_main_quit();
}


