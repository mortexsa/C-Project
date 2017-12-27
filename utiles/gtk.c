    #include <gtk/gtk.h>
    #include <math.h>
    #include <cairo.h>
     
    #define WIDTH   640
    #define HEIGHT  480
     
    #define ZOOM_X  100.0
    #define ZOOM_Y  100.0
     
     
    gfloat f (gfloat x)
    {
    	return 0.03 * pow (x, 3);
    }
     
    static gboolean
    on_expose_event (GtkWidget *widget, GdkEventExpose *event, gpointer user_data)
    {
    	cairo_t *cr = gdk_cairo_create (widget->window);
    	GdkRectangle da;            /* Dimensions de la GtkDrawingArea */
    	gdouble dx = 5.0, dy = 5.0; /* Nombre de pixels entre chaque point calculé */
    	gdouble i, clip_x1 = 0.0, clip_y1 = 0.0, clip_x2 = 0.0, clip_y2 = 0.0;
    	gint unused = 0;
     
       int iX,iY;
        const int iXmax = WIDTH; 
        const int iYmax = HEIGHT;
        /* world ( double) coordinate = parameter plane*/
        double Cx,Cy;
        const double CxMin=-2.1;
        const double CxMax=0.6;
        const double CyMin=-1.2;
        const double CyMax=1.2;
        /* */
        double PixelWidth=(CxMax-CxMin)/iXmax;
        double PixelHeight=(CyMax-CyMin)/iYmax;
     
        /* Z=Zx+Zy*i  ;   Z0 = 0 */
        double Zx, Zy;
        double Zx2, Zy2; /* Zx2=Zx*Zx;  Zy2=Zy*Zy  */
        /*  */
        double coul;
        int Iteration;
        const int IterationMax=50;
        /* bail-out value , radius of circle ;  */
        const double EscapeRadius=2;
        double ER2=EscapeRadius*EscapeRadius;
        
    	/* On définit la zone de clipping, cela correspond à la zone à 
    	 * raffraîchir. En ne dessinant que le strict nécessaire, on dessinera 
    	 * plus rapidement */
    	cairo_rectangle (cr, 
    			event->area.x, 
    			event->area.y, 
    			event->area.width, 
    			event->area.height);
    	cairo_clip (cr);
     
    	/* On détermine les dimensions de la GtkDrawingArea */
    	gdk_window_get_geometry (widget->window, 
    			&da.x, 
    			&da.y, 
    			&da.width, 
    			&da.height, 
    			&unused);
     
    	/* On dessine un fond noir */
    	cairo_set_source_rgb (cr, 0.0, 0.0, 0.0);
    	cairo_paint (cr);
        cairo_translate(cr, 0, 0);
          cairo_set_line_width(cr, 1);  
  
  
      for(iY=0;iY<iYmax;iY++)
        {
             Cy=CyMin + iY*PixelHeight;
             if (fabs(Cy)< PixelHeight/2) Cy=0.0; /* Main antenna */
             for(iX=0;iX<iXmax;iX++)
             {         
				 cairo_line_to (cr, iX, iY);
                        Cx=CxMin + iX*PixelWidth;
                        /* initial value of orbit = critical point Z= 0 */
                        Zx=0.0;
                        Zy=0.0;
                        Zx2=Zx*Zx;
                        Zy2=Zy*Zy;
                        /* */
                        for (Iteration=0;Iteration<IterationMax && ((Zx2+Zy2)<ER2);Iteration++)
                        {
                            Zy=2*Zx*Zy + Cy;
                            Zx=Zx2-Zy2 +Cx;
                            Zx2=Zx*Zx;
                            Zy2=Zy*Zy;
                        }

  coul=(double)Iteration/100;

                        if (Iteration==IterationMax) cairo_set_source_rgb(cr, 0, 0, 0);
						else  cairo_set_source_rgb(cr, 0, 0, coul);
						
  cairo_arc(cr, iX, iY, 1, 0, 2 * M_PI);
  cairo_fill(cr);   									   
  
						}
												} 
	cairo_destroy (cr);
    	return FALSE;
}                       
                        
                        
     
     
    
    
     
    int
    main (int argc, char **argv)
    {
    	GtkWidget *window;
    	GtkWidget *da;
     
    	gtk_init (&argc, &argv);
     
    	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    	gtk_window_set_default_size (GTK_WINDOW (window), WIDTH, HEIGHT);
    	gtk_window_set_title (GTK_WINDOW (window), "Affichage de courbe");
    	g_signal_connect (G_OBJECT (window), "delete-event", gtk_main_quit, NULL);
     
    	da = gtk_drawing_area_new ();
    	gtk_container_add (GTK_CONTAINER (window), da);
     
    	g_signal_connect (G_OBJECT (da), 
    			"expose-event", 
    			G_CALLBACK (on_expose_event), 
    			NULL);
     
    	gtk_widget_show_all (window);
    	gtk_main ();
     
    	return 0;
    }


