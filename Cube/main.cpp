#include <iostream>
#include <GLUT/glut.h>

GLfloat vertices [8][3] = { {-1.0,-1.0,-1.0}, {-1.0,1.0,-1.0},
    {1.0,1.0,-1.0}, {1.0,-1.0,-1.0}, {-1.0,-1.0,1.0},
    {-1.0,1.0,1.0},{1.0,1.0,1.0},{1.0,-1.0,1.0}};


GLfloat color [8][3] = {{0.0,0.0,0.0},{0.0,1.0,0.0},{1.0,1.0,0.0},
    {1.0,0.0,0.0},{0.0,0.0,1.0},{0.0,1.0,1.0},{1.0,1.0,1.0},
    {1.0,0.0,1.0}};

GLfloat theta =0,x_axes=1.0,y_axes=1.0,z_axes=1.0;




    void polygon(int  a,int b,int c,int d) {
    glBegin(GL_POLYGON);
    glColor3fv(color[a]);
    glVertex3fv(vertices[a]);
    glColor3fv(color[b]);
    glVertex3fv(vertices[b]);
    glColor3fv(color[c]);
    glVertex3fv(vertices[c]);
    glColor3fv(color[d]);
    glVertex3fv(vertices[d]);
    glEnd();
}

void cube(){
    polygon(0,3,2,1);
    polygon(2,3,7,6);
    polygon(3,0,4,7);
    polygon(1,2,6,5);
    polygon(4,5,6,7);
    polygon(5,4,0,1);
}
void test(){
    theta -=1.0;
    glutPostRedisplay();
    
}
void test1(){
    theta +=1.0;
    glutPostRedisplay();
    
}

void keyboard(unsigned char key, int x, int y)
{
   
    if (key=='a' || key == 'A'){
        
        theta=theta-3.0;
        glutIdleFunc(test);
    }
    if (key=='d' || key == 'D'){
        theta=theta+3.0;
        glutIdleFunc(test1);

    }
  
    if (key=='w' || key == 'W'){
        
         theta=theta+3.0;
        glutPostRedisplay();
        
    }
    if (key=='s')
        glutIdleFunc(NULL);
        
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glRotatef (theta,x_axes,0,0);
    glTranslatef(0, -2.0, 0.0);
    glRotatef(theta,x_axes,y_axes,z_axes);
    cube();
    
    glLoadIdentity();
    
    glRotatef (theta,x_axes,0,0);
    glTranslatef(0, 4.0, 0.0);
    glRotatef(theta,x_axes,y_axes,z_axes);
    
    cube();
    //glLoadIdentity();
    glRotatef (theta,0,y_axes,0);
    glTranslatef(3.0,0,0);
  
    cube();
        glutSwapBuffers();
    
}
void init()
{
    glEnable(GL_DEPTH_TEST);
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-5.0, 5.0, -7.0, 7.0, -7.0, 7.0);
    glMatrixMode(GL_MODELVIEW);
    
}



int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0.0, 0.0);
    glutCreateWindow("R_CUBE");
    //glutIdleFunc(test);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    init();
    glutMainLoop();
    
    
}