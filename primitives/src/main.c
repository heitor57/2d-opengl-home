#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif
#define X_SHIFT 0.301
#define SUP_HEIGHT 0.15
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

void draw_circle(GLfloat x, GLfloat y, GLfloat radius){
	int i;
	int num_triangle = 20;
	GLfloat twice_pi = 2.0f * M_PI;
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); 
		for(i = 0; i <= num_triangle;i++) { 
			glVertex2f(
		            x + (radius * cos(i *  twice_pi / num_triangle)), 
			    y + (radius * sin(i * twice_pi / num_triangle))
			);
		}
	glEnd();
}
void display(void)
{
    glMatrixMode(GL_MODELVIEW);

    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_DEPTH_BUFFER_BIT);
    glColor3f (1.0, 0.0, 0.0);
    glLineWidth(5);
    glBegin(GL_LINES);        
        glVertex3f (0.15, 0.15, 0.1);
        glVertex3f (0.25, 0.15, 0.1);
        glVertex3f (0.35, 0.15, 0.1);
        glVertex3f (0.45, 0.15, 0.1);
        glColor3f (0.0, 1.0, 0.0);
        glVertex3f (0.55, 0.15, 0.1);
        glVertex3f (0.65, 0.25, 0.1);
        glVertex3f (0.75, 0.35, 0.1);
        glVertex3f (0.85, 0.45, 0.1);
        /*glVertex3f (0.15, 0.15, 0.1);*/
    glEnd();

    glBegin(GL_QUADS);        
        glColor3f (1.0, 0.0, 0.0);
        glVertex3f (0.35, 0.35, 0.1);
        glColor3f (1.0, 1.0, 1.0);
        glVertex3f (0.65, 0.35, 0.1);
        glColor3f (0.0, 1.0, 0.0);
        glVertex3f (0.65, 0.65, 0.1);
        glColor3f (0.0, 0.0, 1.0);
        glVertex3f (0.35, 0.65, 0.1);        
    glEnd();
    glColor3f (0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);        
        glVertex3f (0.35, 0.35, 0.1);
        glColor3f (1.0, 1.0, 0.0);
        glVertex3f (0.65, 0.35, 0.1);
        glColor3f (0.0, 1.0, 0.0);
        glVertex3f (0.65, 0.65, 0.1);
        glColor3f (0.0, 1.0, 1.0);
        glVertex3f (0.35, 0.65, 0.1);        
    glEnd();
    glPointSize(10);
    glColor3f (0.3, 0.5, 0.2);
    glBegin(GL_POINTS);        
        glVertex3f (0.35, 0.35, 0.1);
        glColor3f (1.0, 1.0, 0.0);
        glVertex3f (0.65, 0.35, 0.1);
        glColor3f (0.0, 0.0, 1.0);
        glVertex3f (0.65, 0.65, 0.1);
        glColor3f (1.0, 1.0, 0.0);
        glVertex3f (0.35, 0.65, 0.1);        
    glEnd();

    glColor3f (0.8, 0.5, 0.2);
    glLineWidth(4);
    glBegin(GL_LINE_STRIP);        
        glVertex3f (0.05, 0.8, 0.1);
        glVertex3f (0.09, 0.78, 0.1);
        glVertex3f (0.11, 0.73, 0.1);
        glVertex3f (0.07, 0.61, 0.1);
        glVertex3f (0.27, 0.51, 0.1);
    glEnd();

   glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(0.35,0.65);
        glVertex2f((0.35+0.65)/2,0.65+0.15);
        glVertex2f(0.65,0.65);
    glEnd();

    glColor3d(1,1,0.6);
    draw_square(0.35, 0.65-0.1, 0.1,GL_POLYGON);

    glColor3d(1,0.4,0.6);
    draw_circle(0.1, 0.1, 0.1);

   glBegin(GL_TRIANGLE_STRIP);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(0.93,0.95);
        glVertex2f(0.83,0.85);
        glVertex2f(0.66,0.81);
        glVertex2f(0.78,0.72);
        glVertex2f(0.88,0.72);
    glEnd();
   glBegin(GL_QUAD_STRIP);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(0.88,0.1);
        glVertex2f(0.88,0.15);
        glVertex2f(0.93,0.15);
        glVertex2f(0.93,0.1);
        glVertex2f(0.93+0.05,0.1);
        glVertex2f(0.93+0.05,0.15);
    glEnd();

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
