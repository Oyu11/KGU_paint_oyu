#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
int dx = -1, dy = -1, fx = -1, fy = -1;



void mouse(int button, int state, int x, int y){
    glVertex2f(x, y);
    if(state == GLUT_DOWN){
        dx = x;
        dy = y;
     printf("%d, %d\n", x ,y);
    }
    else{
        fx = x;
        fy = y;
        glutPostRedisplay();
    }
}
void motion(int x, int y){
    fx = x;
    fy = y;
    glutPostRedisplay();
}
void display(){
    glLineWidth(1.0);
    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
        glVertex2f(dx, glutGet(GLUT_WINDOW_HEIGHT) - dy);
        glVertex2f(fx, glutGet(GLUT_WINDOW_HEIGHT) - fy);
    glEnd();
    dx = fx;
    dy = fy;
    glFlush();
}

void reshape(int width, int height){
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, width, 0, height);
    glMatrixMode(GL_MODELVIEW);
}


int main(int arg, char** argv){
    glutInit(&arg, argv);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Oyu Paint program");
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glutMainLoop();
    return 0;
}
