#include <gtk/gtk.h>

static void
print_hello (GtkWidget *widget,
	gpointer	data)
{
	g_print("Is Corinne! I LOVE YOU\n");
}

static gboolean
on_delete_event (GtkWidget *widget,
	GdkEvent	*event,
	gpointer	data)
	{
		g_print (":(\n");

		return FALSE;
	}

int
main (int	argc,
char *argv[])
{
	GtkWidget *window;
	GtkWidget *button;


	gtk_init(&argc, &argv);

	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title (GTK_WINDOW (window), "Sniff Love");

	g_signal_connect (window, "delete-event", G_CALLBACK (on_delete_event), NULL);

	g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);

	gtk_container_set_border_width (GTK_CONTAINER (window), 10);

	button = gtk_button_new_with_label ("My Love");

	g_signal_connect(button, "clicked", G_CALLBACK (print_hello), NULL);

	g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_widget_destroy), window);

	gtk_container_add (GTK_CONTAINER (window), button);

	gtk_widget_show (button);	

	gtk_widget_show (window);

	gtk_main();

	return 0;
}