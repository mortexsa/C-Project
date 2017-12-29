//---------------------------------------
// Program: mandelbrot2.cpp
// Purpose: To generate a portion of the mandelbrot set.
// Author:  John Gauch
// Date:    November 2008
//---------------------------------------
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#ifdef MAC
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

// Global variables
#define XDIM 800
#define YDIM 800
unsigned char image[YDIM][XDIM];
double center_re = -0.5;
double center_im = 0.0;
double radius = 1.0;
int depth = 4;

//---------------------------------------
// Calculate Z=Z^2+C for given C
//---------------------------------------
int mandelbrot(double C_re, double C_im, int max_count)
{
   int count = 0;
   double Z_re = 0;
   double Z_im = 0;
   double magnitude = 0;
   double max_magnitude = 1000000;

   // Calculate Z=Z^2+C for given C
   while ((magnitude < max_magnitude) && (count++ < max_count))
   {
      double N_re = Z_re * Z_re - Z_im * Z_im + C_re;
      double N_im = Z_re * Z_im + Z_im * Z_re + C_im;
      Z_re = N_re;
      Z_im = N_im;
      magnitude = Z_re * Z_re + Z_im * Z_im;
   }

   // Return number of iterations 
   if (count >= max_count)
      return 0;
   else
      return count;
}

//---------------------------------------
// Initialize mandelbrot image
//---------------------------------------
void init_mandelbrot()
{
   for (int y = 0; y < YDIM; y++)
      for (int x = 0; x < XDIM; x++)
      {
	 double C_re = center_re - radius + 2 * radius * x / XDIM;
	 double C_im = center_im - radius + 2 * radius * y / YDIM;
	 image[y][x] = mandelbrot(C_re, C_im, depth * 256) % 256;
      }
}

//---------------------------------------
// Init function for OpenGL
//---------------------------------------
void init()
{
   // Initialize OpenGL
   float r_map[256] = {0.0};
   float g_map[256] = {0.0};
   float b_map[256] = {0.0};
   for (int i = 0; i < 128; i++)
   {
      b_map[i] = 1.0 - i / 128.0;
      g_map[i] = i / 128.0;
      g_map[i+128] = 1.0 - i / 128.0;
      r_map[i+128] = i / 128.0;
   }
   r_map[0] = g_map[0] = b_map[0] = 0.0;
   glPixelMapfv(GL_PIXEL_MAP_I_TO_R, 256, r_map);
   glPixelMapfv(GL_PIXEL_MAP_I_TO_G, 256, g_map);
   glPixelMapfv(GL_PIXEL_MAP_I_TO_B, 256, b_map);
   glClearColor(0.0, 0.0, 0.0, 1.0);

   // Initialize mandelbrot image
   init_mandelbrot();
}

//---------------------------------------
// Mouse callback for OpenGL
//---------------------------------------
void mouse(int button, int state, int x, int y)
{
   // Calculate new center and radius
   if (state == GLUT_DOWN)
   {
      y = YDIM - y;
      center_re = center_re - radius + 2 * radius * x / XDIM;
      center_im = center_im - radius + 2 * radius * y / YDIM;

      if (button == 0)
         radius = radius * 0.75;
      else
         radius = radius / 0.75;

      // Initialize mandelbrot image
      init_mandelbrot();
      glutPostRedisplay();
   }
}

//---------------------------------------
// Keyboard callback for OpenGL
//---------------------------------------
void keyboard(unsigned char key, int x, int y)
{
   if ((key == 'd') && (depth > 1))
      depth--;
   else if ((key == 'D') && (depth < 10))
      depth++;

   // Redraw objects
   printf("depth = %d\n", depth);
   init_mandelbrot();
   glutPostRedisplay();
}

//---------------------------------------
// Display callback for OpenGL
//---------------------------------------
void display()
{
   glClear(GL_COLOR_BUFFER_BIT);
   glDrawPixels(XDIM, YDIM, GL_COLOR_INDEX, GL_UNSIGNED_BYTE, image);
   glFlush();
}

//---------------------------------------
// Main program
//---------------------------------------
int main(int argc, char *argv[])
{
   // Create OpenGL window
   glutInit(&argc, argv);
   glutInitWindowSize(XDIM, YDIM);
   glutInitWindowPosition(0, 0);
   glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
   glutCreateWindow("Mandelbrot");
   init();

   // Specify callback function
   glutMouseFunc(mouse);
   glutKeyboardFunc(keyboard);
   glutDisplayFunc(display);
   glutMainLoop();
   return 0;
}
