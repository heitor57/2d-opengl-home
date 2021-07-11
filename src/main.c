#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif
#define X_SHIFT 0.301
#define SUP_HEIGHT 0.15

void draw_circle(GLfloat x, GLfloat y, GLfloat radius){
	int i;
	int triangleAmount = 20; //# of triangles used to draw circle
	
	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * M_PI;
	
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) { 
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)), 
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
}

void draw_empty_circle(GLfloat x, GLfloat y, GLfloat radius){
	int i;
	int triangleAmount = 20; //# of triangles used to draw circle
	
	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * M_PI;
	
	glBegin(GL_LINE_LOOP);
		for(i = 0; i <= triangleAmount;i++) { 
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)), 
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
}
void draw_square(double x, double y, double length, int mode)
{
    double half_length = length / 2;
    glBegin(mode);
    glVertex2d(x + half_length, y + half_length);
    glVertex2d(x + half_length, y - half_length);
    glVertex2d(x - half_length, y - half_length);
    glVertex2d(x - half_length, y + half_length);
    glEnd();
}
void display(void)
{
    glMatrixMode(GL_MODELVIEW);

/*  clear all pixels  */
    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_DEPTH_BUFFER_BIT);
       
/*  draw white polygon (rectangle) with corners at
 *  (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)  
 */
    // front part of the house
    glColor3f (1.0, 0.0, 0.0);
    glBegin(GL_QUADS);        
        glVertex3f (0.35, 0.35, 0.1);
        glVertex3f (0.65, 0.35, 0.1);
        glVertex3f (0.65, 0.65, 0.1);
        glVertex3f (0.35, 0.65, 0.1);        
    glEnd();
    glColor3f (0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);        
        glVertex3f (0.35, 0.35, 0.1);
        glVertex3f (0.65, 0.35, 0.1);
        glVertex3f (0.65, 0.65, 0.1);
        glVertex3f (0.35, 0.65, 0.1);        
    glEnd();
    // door of the house
#define X_DOOR_SIZE 0.1
#define Y_DOOR_SIZE 0.25
    glColor3f (0.6, 0.6, 0.6);
/*glColor4f(1.0f, 0.5f, 0.0f, 0.0f);*/
    /*glColor3f(0.1f, 0.0f, 0.0f);//Brown*/
    glBegin(GL_QUADS);        
        float x_center_front_part = (0.35+0.65)/2;
        /*int y_center_front_part = (0.35+0.65)/2;*/
        glVertex3f (x_center_front_part-X_DOOR_SIZE/2, 0.35, 0.1);
        glVertex3f (x_center_front_part-X_DOOR_SIZE/2, 0.35+Y_DOOR_SIZE/2, 0.1);
        glVertex3f (x_center_front_part+X_DOOR_SIZE/2, 0.35+Y_DOOR_SIZE/2, 0.1);
        glVertex3f (x_center_front_part+X_DOOR_SIZE/2, 0.35, 0.1);        
    glEnd();

    glColor3f (0.0, 0.0, 0);
    glBegin(GL_LINE_LOOP);        
        /*int y_center_front_part = (0.35+0.65)/2;*/
        glVertex3f (x_center_front_part-X_DOOR_SIZE/2, 0.35, 0.1);
        glVertex3f (x_center_front_part-X_DOOR_SIZE/2, 0.35+Y_DOOR_SIZE/2, 0.1);
        glVertex3f (x_center_front_part+X_DOOR_SIZE/2, 0.35+Y_DOOR_SIZE/2, 0.1);
        glVertex3f (x_center_front_part+X_DOOR_SIZE/2, 0.35, 0.1);        

        glEnd();
    // back part of the house
    glColor3f (0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);        
        glVertex3f (0.35+X_SHIFT, 0.35, 0.1);
        glVertex3f (0.65+X_SHIFT, 0.35, 0.1);
        glVertex3f (0.65+X_SHIFT, 0.65, 0.1);
        glVertex3f (0.35+X_SHIFT, 0.65, 0.1);        
    glEnd();

    /*glColor3f (0.0, 0.0, 1.0);*/
    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);        
        glVertex3f (0.35+X_SHIFT, 0.35, 0.1);
        glVertex3f (0.65+X_SHIFT, 0.35, 0.1);
        glVertex3f (0.65+X_SHIFT, 0.65, 0.1);
        glVertex3f (0.35+X_SHIFT, 0.65, 0.1);        
    glEnd();
    // back part windows
    
    float window_size = 0.08;
    float window_1_x_position_shift=0.1;
    float window_2_x_position_shift=0.22;
    glColor3d(1,1,1);
    draw_square(0.35+X_SHIFT+window_1_x_position_shift, 0.65-0.1, window_size,GL_POLYGON);
    glColor3d(0,0,0);
    draw_square(0.35+X_SHIFT+window_1_x_position_shift, 0.65-0.1, window_size,GL_LINE_LOOP);

    glColor3d(1,1,1);
    draw_square(0.35+X_SHIFT+window_2_x_position_shift, 0.65-0.1, window_size,GL_POLYGON);
    glColor3d(0,0,0);
    draw_square(0.35+X_SHIFT+window_2_x_position_shift, 0.65-0.1, window_size,GL_LINE_LOOP);


    // front top part of the house
   glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(0.35,0.65);
        glVertex2f((0.35+0.65)/2,0.65+0.15);
        glVertex2f(0.65,0.65);
    glEnd();
    glBegin(GL_LINE_LOOP);        
        glColor3f (0.0, 0.0, 0.0);
        glVertex2f(0.35,0.65);
        glVertex2f((0.35+0.65)/2,0.65+SUP_HEIGHT);
        glVertex2f(0.65,0.65);
    glEnd();
    float top_front_distance_from_center = 0.65-(0.35+0.65)/2;
    // front top part window
    float front_top_window_x_center= (0.35+0.65)/2;
    float front_top_window_y_center= (0.65+SUP_HEIGHT+0.65)/2;
    glColor3f (1.0, 1.0, 1.0);
    draw_circle(front_top_window_x_center, front_top_window_y_center-0.01, 0.04);
    glColor3f (0.0, 0.0, 0.0);
    draw_empty_circle(front_top_window_x_center, front_top_window_y_center-0.01, 0.04);


    // back top part of the house
    glBegin(GL_QUADS);        
        glColor3f (0.0, 1.0, 0.0);
        /*glVertex2f(0.35,0.65);*/
        glVertex2f((0.35+0.65)/2,0.65+SUP_HEIGHT);
        glVertex2f(0.65,0.65);
        glVertex2f(0.65+X_SHIFT,0.65);
        glVertex2f(0.65+X_SHIFT-top_front_distance_from_center,0.65+SUP_HEIGHT);
    glEnd();

    glBegin(GL_LINE_LOOP);        
        glColor3f (0.0, 0.0, 0.0);
        /*glVertex2f(0.35,0.65);*/
        glVertex2f((0.35+0.65)/2,0.65+SUP_HEIGHT);
        glVertex2f(0.65,0.65);
        glVertex2f(0.65+X_SHIFT,0.65);
        glVertex2f(0.65+X_SHIFT-top_front_distance_from_center,0.65+SUP_HEIGHT);
    glEnd();

/*  don't wait!  
 *  start processing buffered OpenGL routines 
 */
    glFlush ();
}

void init (void) 
{
/*  select clearing (background) color       */
    /*glClearColor (0.2, 0.6, 0.0, 1.0);*/
    glClearColor (0.5, 0.5, 0.5, 1.0);

/*  initialize viewing values  */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
    
}

void manage_keyboard(unsigned char key, int x, int y)
{
    switch (key) {
            case 27: 
                exit (0);
                break;

    }
    glutPostRedisplay();
}

/* 
 *  Declare initial window size, position, and display mode
 *  (single buffer and RGBA).  Open window with "hello"
 *  in its title bar.  Call initialization routines.
 *  Register callback function to display graphics.
 *  Enter main loop and process events.
 */
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (350, 350); 
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("2D Home");
    init();
    glutDisplayFunc(display); 
    glutKeyboardFunc(manage_keyboard);
    glutMainLoop();
    return 0;   /* ISO C requires main to return int. */
}
