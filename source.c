#include<stdio.h>
#include<gtk/gtk.h>
GtkWidget *window;
    GtkWidget *buttonA;
    GtkWidget *buttonB;
    GtkWidget *buttonC;
    GtkWidget *buttonD;
    GtkWidget *OK;
    GtkBuilder *builder;
GtkWidget *E1_M,*E1_W1,*E2_W1,*E3_W1,*E4_W1,*E5_W1,*E6_W1,*E7_W1;
GtkWidget *B1,*B2,*B3,*B4,*B5,*B6,*B7;
GtkWidget *E1_W2,*E2_W2,*E3_W2,*E4_W2,*E5_W2,*E6_W2,*E6_W2,*E7_W2;
GtkWidget *B8,*B9,*B10,*B11,*B12,*B13,*B14;
GtkWidget *switch1;
//struct
typedef struct 
	{ 
	char idVoiture[5]; 
	char marque[15]; 
	char nomVoiture[15]; 
	char couleur[7]; 
	char nbPlaces[5]; 
	char prixJour[5]; 
	char enLocation[4]; 
}voiture;
typedef struct 
{ 
	char idClient[8]; 
	char nom[20]; 
	char prenom[20]; 
	char cin[8]; 
	char adresse[15]; 
	char telephone[10]; 
 } client;
typedef struct
{
	int j; 
	int m; 
	int a; 
}date; 
typedef struct {
    GtkWidget *w_txtvw_main;            // Pointer to text view object
    GtkWidget *w_dlg_file_choose;       // Pointer to file chooser dialog box
    GtkTextBuffer *textbuffer_main;     // Pointer to text buffer
} app_widgets;
//Delet Voiture


//Fonction Creé le fiche List_Clients
void entry_Client (GtkWidget *widget,gpointer data){
    client customer ;
    FILE *pfs;
    
    strcpy(customer.idClient,gtk_entry_get_text(GTK_ENTRY(E1_W2)));
    strcpy(customer.nom,gtk_entry_get_text(GTK_ENTRY(E2_W2)));
    strcpy(customer.prenom,gtk_entry_get_text(GTK_ENTRY(E3_W2)));
    strcpy(customer.cin,gtk_entry_get_text(GTK_ENTRY(E4_W2)));
    strcpy(customer.adresse,gtk_entry_get_text(GTK_ENTRY(E5_W2)));
    strcpy(customer.telephone,gtk_entry_get_text(GTK_ENTRY(E6_W2)));
    
    pfs=fopen("ListClient","a");
    fprintf(pfs,"%s : %s: %s: %s: %s: %s",customer.idClient,customer.nom,customer.prenom,customer.cin,customer.adresse,customer.telephone);
    fclose(pfs);
}
//Fonction Creé le fiche List_Voitures
void entry_Voiture (GtkWidget *widget,gpointer data){
    voiture car;
    FILE *pf;
    
    strcpy(car.idVoiture,gtk_entry_get_text(GTK_ENTRY(E1_W1)));
    strcpy(car.marque,gtk_entry_get_text(GTK_ENTRY(E2_W1)));
    strcpy(car.nomVoiture,gtk_entry_get_text(GTK_ENTRY(E3_W1)));
    strcpy(car.couleur,gtk_entry_get_text(GTK_ENTRY(E4_W1)));
    strcpy(car.nbPlaces,gtk_entry_get_text(GTK_ENTRY(E5_W1)));
    strcpy(car.prixJour,gtk_entry_get_text(GTK_ENTRY(E6_W1)));
    strcpy(car.enLocation,gtk_entry_get_text(GTK_ENTRY(E7_W1)));
    pf=fopen("ListVoiture","a");
    fprintf(pf,"%s : %s: %s: %s: %s: %s: %s",car.idVoiture,car.marque,car.nomVoiture,car.couleur,car.nbPlaces,car.prixJour,car.enLocation);
    fclose(pf);
    
    
}
//

//Fonction de Quiter le Programme 
void quit_clbk    ( void )
{
    g_print ( "GoodBye\n" );
    gtk_main_quit();
}
//Fonction de Gestion des Voitures
void Gestion_Voiture(GtkWidget *widget,gpointer data){
    GtkWidget *window1;
    GtkWidget *OK1,*Annuler;
  
     builder=gtk_builder_new_from_file ("test2.glade");
    window1=GTK_WIDGET(gtk_builder_get_object(builder , "Voiture"));
    switch1=GTK_WIDGET(gtk_builder_get_object(builder , "switch1"));
    B1=GTK_WIDGET(gtk_builder_get_object(builder , "b1"));
    B2=GTK_WIDGET(gtk_builder_get_object(builder , "b2"));
    B3=GTK_WIDGET(gtk_builder_get_object(builder , "b3"));
    B4=GTK_WIDGET(gtk_builder_get_object(builder , "b4"));
    B5=GTK_WIDGET(gtk_builder_get_object(builder , "b5"));
    B6=GTK_WIDGET(gtk_builder_get_object(builder , "b6"));
    B7=GTK_WIDGET(gtk_builder_get_object(builder , "b7"));
    OK1=GTK_WIDGET(gtk_builder_get_object(builder , "OK1"));
    //***
    E1_W1=GTK_WIDGET(gtk_builder_get_object(builder , "e1"));
    E2_W1=GTK_WIDGET(gtk_builder_get_object(builder , "e2"));
    E3_W1=GTK_WIDGET(gtk_builder_get_object(builder , "e3"));
    E4_W1=GTK_WIDGET(gtk_builder_get_object(builder , "e4"));
    E5_W1=GTK_WIDGET(gtk_builder_get_object(builder , "e5"));
    E6_W1=GTK_WIDGET(gtk_builder_get_object(builder , "e6"));
    E7_W1=GTK_WIDGET(gtk_builder_get_object(builder , "e7"));
    g_signal_connect(OK1,"clicked",G_CALLBACK(entry_Voiture), NULL);
    //***
    
    gtk_widget_show_all(window1);
}
//Fonction de Gestion des Clients
void Gestion_Client(GtkWidget *widget,gpointer data){
    GtkWidget *window2;
    GtkWidget *OK2;
    GtkWidget *Annuler;

    
     builder=gtk_builder_new_from_file ("test2.glade");
    window2=GTK_WIDGET(gtk_builder_get_object(builder , "Client"));
    switch1=GTK_WIDGET(gtk_builder_get_object(builder , "switch3"));
    //***
    B7=GTK_WIDGET(gtk_builder_get_object(builder , "l8"));
    B8=GTK_WIDGET(gtk_builder_get_object(builder , "l9"));
    B9=GTK_WIDGET(gtk_builder_get_object(builder , "l10"));
    B10=GTK_WIDGET(gtk_builder_get_object(builder , "l11"));
    B11=GTK_WIDGET(gtk_builder_get_object(builder , "l12"));
    B12=GTK_WIDGET(gtk_builder_get_object(builder , "l13"));
    //***
    E1_W2=GTK_WIDGET(gtk_builder_get_object(builder , "e8"));
    E2_W2=GTK_WIDGET(gtk_builder_get_object(builder , "e9"));
    E3_W2=GTK_WIDGET(gtk_builder_get_object(builder , "e10"));
    E4_W2=GTK_WIDGET(gtk_builder_get_object(builder , "e11"));
    E5_W2=GTK_WIDGET(gtk_builder_get_object(builder , "e12"));
    E6_W2=GTK_WIDGET(gtk_builder_get_object(builder , "e13"));
    OK2=GTK_WIDGET(gtk_builder_get_object(builder , "OK2"));
    //***
    g_signal_connect(OK2 ,"clicked",G_CALLBACK(entry_Client), NULL);
    
    gtk_widget_show_all(window2);
}
//Fonction de afficher les liste de Voitures et Clients
void show(GtkWidget *widget,gpointer data){
    GtkBuilder      *builder; 
    GtkWidget       *window;
    app_widgets     *widgets = g_slice_new(app_widgets);

    builder = gtk_builder_new_from_file("test2.glade");
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
    // Get pointers to widgets
    widgets->w_txtvw_main = GTK_WIDGET(gtk_builder_get_object(builder, "txtvw_main"));
    widgets->w_dlg_file_choose = GTK_WIDGET(gtk_builder_get_object(builder, "dlg_file_choose"));
    widgets->textbuffer_main = GTK_TEXT_BUFFER(gtk_builder_get_object(builder, "textbuffer_main"));
    
    gtk_builder_connect_signals(builder, widgets);

    g_object_unref(builder);

    gtk_widget_show(window);
    gtk_main();
    g_slice_free(app_widgets, widgets);
}
// File --> Open
void on_menuitm_open_activate(GtkMenuItem *menuitem, app_widgets *app_wdgts)
{
    gchar *file_name = NULL;        // Name of file to open from dialog box
    gchar *file_contents = NULL;    // For reading contents of file
    gboolean file_success = FALSE;  // File read status
    
    // Show the "Open Text File" dialog box
    gtk_widget_show(app_wdgts->w_dlg_file_choose);
    
    // Check return value from Open Text File dialog box to see if user clicked the Open button
    if (gtk_dialog_run(GTK_DIALOG (app_wdgts->w_dlg_file_choose)) == GTK_RESPONSE_OK) {
        // Get the file name from the dialog box
        file_name = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(app_wdgts->w_dlg_file_choose));
        if (file_name != NULL) {
            // Copy the contents of the file to dynamically allocated memory
            file_success = g_file_get_contents(file_name, &file_contents, NULL, NULL);
            if (file_success) {
                // Put the contents of the file into the GtkTextBuffer
                gtk_text_buffer_set_text(app_wdgts->textbuffer_main, file_contents, -1);
            }
            g_free(file_contents);
        }
        g_free(file_name);
    }

    // Finished with the "Open Text File" dialog box, so hide it
    gtk_widget_hide(app_wdgts->w_dlg_file_choose);
}

// File --> Close
void on_menuitm_close_activate(GtkMenuItem *menuitem, app_widgets *app_wdgts)
{
    // Clear the text from window "Close the file"
    gtk_text_buffer_set_text(app_wdgts->textbuffer_main, "", -1);
}

// File --> Quit
void on_menuitm_quit_activate(GtkMenuItem *menuitem, app_widgets *app_wdgts)
{
    gtk_main_quit();
}

// called when window is closed
void on_window_main_destroy()
{
    gtk_main_quit();
}

//CODE PAR : ZOUBAIR ELFADILI ; MOUHCINE BOUCETTA