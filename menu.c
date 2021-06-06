#include<stdio.h>
#include<gtk/gtk.h>
GtkBuilder *builder;
GtkWidget *E1_M;
//Les Fonction
void quit_clbk(); //Fonction de Quiter le Programme
void Gestion_Voiture(GtkWidget ,gpointer ); //Fonction de Gestion des Voitures
void Gestion_Client(GtkWidget ,gpointer ); //Fonction de Gestion des Clients
void show(GtkWidget ,gpointer ); //Fonction de Location d'une Voiture
int main(int argc , char **argv){
    GtkBuilder      *builder; 
    gtk_init(&argc,&argv);
    GtkWidget *window;
    GtkWidget *buttonA;
    GtkWidget *buttonB;
    GtkWidget *buttonC;
    GtkWidget *buttonD;
    GtkWidget *OK;
    // Afficher Menu Principal
    builder=gtk_builder_new_from_file ("test2.glade");
    window=GTK_WIDGET(gtk_builder_get_object(builder ,"Menu"));
    E1_M=GTK_WIDGET(gtk_builder_get_object(builder , "lA"));
    buttonA=GTK_WIDGET(gtk_builder_get_object(builder , "bA"));
    buttonB=GTK_WIDGET(gtk_builder_get_object(builder , "bB"));
    buttonC=GTK_WIDGET(gtk_builder_get_object(builder , "bC"));
    buttonD=GTK_WIDGET(gtk_builder_get_object(builder , "bD"));
    //***
    g_signal_connect(buttonA ,"clicked",G_CALLBACK(show), NULL);
    g_signal_connect(buttonB ,"clicked",G_CALLBACK(Gestion_Voiture), NULL);
    g_signal_connect(buttonC ,"clicked",G_CALLBACK(Gestion_Client), NULL);
    g_signal_connect(buttonD ,"clicked",G_CALLBACK(quit_clbk ), NULL);
    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}

//CODE PAR : ZOUBAIR ELFADILI ; MOUHCINE BOUCETTA