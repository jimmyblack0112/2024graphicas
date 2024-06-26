 #include <GL/glut.h>

 void myBody(){///我的身體
    glPushMatrix();
        glColor3f(1, 0, 0);///紅色的
        glutWireCube(0.6);///myBody()
    glPopMatrix();
 }
void myArm(){///我的身體
    glPushMatrix();
        glColor3f(0, 1, 0);///綠色的
        glScalef(1, 0.4, 0.4);///大小
        glutWireCube(0.3);///myArm()
    glPopMatrix();
 }
float angle = 0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    myBody();///我的身體

    glPushMatrix();
        glTranslatef(0.3, 0.3, 0);///(3)掛到肩上
        glRotatef(angle++, 0, 0, 1);///(2)旋轉角度
        glTranslatef(0.15, 0, 0);///(1)把旋轉中心放在左上角
        myArm();///我的手臂
    glPopMatrix();

    glutSwapBuffers();
}

int main(int argc, char*argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week10");
    glutDisplayFunc(display);
    glutIdleFunc(display);///有空就旋轉
    glutMainLoop();
}
